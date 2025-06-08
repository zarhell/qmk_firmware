#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "features/select_word.h"
#include "rgb/rgb_indicators.h"
#include "oled/oled_render.h"
#include "handlers/keycode_handler.h"
#include "init/init_user.h"
#include "combos/combos.h"
#include "keycodes/keycodes.h"
#include "combos/combos_symbols.h"
#include "combos/combos_media.h"

// COMBO simples que devuelven keycodes
combo_t key_combos[] = {
    COMBO(left_slsh, KC_SLSH),
    COMBO(left_bsls, KC_BSLS),
    COMBO(left_pipe, KC_PIPE),
    COMBO(left_circ, KC_CIRC),
    COMBO(left_lower_than, KC_LT),
    COMBO(left_greather_than, KC_GT),
    COMBO(left_grv, KC_GRV),
    COMBO(left_tild, KC_TILD),
    COMBO(left_hash, KC_HASH),
    COMBO(left_perc, KC_PERC),
    COMBO(left_exlm, KC_EXLM),
    COMBO(left_ques, KC_QUES),
    COMBO(left_dlr, KC_DLR),
    COMBO(left_at, KC_AT),
    COMBO(left_ampr, KC_AMPR),
    COMBO(left_astr, KC_ASTR),

    COMBO(numslsh, KC_SLSH),
    COMBO(numbsls, KC_BSLS),
    COMBO(numpipe, KC_PIPE),
    COMBO(numcirc, KC_CIRC),
    COMBO(numlt, KC_LT),
    COMBO(numgt, KC_GT),
    COMBO(numgrv, KC_GRV),
    COMBO(numtild, KC_TILD),
    COMBO(numhash, KC_HASH),
    COMBO(numperc, KC_PERC),
    COMBO(numexlm, KC_EXLM),
    COMBO(numques, KC_QUES),
    COMBO(numdlr, KC_DLR),
    COMBO(numat, KC_AT),
    COMBO(numampr, KC_AMPR),
    COMBO(numastr, KC_ASTR),

    COMBO(media_play_pause_combo, KC_MEDIA_PLAY_PAUSE),
    COMBO(media_vol_up_combo, KC_AUDIO_VOL_UP),
    COMBO(media_vol_down_combo, KC_AUDIO_VOL_DOWN),
    COMBO(media_mute_combo, KC_AUDIO_MUTE),
    COMBO(media_next_combo, KC_MEDIA_NEXT_TRACK),
    COMBO(media_prev_combo, KC_MEDIA_PREV_TRACK),
};

#define KC_ KC_TRNS

#define ___off___ {0,0,0}
#define MG_CYAN {0,206,209}
#define MG_RED {153,0,0}
#define MG_BLUE {0,0,153}
#define MG_PURPLE {50,0,232}
#define MG_GREEN {0,153,0}


// ----------------------------------------------------------------------------
// Keymap layers
// ----------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: QWERTY
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  Esc   │   Q    │   W    │   E    │   R    │   T    │      │   Y    │   U    │   I    │   O    │   P    │ Backsp │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   A    │   S    │   D    │   F    │   G    │      │   H    │   J    │   K    │   L    │   ;    │ GUI+'" │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │   Z    │   X    │   C    │   V    │   B    │      │   N    │   M    │   ,    │   .    │   /    │ Shift  │
     * └────────┴────────┴────────┴────────┴────────┴────────┴──────┴────────┴────────┴────────┴────────┴────────┴────────┘
     *         LCtrl    MO(1)    Space     Enter    LAlt     MO(2)
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LGUI_T(KC_QUOT),
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_LCTL, MO(1),    KC_SPC,     KC_ENT,  KC_LALT, MO(2)
    ),

    /* Layer 1: Navigation & Numpad
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │ LLock  │ Home   │  Up    │  End   │   _    │  Num   │      │ LLock  │   7    │   8    │   9    │   _    │   _    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   _    │ Left   │  Down  │ Right  │   _    │   _    │      │   _    │   4    │   5    │   6    │   _    │   _    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   _    │   _    │   _    │   _    │   _    │   _    │      │   _    │   1    │   2    │   3    │   _    │   _    │
     * └────────┴────────┴────────┴────────┴────────┴────────┴──────┴────────┴────────┴────────┴────────┴────────┴────────┘
     *         _       _       _       Ins     _       0
     */
    [1] = LAYOUT_split_3x6_3(
        LLOCK,    KC_HOME, KC_UP,   KC_END, KC_TRNS, KC_NUM,     LLOCK,    KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS,KC_TRNS,    KC_TRNS,  KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,  KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,    KC_INS,   KC_TRNS, KC_P0
    ),

    /* Layer 2: Numbers & Mouse
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │ LLock  │   1    │   2    │   3    │   _    │  Num   │      │   _    │   _    │ Home   │   Up   │  End   │   _    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   _    │   4    │   5    │   6    │   _    │  PScr  │      │   _    │   _    │ Left   │  Down  │ Right  │   _    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤      ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   _    │   7    │   8    │   9    │   0    │  Pause │      │   _    │   _    │   _    │   _    │   _    │   _    │
     * └────────┴────────┴────────┴────────┴────────┴────────┴──────┴────────┴────────┴────────┴────────┴────────┴────────┘
     *         _       _       _       PEnt    _       _
     */
    [2] = LAYOUT_split_3x6_3(
        LLOCK,    KC_1,   KC_2,    KC_3,   KC_TRNS, KC_NUM,   KC_TRNS,  KC_TRNS, KC_HOME, KC_UP,    KC_END,  KC_TRNS,
        KC_TRNS,  KC_4,   KC_5,    KC_6,   KC_TRNS, KC_PSCR,  KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN,  KC_RIGHT,KC_TRNS,
        KC_TRNS,  KC_7,   KC_8,    KC_9,   KC_0,    KC_PAUSE, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS,    KC_PENT,  KC_TRNS, KC_TRNS
    )
};

// ----------------------------------------------------------------------------
// LED indicator map (unchanged)
// ----------------------------------------------------------------------------
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


uint16_t get_combo_len(void) {
    return sizeof(key_combos) / sizeof(combo_t);
}


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
