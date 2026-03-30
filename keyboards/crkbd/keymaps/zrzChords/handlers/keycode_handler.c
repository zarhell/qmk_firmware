#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "features/select_word.h"
#include "utils/keylog.h"
#include "keycodes/keycodes.h"
#include "user_config.h"

// ---------------------------------------------------------------------------
// Lightweight Alt+numpad unicode sender (Windows, no UNICODE_ENABLE needed).
// Usa KC_RALT en lugar de KC_LALT para evitar que VSCode active su menú
// al interceptar el Alt izquierdo durante la secuencia de numpad.
// Requiere NumLock ON. Funciona para codepoints 0x0020–0x00FF (Latin-1).
// ---------------------------------------------------------------------------
static inline uint8_t numpad_kc(uint8_t d) {
    return d == 0 ? KC_P0 : KC_P1 + (d - 1);
}

static void send_win_unicode(uint16_t cp) {
    register_code(KC_RALT);            // Right Alt: no activa menú en VSCode
    tap_code(KC_P0);                   // leading 0 → modo ANSI
    tap_code(numpad_kc((cp / 100) % 10));
    tap_code(numpad_kc((cp / 10)  % 10));
    tap_code(numpad_kc( cp        % 10));
    unregister_code(KC_RALT);
}

// ---------------------------------------------------------------------------
// Acento macOS: Option + dead_kc activa muerta, luego envía base_kc.
//   Ejemplos: Opt+e → ´ muerta; luego 'a' → á.
//             Opt+n → ~ muerta; luego 'n' → ñ.
// ---------------------------------------------------------------------------
static void send_accent_mac(uint8_t dead_kc, uint8_t base_kc, bool upper) {
    register_code(KC_LALT);
    tap_code(dead_kc);
    unregister_code(KC_LALT);
    if (upper) { register_code(KC_LSFT); }
    tap_code(base_kc);
    if (upper) { unregister_code(KC_LSFT); }
}

// ---------------------------------------------------------------------------
// Envía acento con soporte uppercase y detección de OS.
//   lo/hi   → codepoints Latin-1 para Windows (Alt+numpad)
//   mac_dead → tecla de la secuencia Option+dead en macOS
//   mac_base → vocal/consonante a enviar después del dead key
// ---------------------------------------------------------------------------
static void send_accent(uint16_t lo, uint16_t hi, uint8_t mac_dead, uint8_t mac_base) {
    uint8_t saved_mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    bool upper = (saved_mods & MOD_MASK_SHIFT);
    if (is_mac) {
        send_accent_mac(mac_dead, mac_base, upper);
    } else {
        send_win_unicode(upper ? hi : lo);
    }
    set_mods(saved_mods);
}

// ---------------------------------------------------------------------------
// OS mode (false = Windows, true = macOS). Toggle con TOG_OS.
// ---------------------------------------------------------------------------
bool is_mac = false;

// Estado para WIN_SWAP sticky: true mientras el modificador Alt/Cmd esté activo.
static bool alt_tab_active = false;

// Libera el modificador de WIN_SWAP si estaba activo (llamar al salir del layer).
void win_swap_cancel(void) {
    if (alt_tab_active) {
        unregister_code(is_mac ? KC_LGUI : KC_LALT);
        alt_tab_active = false;
    }
}

static inline uint16_t os_ctrl(uint16_t kc) {
    return is_mac ? LGUI(kc) : LCTL(kc);
}

// ---------------------------------------------------------------------------
// Main keycode handler
// ---------------------------------------------------------------------------

static uint8_t mod_state;

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    if (!process_layer_lock(keycode, record, LLOCK)) return false;
    if (!process_select_word(keycode, record, SELWORD)) return false;

    mod_state = get_mods();
    switch (keycode) {

        // Shift+Backspace → Delete
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

        // -------------------------------------------------------------------
        // Acentos españoles — trigger: BSPC + vocal/N
        // Windows: Alt(R)+numpad    → no interfiere con VSCode
        // macOS:   Option+dead_key + vocal (requiere US keyboard layout)
        // -------------------------------------------------------------------
        // mac_dead=KC_E → Opt+e = dead_acute; mac_dead=KC_N → Opt+n = dead_tilde
        case TILDE_A:
            if (record->event.pressed) send_accent(0xE1, 0xC1, KC_E, KC_A);  // á / Á
            return false;
        case TILDE_E:
            if (record->event.pressed) send_accent(0xE9, 0xC9, KC_E, KC_E);  // é / É
            return false;
        case TILDE_I:
            if (record->event.pressed) send_accent(0xED, 0xCD, KC_E, KC_I);  // í / Í
            return false;
        case TILDE_O:
            if (record->event.pressed) send_accent(0xF3, 0xD3, KC_E, KC_O);  // ó / Ó
            return false;
        case TILDE_U:
            if (record->event.pressed) send_accent(0xFA, 0xDA, KC_E, KC_U);  // ú / Ú
            return false;
        case ENIE:
            if (record->event.pressed) send_accent(0xF1, 0xD1, KC_N, KC_N);  // ñ / Ñ
            return false;

        // --- Acento agudo suelto ´ ---
        // Win: Alt(R)+0180  /  Mac: Opt+e → dead_acute → Space
        case ACUTE_ACC:
            if (record->event.pressed) {
                if (is_mac) {
                    register_code(KC_LALT);
                    tap_code(KC_E);
                    unregister_code(KC_LALT);
                    tap_code(KC_SPC);
                } else {
                    send_win_unicode(0xB4);
                }
            }
            return false;

        // Misc string combos
        case EMAIL_GMAIL:
            if (record->event.pressed) send_string(USER_EMAIL_GMAIL);
            return false;
        case EMAIL_WORK:
            if (record->event.pressed) send_string(USER_EMAIL_WORK);
            return false;
        case USERNAME:
            if (record->event.pressed) send_string(USER_USERNAME);
            return false;
        case PASSWORD:
            if (record->event.pressed) send_string(USER_PASSWORD);
            return false;

        // --- OS Toggle ---
        case TOG_OS:
            if (record->event.pressed) is_mac = !is_mac;
            return false;

        // --- Screenshot OS-aware (intercepta KC_PSCR) ---
        case KC_PSCR:
            if (record->event.pressed && is_mac) {
                register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI));
                tap_code(KC_4);
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI));
                return false;
            }
            return true;

        // --- Dev shortcuts OS-aware ---
        case DEV_COMMENT:
            if (record->event.pressed) tap_code16(os_ctrl(KC_SLSH));
            return false;
        case DEV_HOME:
            if (record->event.pressed) {
                tap_code16(is_mac ? LGUI(KC_LEFT) : KC_HOME);
            }
            return false;
        case DEV_END:
            if (record->event.pressed) {
                tap_code16(is_mac ? LGUI(KC_RIGHT) : KC_END);
            }
            return false;
        case DEV_WORD_LEFT:
            if (record->event.pressed) {
                tap_code16(is_mac ? LOPT(KC_LEFT) : LCTL(KC_LEFT));
            }
            return false;
        case DEV_WORD_RIGHT:
            if (record->event.pressed) {
                tap_code16(is_mac ? LOPT(KC_RIGHT) : LCTL(KC_RIGHT));
            }
            return false;
        case APP_MENU:
            if (record->event.pressed) {
                tap_code16(is_mac ? LSFT(KC_F10) : KC_APP);
            }
            return false;

        // --- Navegación entre ventanas (Win: Alt+Tab / Mac: Cmd+Tab) ---
        // 1er toque: registra modificador + envía Tab → abre el switcher y lo mantiene visible.
        // Toques siguientes: envía Tab para mover el selector (modificador sigue activo).
        // El modificador se libera al salir del layer (layer_state_set_user en keymap.c).
        case WIN_SWAP:
            if (record->event.pressed) {
                if (!alt_tab_active) {
                    alt_tab_active = true;
                    register_code(is_mac ? KC_LGUI : KC_LALT);
                }
                tap_code(KC_TAB);
            }
            return false;
    }

    return true;
}
