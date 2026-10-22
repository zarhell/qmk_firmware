#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "keycodes/keycodes.h"
#include "mousekey.h"

// Detector de doble toque: toque corto, soltar y volver a presionar dentro de DBL_TAP_MS
typedef struct {
    uint16_t press;
    uint16_t last_tap;
    bool     dbl;
} dtap_t;

static bool dtap_press(dtap_t *d, uint16_t t) {
    d->dbl      = d->last_tap && (uint16_t)(t - d->last_tap) < DBL_TAP_MS;
    d->press    = t;
    d->last_tap = 0;
    return d->dbl;
}

static void dtap_release(dtap_t *d, uint16_t t) {
    if (!d->dbl && (uint16_t)(t - d->press) < DBL_TAP_MS) d->last_tap = t ? t : 1;
}

static dtap_t gui_dt, mo1l_dt, mo1r_dt, mv_dt[8];
static bool   mo1l_unlocked = false, mo1r_unlocked = false;
static bool   esc_consumed  = false;
// Shift izquierdo: toque limpio (sin otra tecla en medio) = Alt one-shot; el Shift real siempre llega al host
static bool     lsft_dirty = false;
static uint16_t lsft_t;

// Otra tecla pulsada durante un doble toque: deja de ser un toque rapido (no se convierte en one-shot)
static bool dbl_dirty = false;

static bool dbl_quick(dtap_t *d, uint16_t t) {
    return !dbl_dirty && (uint16_t)(t - d->press) < TAPPING_TERM;
}

// MO(1) compatible con Layer Lock. Un toque rapido sin otra tecla deja el one-shot osm_mod (si no es 0);
// mantenido = capa 1; doble toque mantenido = dbl_layer (el segundo toque cancela el one-shot)
static void mo1_dbl(dtap_t *d, bool *unlocked, keyrecord_t *record, int8_t dbl_layer, uint8_t osm_mod) {
    if (record->event.pressed) {
        if (dtap_press(d, record->event.time)) {
            if (osm_mod) del_oneshot_mods(MOD_BIT(osm_mod));
            if (dbl_layer >= 0) layer_on(dbl_layer);
        } else if (is_layer_locked(1)) {
            layer_lock_invert(1);
            *unlocked = true;
        } else {
            dbl_dirty = false;
            layer_on(1);
        }
    } else {
        if (d->dbl) {
            if (dbl_layer >= 0 && !is_layer_locked(dbl_layer)) layer_off(dbl_layer);
        } else if (*unlocked) {
            *unlocked = false;
        } else if (!is_layer_locked(1)) {
            layer_off(1);
            if (osm_mod && dbl_quick(d, record->event.time)) add_oneshot_mods(MOD_BIT(osm_mod));
        }
        dtap_release(d, record->event.time);
    }
}

// Mouse virtual: un toque mantenido = lento (ACL0), doble toque mantenido = rapido (ACL2)
#define MV_DIR_U 0x1
#define MV_DIR_D 0x2
#define MV_DIR_L 0x4
#define MV_DIR_R 0x8

static const uint8_t PROGMEM mv_dirs[8] = {
    MV_DIR_U | MV_DIR_L, MV_DIR_U, MV_DIR_U | MV_DIR_R, MV_DIR_L,
    MV_DIR_R, MV_DIR_D | MV_DIR_L, MV_DIR_D, MV_DIR_D | MV_DIR_R,
};

static void mouse_virtual(uint16_t keycode, keyrecord_t *record) {
    uint8_t i    = keycode - MV_NW;
    uint8_t dirs = pgm_read_byte(&mv_dirs[i]);
    bool    down = record->event.pressed;
    bool    fast;

    if (down) {
        fast         = dtap_press(&mv_dt[i], record->event.time);
        mk_max_speed = fast ? MV_FAST_MAX : MV_SLOW_MAX;
    } else {
        fast = mv_dt[i].dbl;
        dtap_release(&mv_dt[i], record->event.time);
    }

    uint8_t accel = fast ? MS_ACL2 : MS_ACL0;
    if (down) {
        mousekey_on(accel);
        if (dirs & MV_DIR_U) mousekey_on(MS_UP);
        if (dirs & MV_DIR_D) mousekey_on(MS_DOWN);
        if (dirs & MV_DIR_L) mousekey_on(MS_LEFT);
        if (dirs & MV_DIR_R) mousekey_on(MS_RGHT);
    } else {
        if (dirs & MV_DIR_U) mousekey_off(MS_UP);
        if (dirs & MV_DIR_D) mousekey_off(MS_DOWN);
        if (dirs & MV_DIR_L) mousekey_off(MS_LEFT);
        if (dirs & MV_DIR_R) mousekey_off(MS_RGHT);
        mousekey_off(accel);
    }
    mousekey_send();
}

// WIN_SWAP: Super+Tab (workspace siguiente; con Shift izq. fisico, anterior). Super queda
// presionado hasta salir de la capa 1 o pulsar otra tecla
static bool swap_active = false;

void win_swap_cancel(void) {
    if (swap_active) {
        unregister_code(KC_LGUI);
        swap_active = false;
    }
}

static uint8_t mod_state;

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode != GUI_CTL && keycode != MO1_ALT) dbl_dirty = true;
        if (keycode != KC_LSFT) lsft_dirty = true;
        if (keycode != WIN_SWAP && keycode != KC_LSFT) win_swap_cancel();
    }

    if (!process_layer_lock(keycode, record, LLOCK)) return false;

    if (keycode >= MV_NW && keycode <= MV_SE) {
        mouse_virtual(keycode, record);
        return false;
    }

    mod_state = get_mods();
    switch (keycode) {

        case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }

        case GUI_CTL:
            if (record->event.pressed) {
                if (dtap_press(&gui_dt, record->event.time)) {
                    dbl_dirty = false;
                    register_code(KC_LCTL);
                } else {
                    register_code(KC_LGUI);
                }
            } else {
                if (gui_dt.dbl) {
                    unregister_code(KC_LCTL);
                    if (dbl_quick(&gui_dt, record->event.time)) add_oneshot_mods(MOD_BIT(KC_LCTL));
                } else {
                    unregister_code(KC_LGUI);
                }
                dtap_release(&gui_dt, record->event.time);
            }
            return false;

        case KC_LSFT:
            if (record->event.pressed) {
                // Shift Shift (IntelliJ): si hay Alt armado por el toque anterior, se cancela
                if (get_oneshot_mods() & MOD_BIT(KC_LALT)) del_oneshot_mods(MOD_BIT(KC_LALT));
                lsft_dirty = false;
                lsft_t     = record->event.time;
            } else if (!lsft_dirty && (uint16_t)(record->event.time - lsft_t) < TAPPING_TERM) {
                add_oneshot_mods(MOD_BIT(KC_LALT));
            }
            return true;

        case KC_ESC:
            // Con un Layer Lock activo, Esc desbloquea todo y vuelve a la capa 0
            if (record->event.pressed) {
                if (layer_lock_is_any()) {
                    layer_lock_all_off();
                    esc_consumed = true;
                    return false;
                }
            } else if (esc_consumed) {
                esc_consumed = false;
                return false;
            }
            return true;

        case MO1_ALT:
            mo1_dbl(&mo1l_dt, &mo1l_unlocked, record, 3, KC_RALT);
            return false;

        case MO1_MS:
            mo1_dbl(&mo1r_dt, &mo1r_unlocked, record, -1, 0);
            return false;

        case WIN_SWAP:
            if (record->event.pressed) {
                if (!swap_active) {
                    swap_active = true;
                    register_code(KC_LGUI);
                }
                tap_code(KC_TAB);
            }
            return false;
    }

    return true;
}
