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
#include "combos/combos_misc.h"
#include "combos/combos_control.h"

// ---------------------------------------------------------------------------
// Aliases — mod-tap & layer-tap
//   GUI_ESC  tap:Esc    hold:GUI     |  GUI_QT  tap:'      hold:GUI
//   CTL_TAB  tap:Tab    hold:Ctrl    |  CTL_ENT tap:Enter  hold:Ctrl
//   SFT_SCL  tap:;      hold:Shift   |  ALT_CMM tap:,      hold:Alt
//   L1_DOT   tap:.      hold:Layer1  |  L1_PSCR tap:PrtScr hold:Layer1
//   L2_SPC   tap:Space  hold:Layer2  |  L2_TAB  tap:Tab    hold:Layer2
//
// DEV_HOME  = Cmd+← (macOS)  / Home (Windows)
// DEV_END   = Cmd+→ (macOS)  / End  (Windows)
// DEV_WORD_LEFT/RIGHT = Alt+←/→ (macOS) / Ctrl+←/→ (Windows)
// ---------------------------------------------------------------------------
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_QT   LGUI_T(KC_QUOT)
#define CTL_TAB  LCTL_T(KC_TAB)
#define CTL_ENT  LCTL_T(KC_ENT)
#define SFT_SCL  SFT_T(KC_SCLN)
#define ALT_CMM  LALT_T(KC_COMM)
#define L1_DOT   LT(1, KC_DOT)
#define L1_PSCR  LT(1, KC_PSCR)
#define L2_SPC   LT(2, KC_SPC)
#define L2_TAB   LT(2, KC_TAB)

// ---------------------------------------------------------------------------
// Combos
// ---------------------------------------------------------------------------
combo_t key_combos[] = {

    // — Símbolos (layer base)
    COMBO(left_slsh,          KC_SLSH),
    COMBO(left_bsls,          KC_BSLS),
    COMBO(left_pipe,          KC_PIPE),
    COMBO(left_circ,          KC_CIRC),
    COMBO(left_lower_than,    KC_LT),
    COMBO(left_greather_than, KC_GT),
    COMBO(left_grv,           KC_GRV),
    COMBO(left_tild,             KC_TILD),
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

    // — Control
    COMBO(left_enter,    KC_ENT),   // B+SPC
    COMBO(left_bspc,     KC_BSPC),  // G+SPC
    COMBO(t_SPC_DEL,     KC_DEL),   // T+SPC
    COMBO(n_ENT_spc,     KC_SPC),   // N+Enter
    COMBO(z_x_lsft_caps, KC_CAPS),  // Z+X+Shift

    // — Apertura de brackets
    COMBO(bracket_combo,     KC_LBRC),
    COMBO(curly_brace_combo, KC_LCBR),
    COMBO(paren_combo,       KC_LPRN),

    // — Cierre de brackets (Q+W / A+S / Z+X)
    COMBO(bracket_close_combo, KC_RBRC),
    COMBO(curly_close_combo,   KC_RCBR),
    COMBO(paren_close_combo,   KC_RPRN),

    // — Misc (edita user_config.h para setear tus datos)
    COMBO(email_gmail_combo, EMAIL_GMAIL),
    COMBO(email_work_combo,  EMAIL_WORK),
    COMBO(username_combo,    USERNAME),
    COMBO(password_combo,    PASSWORD),

};

// KC_ (sufijo vacío) = KC_TRNS, usado para posiciones transparentes en layers
#define KC_ KC_TRNS

// ---------------------------------------------------------------------------
// Colores RGB para el mapa de LEDs
// ---------------------------------------------------------------------------
#define ___off___ {  0,   0,   0}
#define MG_CYAN   {  0, 206, 209}
#define MG_RED    {153,   0,   0}
#define MG_BLUE   {  0,   0, 153}
#define MG_PURPLE { 50,   0, 232} 
#define MG_GREEN  {  0, 153,   0}

// ---------------------------------------------------------------------------
// Keymap
// ---------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌─────────────────────────────────────────────────────────────────────────┐
// │  Layer 0: QWERTY — escritura base sin KC_TRNS                          │
// └─────────────────────────────────────────────────────────────────────────┘
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     GUI_ESC,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     CTL_TAB,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,           KC_H,      KC_J,      KC_K,      KC_L,      DEV_COMMENT, GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     SFT_SCL,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,   DEV_WORD_LEFT, DEV_WORD_RIGHT, DEV_END, KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                      ALT_CMM,   L1_DOT,    L2_SPC,         CTL_ENT,   L2_TAB,    L1_PSCR
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

// ┌─────────────────────────────────────────────────────────────────────────┐
// │  Layer 1: Navegación (L) + Numpad (R)                                   │
// └─────────────────────────────────────────────────────────────────────────┘
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_TRNS,  DEV_HOME,   KC_UP,     DEV_END,   KC_TRNS,     LLOCK,          LLOCK,     KC_F9,     KC_F10,     KC_F11,   KC_F12,  KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  DEV_WORD_LEFT, KC_LEFT,  KC_DOWN,   KC_RIGHT,DEV_WORD_RIGHT, KC_TRNS,       KC_TRNS,   KC_F5,     KC_F6,     KC_F7,     KC_F8,   KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_TRNS,   KC_PGUP,   KC_TRNS,   KC_PGDN,   KC_TRNS,    KC_NUM,          KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,   KC_TRNS,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_TRNS,   KC_TRNS,   KC_TRNS,        KC_INS,    KC_TRNS,    KC_TRNS
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

// ┌─────────────────────────────────────────────────────────────────────────┐
// │  Layer 2: Números (L, layout numpad) + Mouse (R)                        │
// └─────────────────────────────────────────────────────────────────────────┘
[2] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     LLOCK,     KC_7,      KC_8,      KC_9,      TOG_OS,    KC_NUM,         MS_WHLU,   KC_TRNS,   MS_BTN1,   MS_UP,   MS_BTN2,   KC_WBAK,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_TRNS,   KC_4,      KC_5,      KC_6,      KC_DOT,    KC_PSCR,        MS_WHLD,   KC_TRNS,   MS_LEFT,   MS_DOWN,   MS_RGHT,   KC_WFWD,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_0,      KC_1,      KC_2,      KC_3,      KC_COMM,   KC_PAUSE,       MS_BTN3,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_TRNS,   KC_TRNS,   KC_TRNS,        LLOCK,     KC_TRNS,   KC_TRNS
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
)
};

// ---------------------------------------------------------------------------
// LED indicator map — layers 1 y 2 únicamente (layer 0 usa solo el fondo PURPLE)
// Índice 0 = Layer 1, Índice 1 = Layer 2
// ---------------------------------------------------------------------------
const uint8_t PROGMEM ledmap[2][42][3] = {

{   // Layer 1: Navegación (L) + Función (R)
    // top   L: TRNS | HOME | UP | END | TRNS | LLOCK                        top   R: LLOCK | F9 | F10 | F11 | F12 | TRNS
    ___off___, MG_RED,  MG_BLUE,  MG_RED,  ___off___, MG_CYAN,            MG_CYAN,  MG_RED,   MG_RED,   MG_RED,   MG_RED,   ___off___,
    // home  L: WORD_L | LEFT | DOWN | RIGHT | WORD_R | TRNS                 home  R: TRNS | F5 | F6 | F7 | F8 | TRNS
    MG_RED,  MG_BLUE,  MG_BLUE,  MG_BLUE,  MG_RED,  ___off___,           ___off___, MG_RED,   MG_RED,   MG_RED,   MG_RED,   ___off___,
    // bot   L: TRNS | PGUP | TRNS | PGDN | TRNS | NUM                       bot   R: TRNS | F1 | F2 | F3 | F4 | TRNS
    ___off___, MG_RED,  ___off___, MG_RED,  ___off___, ___off___,          ___off___, MG_RED,   MG_RED,   MG_RED,   MG_RED,   ___off___,
    // thumb L: TRNS | TRNS | TRNS                                            thumb R: INS | TRNS | TRNS
    ___off___, ___off___, ___off___,                                          ___off___, ___off___, ___off___
},

{   // Layer 2: Números (L) + Mouse (R)
    // top   L: LLOCK  |  7    |  8    |  9    | TOG_OS | NUM                top   R: WHLU  | TRNS  | BTN1  | MS_UP | BTN2  | WBAK
    MG_CYAN,  MG_RED,   MG_RED,   MG_RED,   ___off___, ___off___,           MG_CYAN,  ___off___, MG_RED,  MG_BLUE,  MG_RED,   ___off___,
    // home  L: TRNS   |  4    |  5    |  6    | DOT    | PSCR               home  R: WHLD  | TRNS  | LEFT  | DOWN  | RGHT  | WFWD
    ___off___, MG_RED,   MG_RED,   MG_RED,   ___off___, ___off___,           MG_CYAN,  ___off___, MG_BLUE, MG_BLUE,  MG_BLUE,  ___off___,
    // bot    L:  0    |  1    |  2    |  3    | COMM   | PAUSE               bot   R: BTN3  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS
    MG_RED,   MG_RED,   MG_RED,   MG_RED,   ___off___, ___off___,            MG_RED,   ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L: TRNS   | TRNS  | TRNS                                         thumb R: LLOCK | TRNS  | TRNS
    ___off___, ___off___, ___off___,                                           MG_CYAN,  ___off___, ___off___
}
};

uint16_t get_combo_len(void) {
    return sizeof(key_combos) / sizeof(combo_t);
}

void matrix_scan_user(void) {
    layer_lock_task();
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
