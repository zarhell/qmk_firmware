#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "rgb/rgb_indicators.h"
#include "handlers/keycode_handler.h"
#include "init/init_user.h"
#include "combos/combos.h"
#include "keycodes/keycodes.h"
#include "combos/combos_symbols.h"
#include "combos/combos_misc.h"
#include "combos/combos_control.h"
#include "combos/combos_spanish.h"

#define GUI_QT   LGUI_T(KC_QUOT)
#define L2_TAB   LT(2, KC_TAB)
#define L2_PSCR  LT(2, KC_PSCR)

#define WD_LEFT  DEV_WORD_LEFT
#define WD_RGHT  DEV_WORD_RIGHT
#define D_HOME   DEV_HOME
#define D_END    DEV_END

combo_t key_combos[] = {

    COMBO(left_slsh,          KC_SLSH),
    COMBO(left_bsls,          KC_BSLS),
    COMBO(left_pipe,          KC_PIPE),
    COMBO(left_circ,          KC_CIRC),
    COMBO(left_lower_than,    KC_LT),
    COMBO(left_greather_than, KC_GT),
    COMBO(left_grv,           KC_GRV),
    COMBO(left_tild,          KC_TILD),
    COMBO(left_hash,          KC_HASH),
    COMBO(left_perc,          KC_PERC),
    COMBO(left_exlm,          KC_EXLM),
    COMBO(left_ques,          KC_QUES),
    COMBO(left_dlr,           KC_DLR),
    COMBO(left_at,            KC_AT),
    COMBO(left_ampr,          KC_AMPR),
    COMBO(left_astr,          KC_ASTR),
    COMBO(left_eq,            KC_EQL),
    COMBO(left_min,           KC_MINUS),
    COMBO(left_unds,          KC_UNDS),
    COMBO(left_plus,          KC_PLUS),
    COMBO(left_acute,         ACUTE_ACC),
    COMBO(left_comment,       DEV_COMMENT),

    COMBO(left_comma,   KC_COMMA),
    COMBO(left_dot,     KC_DOT),
    COMBO(left_semi,    KC_SCLN),
    COMBO(left_colon,   KC_COLON),
    COMBO(left_quote,   KC_QUOT),

    COMBO(left_enter,     KC_ENT),
    COMBO(left_bspc,      KC_BSPC),
    COMBO(t_SPC_DEL,      KC_DEL),
    COMBO(n_ENT_spc,      KC_SPC),
    COMBO(caps_combo,     KC_CAPS),
    COMBO(app_menu_combo, APP_MENU),

    COMBO(bracket_combo,      KC_LBRC),
    COMBO(gui_combo,          KC_LGUI),
    COMBO(curly_brace_combo, KC_LCBR),
    COMBO(paren_combo,       KC_LPRN),

    COMBO(bracket_close_combo, KC_RBRC),
    COMBO(curly_close_combo,   KC_RCBR),
    COMBO(paren_close_combo,   KC_RPRN),

    COMBO(bspc_a_combo, TILDE_A),
    COMBO(bspc_e_combo, TILDE_E),
    COMBO(bspc_i_combo, TILDE_I),
    COMBO(bspc_o_combo, TILDE_O),
    COMBO(bspc_u_combo, TILDE_U),
    COMBO(bspc_n_combo, ENIE),

    COMBO(email_gmail_combo, EMAIL_GMAIL),
    COMBO(email_work_combo,  EMAIL_WORK),
    COMBO(username_combo,    USERNAME),
    COMBO(password_combo,    PASSWORD),

};

#define ___off___ {  0,   0,   0}
#define MG_CYAN   {  0, 206, 209}
#define MG_RED    {153,   0,   0}
#define MG_BLUE   {  0,   0, 153}
#define MG_PURPLE { 50,   0, 232}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ========================================================================== */
/* LAYER 0 — BASE                                                              */
/* ========================================================================== */
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_ESC,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     L2_TAB,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,          KC_H,      KC_J,      KC_K,      KC_L,      KC_RCTL,   GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_RALT,   KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_LCTL,   MO(1),     LALT_T(KC_SPC),        KC_ENT,   MO(1),    L2_PSCR
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 1 — NAV (LEFT) + NÚMEROS (RIGHT)                                     */
/* ========================================================================== */
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_LEFT_GUI,   D_HOME,    KC_UP,     D_END,     _______,   LLOCK,           LLOCK,   KC_7,      KC_8,      KC_9,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    WIN_SWAP,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   KC_PGUP,        _______,   KC_4,      KC_5,      KC_6,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   WD_LEFT,   _______,   WD_RGHT,   _______,   KC_PGDN,        KC_NUM_LOCK, KC_1,      KC_2,      KC_3,      _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       _______,   _______,   _______,         _______,   _______,   KC_0
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 2 — MOUSE (LEFT) + FUNCIÓN (RIGHT)                                   */
/* ========================================================================== */
[2] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     TOG_OS,    MS_BTN1,   MS_UP,     MS_BTN2,   MS_BTN3,   MS_WHLU,        KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   MS_LEFT,   MS_DOWN,   MS_RGHT,  _______,   MS_WHLD,        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_PAUSE,  KC_WBAK,   KC_WFWD,   _______,   _______,   _______,        _______,   _______,   _______,   _______,   _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       LLOCK,   _______,   _______,         KC_INS,     _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
)

};

const uint8_t PROGMEM ledmap[2][42][3] = {

{   // Layer 1: Navegación (L) + Números (R)
    // top   L: ___   | D_HOME | UP    | D_END  | ___  | ___       top   R: ___  | 7    | 8    | 9    | ___  | ___
    ___off___, ___off___, MG_BLUE, ___off___, ___off___, ___off___,    ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // home  L: ___   | LEFT   | DOWN  | RIGHT  | ___  | PGUP      home  R: ___  | 4    | 5    | 6    | ___  | ___
    ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,      ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // bot   L: ___   | WD_L   | ___   | WD_R   | ___  | PGDN      bot   R: ___  | 1    | 2    | 3    | ___  | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,    ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                   thumb R: ___  | ___  | 0
                               ___off___, ___off___, ___off___,                                ___off___, ___off___, MG_RED
},

{   // (L) + Función (R)
    // top   L: TOG_OS | ___    | MS_UP | ___    | BTN1 | WHLU     top   R: F7     | F8     | F9     | F10    | F11    | F12
    ___off___, ___off___, MG_CYAN, ___off___, ___off___, ___off___,      MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,
    // home  L: ___    | MS_L   | MS_DN | MS_R   | BTN2 | WHLD     home  R: F1     | F2     | F3     | F4     | F5     | F6
    ___off___, MG_CYAN, MG_CYAN, MG_CYAN, ___off___, ___off___,        MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,
    // bot   L: PAUSE  | BTN3   | ___   | ___    | WBAK | WFWD     bot   R: ___    | ___    | ___    | ___    | ___    | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,      ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                   thumb R: LLOCK | ___  | ___
                               ___off___, ___off___, ___off___,                                MG_CYAN, ___off___, ___off___
}
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_TAB:
        case LALT_T(KC_SPC):
            return false;
        default:
            return true;
    }
}

uint16_t get_combo_len(void) {
    return sizeof(key_combos) / sizeof(combo_t);
}

void matrix_scan_user(void) {
    layer_lock_task();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 1)) {
        win_swap_cancel();
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    return handle_keycode(keycode, record);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}
#endif // OLED_ENABLE
