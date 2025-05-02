zz/*
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

#include "features/layer_lock.h"
#include "features/select_word.h"




#define _QWERTY 0
#define _SYMBOL 2
#define _FUNKEY 4
#define _NUMPAD 8
#define _CURSOR 16

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  SELWORD,
  // Other custom keys...
};

#define ___off___ {0,0,0}
#define MG_CYAN {0,206,209}
#define MG_RED {153,0,0}
#define MG_BLUE {0,0,153}
#define MG_PURPLE {50,0,232}
#define MG_GREEN {0,153,0}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    LT(2 , KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y, KC_U,  KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(1, KC_TAB) ,   KC_A,    KC_S,   KC_D,   KC_F,     KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, RSFT_T(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  LGUI_T(KC_APP),
        //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, KC_LALT , KC_SPC,                  KC_ENT, MO(4),TG(3)
                                       //`--------------------------'                   `--------------------------'

  ),


  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      _______, KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT,                       KC_CIRCUMFLEX,  KC_AMPERSAND,  KC_ASTERISK,KC_LEFT_PAREN, KC_RIGHT_PAREN, _______,
  //|--------+--------+--------+--------+--------+--------|                               |--------+--------+--------+--------+--------+--------|
      _______,_______ ,_______,_______,_______,_______,                                    KC_LCBR,KC_RCBR, KC_BSLS,KC_MINS,KC_PLUS,_______,
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      _______,_______,_______,_______,_______,_______,                               KC_TILDE,KC_GRAVE,KC_UNDERSCORE,KC_EQL,KC_PIPE,LLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,            _______, _______, _______
                                      //`--------------------------'            `--------------------------'
  ),
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      _______,KC_F1,KC_F2,KC_F3,KC_F4,  TG(4),                                   KC_MPRV,  KC_MNXT,  _______,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      _______,KC_F5,KC_F6,KC_F7,KC_F8,TG(3),                                  KC_PAUSE,_______,_______,_______,_______,RESET,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______,KC_F9,KC_F10,KC_F11,KC_F12,_______,                                  KC_MPLY ,_______,_______,_______,KC_PSCR,LLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_ENT,  SELWORD,               KC_INS, KC_CAPS, _______
                                      //`--------------------------'             `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                           ,-----------------------------------------------------.
      TO(0), KC_1, KC_2, KC_3, _______, KC_NUM,                                    KC_P7,    KC_P8,    KC_P9,    KC_PMNS, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      _______, KC_4, KC_5, KC_6, _______, _______,                                   KC_P4,    KC_P5,    KC_P6,    KC_PSLS, KC_PAST,  _______,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
        _______, KC_7, KC_8, KC_9, KC_0, _______,                                    KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  KC_COMM, _______,
  //|--------+--------+--------+--------+--------+--------+--------|         |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,         KC_PENT, KC_P0, _______
                                      //`--------------------------'          `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TO(0), _______, _______, _______, _______, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_UP, KC_END, _______, KC_PGUP,                      KC_PGUP, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_PGDN,                      KC_PGDN, _______, _______, _______, _______, LLOCK,
  //|--------+--------+--------+--------+--------+-------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,          _______, _______, _______
                                      //`--------------------------'          `--------------------------'
  )
};

const uint8_t PROGMEM ledmap[][42][3] = {

[0] = {
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
                                         MG_RED, MG_RED, MG_RED,                MG_RED, MG_RED, MG_RED
      },
[1] = {
___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE,                            MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                      MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                 ___off___, ___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_GREEN,
                                 ___off___, MG_RED, ___off___,                  ___off___, ___off___, ___off___
      },

[2] = {
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, MG_RED, ___off___, ___off___, ___off___, ___off___,
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, ___off___, ___off___, ___off___, MG_RED, MG_GREEN,
                                            MG_RED, MG_RED, MG_RED,            MG_RED, MG_RED, ___off___
      },
[3] = {
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, MG_RED,                          MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                          MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,                               MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
                                 ___off___, ___off___, ___off___,               MG_RED, MG_BLUE, ___off___
      },
[4] = {
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                      ___off___, MG_BLUE, MG_RED, MG_BLUE, ___off___, ___off___,
___off___, MG_BLUE, MG_RED, MG_BLUE, ___off___, MG_BLUE,                          MG_BLUE, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
___off___, MG_RED, MG_RED, MG_RED, ___off___, MG_BLUE,                 MG_BLUE, ___off___, ___off___, ___off___, ___off___, MG_GREEN,
                                 ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      }
};


void matrix_scan_user(void) {
  layer_lock_task();
  // Other tasks...
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _CURSOR:
            oled_write_ln_P(PSTR("Cursor"), false);
            break;
        case _FUNKEY:
        case _FUNKEY | _SYMBOL:
        case _FUNKEY | _NUMPAD:
        case _FUNKEY | _CURSOR:
        case _FUNKEY | _SYMBOL | _NUMPAD | _CURSOR:
            oled_write_ln_P(PSTR("Funkey"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}


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
    // if (layerNum == 0) {
    //     return;
    // }

     // Per-key indicators
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




uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    // lock layer when pressed
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

     if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }

     // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
           case KC_BSPC: {
               // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                   // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                       // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else {  // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                       unregister_code(KC_DEL);
                       delkey_registered = false;
                       return false;
                }
            }
               // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }

       return true;
}

#endif
