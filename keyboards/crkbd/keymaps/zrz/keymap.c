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

// HELLO NAVI
#include "transactions.h"
#include "gui_state.h"
#include "boot.h"
#include "navi_logo.h"

#if IS_LEFT
#include "layer_frame.h"
#else
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _NUMPAD,
  _CURSOR,
  _EDIT,
  _GAME
};
#endif

#include "draw_helper.h"
#include "fast_random.h"
#include "ring.h"

#define SE_PLUS KC_MINS
#define SE_ACUT KC_EQL
#define SE_QUOT KC_NUHS
#define SE_SECT KC_GRV
#define SE_PIPE A(KC_7)
#define SE_GRV  S(SE_ACUT)
#define SE_LBRC A(KC_8)
#define SE_RBRC A(KC_9)
#define SE_ODIA KC_SCLN // Ö
#define SE_ADIA KC_QUOT // Ä
#define SE_ARNG KC_LBRC
#define SE_DIAE KC_RBRC
#define SE_BSLS S(A(KC_7))
#define SE_LCBR S(A(KC_8))    // {
#define SE_RCBR S(A(KC_9))    // }
#define SE_LABK KC_NUBS // <
#define SE_RABK S(SE_LABK) // >
#define SE_QUES S(SE_PLUS)

#define S_A LSFT_T(KC_A)
#define C_S LCTL_T(KC_S)
#define A_D LALT_T(KC_D)
#define G_F LGUI_T(KC_F)
#define C_J RCTL_T(KC_J)
#define A_K RALT_T(KC_K)
#define G_L RGUI_T(KC_L)
#define S_T RSFT_T(SE_ACUT)
#define UNDO LGUI(KC_Z)
#define REDO SGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define FLYCUT SGUI(KC_V)
#define SCRSHOT LGUI(LSFT(KC_4))

#define ___off___ {0,0,0}
#define MG__WHITE {255,255,255}
#define MG____RED {255,0,0}
#define MG__GREEN {32,159,33}
#define MG___BLUE {0,181,213}
#define MG_YELLOW {255,208,0}
#define MG_ORANGE {255,85,0}
#define MG___PINK {208,0,255}
#define MG_PURPLE {50,0,232}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD, KC_ESC),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_TAB,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,  KC_J,     KC_K,   KC_L,  KC_SCLN, SE_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            SE_PLUS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENTER,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LGUI,MO(_LOWER),  KC_SPC,MO(_CURSOR),MO(_EDIT), TO(_GAME)
                                            //`--------------------------'  `--------------------------'

  ),

  //KC_APP Application (Windows Context Menu Key)

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SE_SECT,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),         LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT(SE_SECT), SE_PIPE,LALT(KC_2),SE_LCBR,SE_RCBR, SE_QUES,                   LALT(KC_4), SE_ARNG,   SE_ADIA,SE_ODIA, LALT(SE_DIAE), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SE_LABK, SE_RABK, SE_BSLS, _______, _______, _______,                       SE_GRV, SE_LBRC, SE_RBRC, _______, _______,LSFT(SE_DIAE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_AT, KC_HASH, KC_LPRN, KC_RPRN, KC_BSLS,                      KC_PSLS,    KC_P7,    KC_P8,    KC_P9, KC_PMNS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MINS, KC_EQL, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, _______,     KC_PAST,    KC_P4,    KC_P5,    KC_P6, KC_PPLS,  KC_PEQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RESET, _______, _______, _______, _______, _______,                KC_COMM,    KC_P1,    KC_P2,    KC_P3,  KC_PDOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, _______, KC_P0
                                      //`--------------------------'  `--------------------------'
  ),

  [_CURSOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                      _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, SCRSHOT,    UNDO,    REDO, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,     CUT,    COPY,   PASTE, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,  FLYCUT, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD, KC_ESC),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, SE_ACUT, RSFT_T(KC_ENTER),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            SE_PLUS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SE_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LCTL, KC_LALT, LGUI_T(KC_SPC),    KC_RGUI, KC_RALT, TO(_QWERTY)
                                            //`--------------------------'  `--------------------------'

  )
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
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,         ___off___, MG___BLUE, MG___BLUE, MG___BLUE, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                                 ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      },
[_EDIT] = {
___off___, ___off___, MG___BLUE, MG_PURPLE, MG_YELLOW, ___off___,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, ___off___, MG____RED, MG_ORANGE, MG__GREEN, ___off___,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, MG__WHITE, ___off___,         ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                                 ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      }/*,
[_GAME] = {
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
MG____RED, MG_ORANGE, MG_YELLOW, MG__GREEN, MG_PURPLE, MG___PINK,         MG___PINK, MG_PURPLE, MG__GREEN, MG_YELLOW, MG_ORANGE, MG____RED,
                                 MG__WHITE, MG__WHITE, MG___BLUE,         MG___BLUE, MG__WHITE, MG__WHITE
      },*/
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

// sync transport
typedef struct _sync_keycode_t {
    uint16_t keycode;
} sync_keycode_t;

// force rigth side to update
bool b_sync_need_send = false;

// last keycode typed
sync_keycode_t last_keycode;

void update(uint16_t keycode) {
#if IS_RIGHT
    update_circle(keycode);
#endif
}

void reset(void) {
#if IS_RIGHT
    reset_ring();
#endif
}

void set_wackingup_mode_clean(void) {
    oled_clear();
    reset();
}

void process_key(uint16_t keycode) {
    // update screen with the new key
    update(keycode);

    gui_state_t t = get_gui_state();

    if (t == _IDLE) {
        // wake up animation
        reset();
    }

    if (t == _BOOTING || t == _HALTING) {
        // cancel booting or halting : waking_up
        set_wackingup_mode_clean();
    }

    if (t == _SLEEP) {
        // boot sequence
        set_wackingup_mode_clean();
        reset_boot();
    }

    update_gui_state();
}

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const sync_keycode_t* m2s = (const sync_keycode_t*)in_data;
    // get the last char typed on left side and update the right side
    process_key(m2s->keycode);
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // (180, 255, 231) is purple
    rgb_matrix_mode_noeeprom(1);
    // HELLO NAVI
    transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);
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

// HELLO NAVI
// clang-format on

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // vertical orientation
    return OLED_ROTATION_270;
}

void render(gui_state_t t) {
    // logo
    render_logo(t);
#if IS_LEFT
    // left side
    render_layer_frame(t);
    render_gears();
#endif

#if IS_RIGHT
    // right side
    render_circle(t);
#endif
}

bool oled_task_user(void) {
    gui_state_t t = get_gui_state();

    // in sleep mode => turn display off
    if (t == _SLEEP) {
        oled_off();
        return false;
    }

    // not in sleep mode => screen is on
    oled_on();

#ifdef WITH_BOOT
    // in booting mode => display booting animation
    if (t == _BOOTING) {
        bool boot_finished = render_boot();
        if (boot_finished) {
            // end of the boot : wacking up
            set_wackingup_mode_clean();
            update_gui_state();
        }
        return false;
    }
#endif

    // in halting mode => display booting animation
    if (t == _HALTING) {
        render_halt();
        return false;
    }

    render(t);
    return false;
}

void housekeeping_task_user(void) {
    // only for master side
    if (!is_keyboard_master()) return;

    // only if a new char was typed
    if (!b_sync_need_send) return;

    // send the char to the slave side : sync is done
    if (transaction_rpc_send(USER_SYNC_A, sizeof(last_keycode), &last_keycode)) {
        b_sync_need_send = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        // master : store keycode to sent to the other side to be process_key
        last_keycode.keycode = keycode;
        b_sync_need_send     = true;

        // gui process the input
        process_key(keycode);
    }
    return true;
}

#if IS_LEFT
layer_state_t layer_state_set_user(layer_state_t state) {
    // update the frame with the layer name
    update_layer_frame(state);
    return state;
}
#endif
