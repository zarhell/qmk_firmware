#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "utils/keylog.h"
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

// MO(1) compatible con Layer Lock; el doble toque mantenido activa dbl_layer (capa) o dbl_mod (modificador)
static void mo1_dbl(dtap_t *d, bool *unlocked, keyrecord_t *record, int8_t dbl_layer, uint8_t dbl_mod) {
    if (record->event.pressed) {
        if (dtap_press(d, record->event.time)) {
            if (dbl_layer >= 0) layer_on(dbl_layer);
            if (dbl_mod) register_code(dbl_mod);
        } else if (is_layer_locked(1)) {
            layer_lock_invert(1);
            *unlocked = true;
        } else {
            layer_on(1);
        }
    } else {
        if (d->dbl) {
            if (dbl_layer >= 0) layer_off(dbl_layer);
            if (dbl_mod) unregister_code(dbl_mod);
        } else if (*unlocked) {
            *unlocked = false;
        } else if (!is_layer_locked(1)) {
            layer_off(1);
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

static bool alt_tab_active = false;

void win_swap_cancel(void) {
    if (alt_tab_active) {
        unregister_code(KC_LALT);
        alt_tab_active = false;
    }
}

static uint8_t mod_state;

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
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
                register_code(dtap_press(&gui_dt, record->event.time) ? KC_LCTL : KC_LGUI);
            } else {
                unregister_code(gui_dt.dbl ? KC_LCTL : KC_LGUI);
                dtap_release(&gui_dt, record->event.time);
            }
            return false;

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
            mo1_dbl(&mo1l_dt, &mo1l_unlocked, record, -1, KC_LALT);
            return false;

        case MO1_MS:
            mo1_dbl(&mo1r_dt, &mo1r_unlocked, record, 3, 0);
            return false;

        case WIN_SWAP:
            if (record->event.pressed) {
                if (!alt_tab_active) {
                    alt_tab_active = true;
                    register_code(KC_LALT);
                }
                tap_code(KC_TAB);
            }
            return false;
    }

    return true;
}
