#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "features/select_word.h"
#include "rgb/rgb_indicators.h"
#include "handlers/keycode_handler.h"
#include "init/init_user.h"
#include "combos/combos.h"
#include "keycodes/keycodes.h"
#include "combos/combos_symbols.h"
#include "combos/combos_misc.h"
#include "combos/combos_control.h"

// ---------------------------------------------------------------------------
// Aliases — mod-tap & layer-tap
//   GUI_ESC  tap:Esc    hold:GUI     |  GUI_QT   tap:'      hold:GUI
//   ALT_TAB  tap:Tab    hold:Alt     |  CTL_ENT  tap:Enter  hold:Ctrl
//   SFT_SCL  tap:;      hold:Shift   |  CTL_CMM  tap:,      hold:Ctrl
//   L1_DOT   tap:.      hold:Layer1  |  L1_PSCR  tap:PrtScr hold:Layer1
//   L2_SPC   tap:Space  hold:Layer2  |  L2_TAB   tap:Tab    hold:Layer2
//
// Short aliases (≤7 chars) for long keycodes — keeps the grid aligned:
//   COMMENT = DEV_COMMENT    Ctrl+/  (macOS: Cmd+/)
//   WD_LEFT = DEV_WORD_LEFT  Alt+←   (macOS) / Ctrl+← (Windows)
//   WD_RGHT = DEV_WORD_RIGHT Alt+→   (macOS) / Ctrl+→ (Windows)
//   D_HOME  = DEV_HOME       Cmd+←   (macOS) / Home   (Windows)
//   D_END   = DEV_END        Cmd+→   (macOS) / End    (Windows)
// ---------------------------------------------------------------------------
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_QT   LGUI_T(KC_QUOT)
#define ALT_TAB  LALT_T(KC_TAB)
#define CTL_ENT  RCTL_T(KC_ENT)
#define SFT_SCL  SFT_T(KC_SCLN)
#define CTL_CMM  LCTL_T(KC_COMM)
#define L1_DOT   LT(1, KC_DOT)
#define L1_PSCR  LT(1, KC_PSCR)
#define L2_SPC   LT(2, KC_SPC)
#define L2_TAB   LT(2, KC_TAB)

#define COMMENT  DEV_COMMENT
#define WD_LEFT  DEV_WORD_LEFT
#define WD_RGHT  DEV_WORD_RIGHT
#define D_HOME   DEV_HOME
#define D_END    DEV_END

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

    // — Control
    COMBO(left_enter,     KC_ENT),        // B+SPC
    COMBO(left_bspc,      KC_BSPC),       // G+SPC
    COMBO(t_SPC_DEL,      KC_DEL),        // T+SPC
    COMBO(n_ENT_spc,      KC_SPC),        // N+Enter
    COMBO(z_x_lsft_caps,  KC_CAPS),       // Z+X+Shift(;)
    COMBO(app_menu_combo, APP_MENU),      // M+N → KC_APP (Win) / Shift+F10 (Mac)
    COMBO(alt_tab_combo,  LALT(KC_TAB)),  // Tab+A → Alt+Tab

    // — Brackets (apertura)
    COMBO(bracket_combo,     KC_LBRC),
    COMBO(curly_brace_combo, KC_LCBR),
    COMBO(paren_combo,       KC_LPRN),

    // — Brackets (cierre)
    COMBO(bracket_close_combo, KC_RBRC),
    COMBO(curly_close_combo,   KC_RCBR),
    COMBO(paren_close_combo,   KC_RPRN),

    // — Misc (edita user_config.h para setear tus datos)
    COMBO(email_gmail_combo, EMAIL_GMAIL),
    COMBO(email_work_combo,  EMAIL_WORK),
    COMBO(username_combo,    USERNAME),
    COMBO(password_combo,    PASSWORD),

};

// ---------------------------------------------------------------------------
// Colores RGB para el mapa de LEDs
// ---------------------------------------------------------------------------
#define ___off___ {  0,   0,   0}
#define MG_CYAN   {  0, 206, 209}
#define MG_RED    {153,   0,   0}
#define MG_BLUE   {  0,   0, 153}
#define MG_PURPLE { 50,   0, 232}

// ---------------------------------------------------------------------------
// Keymap
// ---------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ========================================================================== */
/* LAYER 0 — BASE                                                              */
/* ========================================================================== */
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     GUI_ESC,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     ALT_TAB,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,           KC_H,      KC_J,      KC_K,      KC_L,      COMMENT,   GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     SFT_SCL,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,      WD_LEFT,   WD_RGHT,   D_END,     KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       CTL_CMM,   L1_DOT,    L2_SPC,        CTL_ENT,   L2_TAB,    L1_PSCR
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 1 — NAV (LEFT) + FUNCTION (RIGHT)                                    */
/* ========================================================================== */
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     _______,   D_HOME,    KC_UP,     D_END,     _______,   KC_NUM,         KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     WD_LEFT,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  WD_RGHT,   KC_PGUP,         KC_F1,     KC_F2,     KC_F3,      KC_F4,     KC_F5,     KC_F6,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   _______,   _______,   _______,   _______,   KC_PGDN,        _______,   _______,   _______,   _______,   _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       _______,   _______,   _______,        KC_INS,    _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 2 — NUMPAD (LEFT) + MOUSE (RIGHT)                                    */
/* ========================================================================== */
[2] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
       TOG_OS,    _______,      KC_7,      KC_8,      KC_9,  KC_NUM,         MS_WHLU,   MS_BTN1,   MS_UP,     MS_BTN2,    KC_WBAK,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
       _______,   _______,      KC_4,      KC_5,      KC_6,   KC_DOT,        MS_WHLD,   MS_LEFT,   MS_DOWN,   MS_RGHT,   KC_WFWD,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
       KC_PAUSE,   _______,     KC_1,      KC_2,      KC_3,   KC_COMM,       MS_BTN3,   _______,   _______,   _______,   _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                           KC_0,   _______,   _______,        LLOCK,     _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
)

};

// ---------------------------------------------------------------------------
// LED indicator map — layer 1 y 2 (layer 0 usa fondo PURPLE del rgb_indicators)
// ---------------------------------------------------------------------------
const uint8_t PROGMEM ledmap[2][42][3] = {

{   // Layer 1: Navegación (L) + Función (R)
    // top   L: ___  | HOME | UP  | END  | ___  | NUM              top   R: F7   | F8  | F9  | F10  | F11  | F12
    ___off___, ___off___,   MG_BLUE,  ___off___,   ___off___,      ___off___,  MG_RED,   MG_RED,   MG_RED,   MG_RED,   MG_RED,   MG_RED,
    // home  L: ___  | LEFT | DOWN | RGHT | ___  | ___              home  R: F4   | F5  | F6  | F1   | F2   | F3
    ___off___, MG_BLUE,  MG_BLUE,  MG_BLUE,  ___off___,           ___off___,  MG_RED,   MG_RED,   MG_RED,   MG_RED,   MG_RED,   MG_RED,
    // bot   L: ___  | PGUP | ___  | PGDN | ___  | ___              bot   R: ___  | ___  | ___  | ___  | ___  | ___
    ___off___, ___off___,   ___off___, ___off___,              ___off___, ___off___,  ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                    thumb R: INS  | ___  | ___
                               ___off___, ___off___, ___off___,                                  MG_CYAN,  ___off___, ___off___
},

{   // Layer 2: Números (L) + Mouse (R)
    // top   L: OS   |  ___  |  7  |  8   |  9  | NUM              top   R: WHLU  | ___  | BTN1 | UP   | BTN2 | WBAK
    MG_CYAN,  ___off___,   MG_RED,   MG_RED,   MG_RED, ___off___,  ___off___,  ___off___, MG_BLUE,   ___off___,  ___off___,   ___off___,
    // home  L: ___  |  ___  |  4  |  5   |  6  | PSCR             home  R: WHLD  | ___  | LEFT | DOWN | RGHT | WFWD
    ___off___, ___off___,   MG_RED,   MG_RED,   MG_RED, ___off___,  ___off___,  MG_BLUE,  MG_BLUE,  MG_BLUE,  ___off___,  ___off___,
    // bot   L: ___  | ___  |  1  |  2   |  3   | PAUSE            bot   R: BTN3  | ___  | ___  | ___  | ___  | ___
    ___off___, ___off___,   MG_RED,   MG_RED,   MG_RED,   ___off___,   ___off___,   ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                    thumb R: LLOCK | ___  | ___
                               MG_RED, ___off___, ___off___,                                  ___off___,  ___off___, ___off___
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
