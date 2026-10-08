#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "utils/keylog.h"
#include "keycodes/keycodes.h"

static void send_accent_mac(uint8_t dead_kc, uint8_t base_kc, bool upper) {
    register_code(KC_LALT);
    tap_code(dead_kc);
    unregister_code(KC_LALT);
    if (upper) { register_code(KC_LSFT); }
    tap_code(base_kc);
    if (upper) { unregister_code(KC_LSFT); }
}

static void send_accent(uint16_t lo, uint16_t hi, uint8_t mac_dead, uint8_t mac_base) {
    uint8_t saved_mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    bool upper = (saved_mods & MOD_MASK_SHIFT);
    if (is_mac) {
        send_accent_mac(mac_dead, mac_base, upper);
    } else {
        register_unicode(upper ? hi : lo);
    }
    set_mods(saved_mods);
}

bool is_mac = false;

static bool alt_tab_active = false;

void win_swap_cancel(void) {
    if (alt_tab_active) {
        unregister_code(is_mac ? KC_LGUI : KC_LALT);
        alt_tab_active = false;
    }
}

static uint8_t mod_state;

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    if (!process_layer_lock(keycode, record, LLOCK)) return false;

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

        case TILDE_A:
            if (record->event.pressed) send_accent(0xE1, 0xC1, KC_E, KC_A);
            return false;
        case TILDE_E:
            if (record->event.pressed) send_accent(0xE9, 0xC9, KC_E, KC_E);
            return false;
        case TILDE_I:
            if (record->event.pressed) send_accent(0xED, 0xCD, KC_E, KC_I);
            return false;
        case TILDE_O:
            if (record->event.pressed) send_accent(0xF3, 0xD3, KC_E, KC_O);
            return false;
        case TILDE_U:
            if (record->event.pressed) send_accent(0xFA, 0xDA, KC_E, KC_U);
            return false;
        case ENIE:
            if (record->event.pressed) send_accent(0xF1, 0xD1, KC_N, KC_N);
            return false;

        case TOG_OS:
            if (record->event.pressed) {
                is_mac = !is_mac;
                set_unicode_input_mode(is_mac ? UNICODE_MODE_MACOS : UNICODE_MODE_LINUX);
            }
            return false;

        case KC_PSCR:
            if (record->event.pressed && is_mac) {
                register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI));
                tap_code(KC_4);
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI));
                return false;
            }
            return true;

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
        case GUI_SFT:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            } else {
                unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            }
            return false;

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
