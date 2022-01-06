/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_swedish_pro_osx_iso.h"

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
#define FLYCUT SGUI(KC_V)

#define ___off___ {0,0,0}
#define MG__WHITE {255,255,255}
#define MG____RED {255,0,0}
#define MG__GREEN {32,159,33}
#define MG___BLUE {0,181,213}
#define MG_YELLOW {255,208,0}
#define MG_ORANGE {255,85,0}
#define MG___PINK {208,0,255}
#define MG_PURPLE {50,0,232}

enum my_keycodes {
  RGB_SET_SOLID = SAFE_RANGE,
  RGB_SET_WHITE,
  RGB_SET_PURPLE,
};

enum layers {
    _QWERTY = 0,
    _LOWER,
    _NUMPAD,
    _CURSOR,
    _EDIT,
    //_GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD, KC_ESC),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TAB),    KC_A,     C_S,     A_D,     G_F,    KC_G,                         KC_H,     C_J,     A_K,     G_L, SE_ACUT, RSFT_T(KC_ENTER),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            SE_PLUS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SE_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_HYPR,MO(_LOWER),  KC_SPC,MO(_CURSOR),MO(_EDIT), _______
                                            //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SE_SECT, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4),    LSFT(KC_5),                         LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT(SE_SECT), SE_PIPE, LALT(KC_2), SE_LCBR, SE_RCBR, SE_QUES,                      SE_GRV, SE_ARNG,   SE_ADIA,SE_ODIA, LALT(SE_DIAE), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_SLSH,    KC_7,    KC_8,    KC_9, SE_PLUS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   LSFT(KC_7),    KC_4,    KC_5,    KC_6, LSFT(KC_DOT),  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RESET, _______, _______, _______, _______, _______,                LSFT(SE_QUOT),    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_CURSOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_BSLS, LSFT(SE_DIAE), SE_LBRC, SE_RBRC, _______,                _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, SE_LABK, SE_RABK, LALT(KC_4),                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______,    UNDO,    REDO, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,     CUT,    COPY,   PASTE, _______,                      _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, _______, _______,  FLYCUT, _______,                      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SAD, RGB_VAD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

  /*[_GAME] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, SE_ACUT, RSFT_T(KC_ENTER),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            SE_PLUS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SE_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LCTL, KC_LALT, LGUI_T(KC_SPC),    KC_RGUI, KC_RALT, _______
                                            //`--------------------------'  `--------------------------'

  )*/
};

const uint8_t PROGMEM ledmap[][42][3] = {
[_NUMPAD] = {
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,         ___off___, MG___BLUE, MG___BLUE, MG___BLUE, MG__GREEN, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,         MG__GREEN, MG___BLUE, MG___BLUE, MG___BLUE, MG__GREEN, ___off___,
MG____RED, ___off___, ___off___, ___off___, ___off___, ___off___,         MG__GREEN, MG___BLUE, MG___BLUE, MG___BLUE, MG__GREEN, ___off___,
                 ___off___, ___off___, ___off___,         MG__GREEN, MG___BLUE, MG__GREEN
      },
[_CURSOR] = {
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,         ___off___, ___off___, MG___BLUE, ___off___, ___off___, ___off___,
___off___, MG__GREEN, MG__GREEN, MG__GREEN, MG__GREEN, ___off___,         ___off___, MG___BLUE, MG___BLUE, MG___BLUE, ___off___, ___off___,
___off___, ___off___, ___off___, MG__GREEN, MG__GREEN, MG__GREEN,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                   ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      },
[_EDIT] = {
___off___, ___off___, ___off___, MG_PURPLE, MG_YELLOW, ___off___,         ___off___, ___off___, MG___BLUE, ___off___, ___off___, ___off___,
___off___, ___off___, MG____RED, MG_ORANGE, MG__GREEN, ___off___,         ___off___, MG___BLUE, MG___BLUE, MG___BLUE, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, MG__WHITE, ___off___,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                   ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      },
/*[_GAME] = {
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
                   MG__WHITE, MG__WHITE, MG___BLUE,         MG___BLUE, MG__WHITE, MG__WHITE
      },*/
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // (180, 255, 231) is purple
    rgb_matrix_mode_noeeprom(1);
}

// ====================================================
// RGB matrix
// ====================================================

uint8_t ledIndexForKeymapIndex(uint8_t keyIndex) {
  // Turn keyIndex into a row and column within g_led_config.
  // Reference: https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/r2g/r2g.c
  uint8_t row = 0;
  uint8_t col = 0;
  uint8_t keysPerRow = 12; // Specific to crkdb!
  uint8_t keysPerHalf = keysPerRow / 2; // Assumes equal split!

  row = keyIndex / keysPerRow;
  col = keyIndex % keysPerRow;
  if (row == 3) { // Specific to crkbd!
    col += 3; // Compensate for leading three NO_LED entries in g_led_config.
  }

  bool mirror = (col >= keysPerHalf);
  if (mirror) {
    // Normalise row and col per g_led_config structure.
    row += 4;
    col -= keysPerHalf;
    // Mirror column position.
    col = (keysPerHalf - 1) - col;
  }

  return g_led_config.matrix_co[row][col];
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layerNum = get_highest_layer(layer_state);
    if (layerNum == 0) {
        return;
    }

    uint8_t ledIndex = 0;
    uint8_t r, g, b;
    for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) { // 0 to 42
        ledIndex = ledIndexForKeymapIndex(keyIndex);

        if (ledIndex >= led_min && ledIndex <= led_max) {
            r = pgm_read_byte(&ledmap[layerNum][keyIndex][0]);
            g = pgm_read_byte(&ledmap[layerNum][keyIndex][1]);
            b = pgm_read_byte(&ledmap[layerNum][keyIndex][2]);

            if (!r && !g && !b) {
                RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 0, 0, 0);
            } else {
                RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, r, g, b);
            }
        }
    }
}
