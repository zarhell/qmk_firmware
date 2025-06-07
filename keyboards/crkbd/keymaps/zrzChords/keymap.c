#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "features/select_word.h"
#include "rgb/rgb_indicators.h"
#include "oled/oled_render.h"
#include "handlers/keycode_handler.h"
#include "init/init_user.h"
#include "combos/combos.h"

#define KC_ KC_TRNS

#define ___off___ {0,0,0}
#define MG_CYAN {0,206,209}
#define MG_RED {153,0,0}
#define MG_BLUE {0,0,153}
#define MG_PURPLE {50,0,232}
#define MG_GREEN {0,153,0}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.              ,-----------------------------------------------------.
          KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y, KC_U,  KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
            KC_TAB , KC_A,   KC_S,   KC_D,   KC_F,     KC_G,                   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, LGUI_T(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, MO(1) , KC_SPC,               KC_ENT,   KC_LALT, MO(2)
                                       //`--------------------------'                   `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                       ,-----------------------------------------------------.
      LLOCK, KC_HOME, KC_UP, KC_END, _______, KC_NUM,                              LLOCK,    KC_P7,    KC_P8,    KC_P9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                       _______,    KC_P4,    KC_P5,    KC_P6, _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                          _______,    KC_P1,    KC_P2,    KC_P3,  _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|         |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,         KC_INS, _______, KC_P0
                                      //`--------------------------'          `--------------------------'
  ),


  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      LLOCK,   KC_1, KC_2, KC_3,  _______, KC_NUM,                              _______, _______,   KC_HOME, KC_UP, KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_4, KC_5, KC_6, _______, KC_PSCR,                             _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_7, KC_8, KC_9, KC_0,  KC_PAUSE,                                 _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+-------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,          KC_PENT, _______, _______
                                      //`--------------------------'          `--------------------------'
  )
};

const uint8_t PROGMEM ledmap[][42][3] = {

[0] = {
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                       ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                       ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                       ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                                         ___off___, MG_RED, ___off___,                ___off___, MG_RED, ___off___
      },

[1] = {
___off___, MG_BLUE, MG_RED, MG_BLUE, ___off___, ___off___,                      ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,                            ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,                   ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
                                 ___off___, ___off___, ___off___,               ___off___, ___off___, MG_RED
      },

[2] = {
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                      ___off___, ___off___, MG_BLUE, MG_RED, MG_BLUE, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                      ___off___, ___off___,MG_RED, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, MG_BLUE, ___off___,                        ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
                                 ___off___, ___off___, ___off___,         ___off___, ___off___, ___off___
      }
};

extern combo_t* key_combos_ptr;
#define COMBO_LEN (sizeof(*key_combos_ptr) / sizeof(combo_t))

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


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    return handle_keycode(keycode, record);
}

#endif // OLED_ENABLE
