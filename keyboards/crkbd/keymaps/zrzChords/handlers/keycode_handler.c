#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "features/select_word.h"
#include "utils/keylog.h"
#include "keycodes/keycodes.h"
#include "user_config.h"

// ---------------------------------------------------------------------------
// Lightweight Alt+numpad unicode sender (Windows, no UNICODE_ENABLE needed).
// Sends Alt + 0 + three decimal digits → ANSI/Unicode codepoint.
// Requires NumLock ON. Works for codepoints 0x0020–0x00FF (Latin-1 range).
// ---------------------------------------------------------------------------
static inline uint8_t numpad_kc(uint8_t d) {
    // KC_P1..KC_P9 are consecutive; KC_P0 is separate
    return d == 0 ? KC_P0 : KC_P1 + (d - 1);
}

static void send_win_unicode(uint16_t cp) {
    register_code(KC_LALT);
    tap_code(KC_P0);                              // leading 0 → ANSI mode
    tap_code(numpad_kc((cp / 100) % 10));
    tap_code(numpad_kc((cp / 10)  % 10));
    tap_code(numpad_kc( cp        % 10));
    unregister_code(KC_LALT);
}

// ---------------------------------------------------------------------------
// Spanish double-tap: press the same key twice quickly → accented character.
//   A+A → á,  E+E → é,  N+N → ñ,  1+1 → ¡,  /+/ → ¿
// Shift held on the second tap produces the uppercase variant (Á, É, Ñ …).
// ---------------------------------------------------------------------------
// DOUBLE_TAP_TERM can be overridden in config.h
#ifndef DOUBLE_TAP_TERM
#define DOUBLE_TAP_TERM 200
#endif

static uint16_t dt_last_keycode = KC_NO;
static uint16_t dt_last_time    = 0;

static bool is_spanish_key(uint16_t keycode) {
    switch (keycode) {
        case KC_A: case KC_E: case KC_I:
        case KC_O: case KC_U: case KC_N:
        case KC_1: case KC_SLSH:
            return true;
        default:
            return false;
    }
}

static bool handle_spanish_double_tap(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    // Any non-Spanish key in between resets the sequence (fixes "palabra" → "paábra")
    if (!is_spanish_key(keycode)) {
        dt_last_keycode = KC_NO;
        return true;
    }

    if (keycode == dt_last_keycode && timer_elapsed(dt_last_time) < DOUBLE_TAP_TERM) {
        dt_last_keycode = KC_NO;

        uint16_t lo = 0, hi = 0;
        switch (keycode) {
            case KC_A:    lo = 0xE1; hi = 0xC1; break; // á / Á
            case KC_E:    lo = 0xE9; hi = 0xC9; break; // é / É
            case KC_I:    lo = 0xED; hi = 0xCD; break; // í / Í
            case KC_O:    lo = 0xF3; hi = 0xD3; break; // ó / Ó
            case KC_U:    lo = 0xFA; hi = 0xDA; break; // ú / Ú
            case KC_N:    lo = 0xF1; hi = 0xD1; break; // ñ / Ñ
            case KC_1:    lo = 0xA1; hi = 0xA1; break; // ¡
            case KC_SLSH: lo = 0xBF; hi = 0xBF; break; // ¿
            default:      return true;
        }

        uint8_t saved_mods = get_mods();
        del_mods(MOD_MASK_SHIFT);
        tap_code(KC_BSPC);
        send_win_unicode((saved_mods & MOD_MASK_SHIFT) ? hi : lo);
        set_mods(saved_mods);
        return false;
    }

    dt_last_keycode = keycode;
    dt_last_time    = timer_read();
    return true;
}

// ---------------------------------------------------------------------------
// Bracket double-tap: press the opening bracket combo twice quickly →
// second tap sends the matching closing bracket.
//   [[ → ]   {{ → }   (( → )
// Any other keypress between the two taps resets the sequence.
// ---------------------------------------------------------------------------
static uint16_t br_last_keycode = KC_NO;
static uint16_t br_last_time    = 0;

static bool handle_bracket_double_tap(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case KC_LBRC:
        case KC_LCBR:
        case KC_LPRN:
            if (keycode == br_last_keycode && timer_elapsed(br_last_time) < DOUBLE_TAP_TERM) {
                br_last_keycode = KC_NO;
                uint16_t closing;
                switch (keycode) {
                    case KC_LBRC: closing = KC_RBRC; break;
                    case KC_LCBR: closing = KC_RCBR; break;
                    default:      closing = KC_RPRN; break;
                }
                tap_code16(closing);
                return false;
            }
            br_last_keycode = keycode;
            br_last_time    = timer_read();
            return true;
        default:
            br_last_keycode = KC_NO;
            return true;
    }
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

    if (!handle_spanish_double_tap(keycode, record)) return false;
    if (!handle_bracket_double_tap(keycode, record)) return false;

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
        case SIGNATURE:
            if (record->event.pressed) send_string(USER_SIGNATURE);
            return false;
    }

    return true;
}
