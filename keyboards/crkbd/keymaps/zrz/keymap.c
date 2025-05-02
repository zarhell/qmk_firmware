/*
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


#include "transactions.h"
#include "gui_state.h"
#include "boot.h"
#include "navi_logo.h"


#include "draw_helper.h"
#include "fast_random.h"


// left side
#include "layer_frame.h"
#include "burst.h"

// right side
#include "ring.h"

#define _QWERTY 0
#define _SYMBOL 1
#define _FUNKEY 2
#define _NUMPAD 3
#define _CURSOR 4

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

  [_QWERTY] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    LT(_FUNKEY , KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y, KC_U,  KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(_SYMBOL, KC_TAB) ,   KC_A,    KC_S,   KC_D,   KC_F,     KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, RSFT_T(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  LGUI_T(KC_APP),
        //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, KC_LALT , KC_SPC,                  KC_ENT, MO(_CURSOR),TG(_NUMPAD)
                                       //`--------------------------'                   `--------------------------'

  ),


  [_SYMBOL] = LAYOUT_split_3x6_3(
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
    [_FUNKEY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
      _______,KC_F1,KC_F2,KC_F3,KC_F4,  TG(_CURSOR),                                   KC_MPRV,  KC_MNXT,  _______,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      _______,KC_F5,KC_F6,KC_F7,KC_F8,TG(_NUMPAD),                                  KC_PAUSE,_______,_______,_______,_______,RESET,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______,KC_F9,KC_F10,KC_F11,KC_F12,_______,                                  KC_MPLY ,_______,_______,_______,KC_PSCR,LLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_ENT,  SELWORD,               KC_INS, KC_CAPS, _______
                                      //`--------------------------'             `--------------------------'
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                           ,-----------------------------------------------------.
      TO(_QWERTY), KC_1, KC_2, KC_3, _______, KC_NUM,                                    KC_P7,    KC_P8,    KC_P9,    KC_PMNS, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      _______, KC_4, KC_5, KC_6, _______, _______,                                   KC_P4,    KC_P5,    KC_P6,    KC_PSLS, KC_PAST,  _______,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
        _______, KC_7, KC_8, KC_9, KC_0, _______,                                    KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  KC_COMM, _______,
  //|--------+--------+--------+--------+--------+--------+--------|         |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,         KC_PENT, KC_P0, _______
                                      //`--------------------------'          `--------------------------'
  ),

  [_CURSOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
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

[_QWERTY] = {
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
                                         MG_RED, MG_RED, MG_RED,                MG_RED, MG_RED, MG_RED
      },
[_SYMBOL] = {
___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE,                            MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                      MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                 ___off___, ___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_GREEN,
                                 ___off___, MG_RED, ___off___,                  ___off___, ___off___, ___off___
      },

[_FUNKEY] = {
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, MG_RED, ___off___, ___off___, ___off___, ___off___,
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,                 MG_RED, ___off___, ___off___, ___off___, MG_RED, MG_GREEN,
                                            MG_RED, MG_RED, MG_RED,            MG_RED, MG_RED, ___off___
      },
[_NUMPAD] = {
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, MG_RED,                          MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                          MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,                               MG_BLUE, MG_BLUE, MG_BLUE, MG_RED, MG_RED, ___off___,
                                 ___off___, ___off___, ___off___,               MG_RED, MG_BLUE, ___off___
      },
[_CURSOR] = {
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
#if IS_LEFT
    update_scope();
#endif

#if IS_RIGHT
    update_circle(keycode);
#endif
}

void reset(void) {
#if IS_LEFT
    reset_scope();
#endif

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

    decay_scope();
    render_scope(t);
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

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        // master : store keycode to sent to the other side to be process_key
        last_keycode.keycode = keycode;
        b_sync_need_send     = true;

        // gui process the input
        process_key(keycode);
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

#if IS_LEFT
layer_state_t layer_state_set_user(layer_state_t state) {
    // update the frame with the layer name
    update_layer_frame(state);
    return state;
}
#endif
