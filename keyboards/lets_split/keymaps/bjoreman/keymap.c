#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define ___ KC_TRNS
#define C_S LCTL_T(KC_S)
#define A_D LALT_T(KC_D)
#define G_F LGUI_T(KC_F)
#define C_J RCTL_T(KC_J)
#define A_K RALT_T(KC_K)
#define G_L RGUI_T(KC_L)
#define UNDO LGUI(KC_Z)
#define REDO SGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

enum layers {
    _QWERTY = 0,
    _LOWER,
    _NUMPAD,
    _CURSOR,
    _MORE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(_NUMPAD, KC_TAB),  KC_A,    C_S,    A_D,    G_F,    KC_G,     KC_H,   C_J,    A_K,    G_L,    SE_ACUT,   SE_APOS,
    LSFT_T(SE_PLUS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,   RSFT_T(KC_ENTER),
    KC_HYPR, ___, ___,  ___, MO(_LOWER), KC_SPACE, MO(_CURSOR),  MO(_MORE), ___, ___, ___, ___
  ),

 [_LOWER] = LAYOUT_ortho_4x12(
    SE_LESS,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),  LSFT(KC_6),  LSFT(KC_7),  LSFT(KC_8),  LSFT(KC_9),  LSFT(KC_0),  ___,
    SE_GRTR,  SE_PIPE_MAC,  SE_LCBR_MAC,  SE_RCBR_MAC, LALT(KC_2), SE_QUES,  SE_GRV_MAC, SE_AA, SE_AE, SE_OSLH, LALT(SE_DIAE), ___,
    ___,   ___,  ___,  ___,   ___,  ___, ___,   ___,  ___,   ___,   ___,    ___,
    ___,   ___,  ___,  ___,   ___,  ___,  ___,   ___,  ___,   ___,   ___, ___
  ),

  [_NUMPAD] = LAYOUT_ortho_4x12(
    RESET, ___, ___, ___, ___, ___, ___, KC_7, KC_8, KC_9, ___, ___,
    ___, ___, ___, ___, ___, ___, LSFT(KC_7), KC_4, KC_5, KC_6, SE_PLUS, ___,
    ___, ___, ___, ___, ___, ___, LSFT(SE_APOS), KC_1, KC_2, KC_3, LSFT(KC_DOT), ___,
    ___, ___, ___, ___, ___, ___, ___, KC_0, KC_SLSH, KC_COMM, KC_DOT, ___
  ),

  [_CURSOR] = LAYOUT_ortho_4x12(
    KC_ESC, ___, ___, ___, ___, ___, ___, KC_HOME, KC_UP, KC_END, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, KC_LEFT, KC_DOWN, KC_RIGHT, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
  ),

  [_MORE] = LAYOUT_ortho_4x12(
    KC_ESC, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, SE_LESS_MAC, SE_GRTR_MAC, LALT(KC_4), ___, ___, SE_LBRC, SE_RBRC, SE_BSLS_MAC, LSFT(SE_DIAE), ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
  ),
/* Always good to have a nice clean layer template …
  [3] = LAYOUT_ortho_4x12(
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
  ),
  */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LALT_T(KC_D):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LGUI_T(KC_F):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_J):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_K):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}