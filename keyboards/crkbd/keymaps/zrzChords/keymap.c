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
#include "combos/combos_control.h"
#include "combos/combos_function.h"
#include "combos/combos_misc.h"

// ---------------------------------------------------------------------------
// Aliases — mod-tap & layer-tap para mejorar legibilidad del layout
// ---------------------------------------------------------------------------
#define GUI_QT  LGUI_T(KC_QUOT)  // tap = '      | hold = GUI
#define CTL_M1  LCTL_T(MS_BTN1) // tap = Mouse 1 | hold = Ctrl
#define ALT_M2  LALT_T(MS_BTN2) // tap = Mouse 2 | hold = Alt
#define L1_SPC  LT(1, KC_SPC)   // tap = Espacio  | hold = Layer 1
#define L1_TAB  LT(1, KC_TAB)   // tap = Tab      | hold = Layer 1
#define L2_SCR  LT(2, KC_PSCR)  // tap = PrtScr   | hold = Layer 2

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

    // — Media
    COMBO(media_play_pause_combo, KC_MEDIA_PLAY_PAUSE),
    COMBO(media_vol_up_combo,     KC_AUDIO_VOL_UP),
    COMBO(media_vol_down_combo,   KC_AUDIO_VOL_DOWN),
    COMBO(media_mute_combo,       KC_AUDIO_MUTE),
    COMBO(media_next_combo,       KC_MEDIA_NEXT_TRACK),
    COMBO(media_prev_combo,       KC_MEDIA_PREV_TRACK),

    // — Control
    COMBO(left_enter,        KC_ENT),
    COMBO(left_bspc,         KC_BSPC),
    COMBO(n_ENT_spc,         KC_SPC),
    COMBO(z_x_lsft_caps,     KC_CAPS),
    COMBO(t_SPC_DEL,         KC_DEL),
    COMBO(dot_slsh_rsft_app, KC_APP),
    COMBO(select_word,       SELWORD),
    COMBO(gui_a_tab,         KC_TAB),
    COMBO(copy_combo,        LCTL(KC_C)),
    COMBO(cut_combo,         LCTL(KC_X)),
    COMBO(paste_combo,       LCTL(KC_V)),
    COMBO(undo_combo,        LCTL(KC_Z)),

    // — Símbolos agrupados (bracket_combo, curly_brace_combo, paren_combo)
    COMBO(bracket_combo,     KC_LBRC),
    COMBO(curly_brace_combo, KC_LCBR),
    COMBO(paren_combo,       KC_LPRN),

    // — Misc (edita user_config.h para setear tus datos)
    COMBO(email_gmail_combo, EMAIL_GMAIL),
    COMBO(email_work_combo,  EMAIL_WORK),
    COMBO(username_combo,    USERNAME),
    COMBO(password_combo,    PASSWORD),

    // — Función
    COMBO(func_1,  KC_F1),
    COMBO(func_2,  KC_F2),
    COMBO(func_3,  KC_F3),
    COMBO(func_4,  KC_F4),
    COMBO(func_5,  KC_F5),
    COMBO(func_6,  KC_F6),
    COMBO(func_7,  KC_F7),
    COMBO(func_8,  KC_F8),
    COMBO(func_9,  KC_F9),
    COMBO(func_10, KC_F10),
    COMBO(func_11, KC_F11),
    COMBO(func_12, KC_F12),
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
// │  Layer 0: QWERTY                                                        │
// └─────────────────────────────────────────────────────────────────────────┘
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_ESC,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_LGUI,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,           KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       CTL_M1,    ALT_M2,    L1_SPC,         KC_ENT,    L1_TAB,    L2_SCR
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

// ┌─────────────────────────────────────────────────────────────────────────┐
// │  Layer 1: Nav (L) + Numpad (R)                                          │
// └─────────────────────────────────────────────────────────────────────────┘
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_P7,     KC_P8,     KC_P9,     KC_HOME,   KC_UP,     KC_END,          LLOCK,     KC_P7,     KC_P8,     KC_P9,     KC_TRNS,   KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_P4,     KC_P5,     KC_P6,     KC_LEFT,   KC_DOWN,   KC_RIGHT,         KC_TRNS,   KC_P4,     KC_P5,     KC_P6,     KC_TRNS,   KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_P1,     KC_P2,     KC_P3,     LLOCK,     KC_TRNS,   KC_NUM,           KC_TRNS,   KC_P1,     KC_P2,     KC_P3,     KC_TRNS,   KC_TRNS,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_TRNS,   KC_TRNS,   KC_TRNS,        KC_INS,    KC_TRNS,   KC_P0
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

// ┌─────────────────────────────────────────────────────────────────────────┐
// │  Layer 2: Números (L) + Mouse (R)                                       │
// └─────────────────────────────────────────────────────────────────────────┘
[2] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     LLOCK,     KC_1,      KC_2,      KC_3,      KC_TRNS,   KC_NUM,         MS_BTN1,   MS_WHLU,   MS_UP,   MS_WHLD,   KC_TRNS,   KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_TRNS,   KC_4,      KC_5,      KC_6,      KC_TRNS,   KC_PSCR,        MS_BTN2,   MS_LEFT,   MS_DOWN,   MS_RGHT,   KC_TRNS,   KC_TRNS,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_TRNS,   KC_7,      KC_8,      KC_9,      KC_0,      KC_PAUSE,       MS_BTN3,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_TRNS,   KC_TRNS,   KC_TRNS,        LLOCK,     KC_TRNS,   KC_TRNS
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
)
};

// ---------------------------------------------------------------------------
// LED indicator map  (42 entradas: 6×3 rows × 2 halves + 3 thumbs × 2)
// ---------------------------------------------------------------------------
const uint8_t PROGMEM ledmap[][42][3] = {

[0] = {
    // top   L                                                                top   R
    MG_PURPLE, ___off___, ___off___, ___off___, ___off___, ___off___,        ___off___, ___off___, ___off___, ___off___, ___off___, MG_PURPLE,
    // home  L                                                                home  R
    MG_PURPLE, ___off___, ___off___, ___off___, ___off___, ___off___,        ___off___, ___off___, ___off___, ___off___, ___off___, MG_PURPLE,
    // bot   L                                                                bot   R
    MG_PURPLE, ___off___, ___off___, ___off___, ___off___, ___off___,        ___off___, ___off___, ___off___, ___off___, ___off___, MG_PURPLE,
    // thumb L                                  thumb R
                                 MG_PURPLE, MG_PURPLE,    MG_PURPLE,             MG_PURPLE, MG_PURPLE,  MG_PURPLE
},

[1] = {
    // top   L                                                                top   R
    ___off___, ___off___,   ___off___, ___off___, MG_BLUE, ___off___,       ___off___, MG_RED,    MG_RED,    MG_RED,    ___off___, ___off___,
    // home  L                                                                home  R
    ___off___, ___off___,    ___off___,    MG_BLUE, MG_BLUE, MG_BLUE,       ___off___, MG_RED,    MG_RED,    MG_RED,    ___off___, ___off___,
    // bot   L                                                                bot   R
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,       ___off___, MG_RED,    MG_RED,    MG_RED,    ___off___, ___off___,
    // thumb L                                  thumb R
    ___off___, ___off___, ___off___,             ___off___, ___off___, ___off___
},

[2] = {
    // top   L                                                                top   R (BTN1=azul, WHLU=verde, UP=rojo, WHLD=verde)
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,        MG_BLUE,   MG_GREEN,  MG_RED,    MG_GREEN,  ___off___, ___off___,
    // home  L                                                                home  R (BTN2=azul, LEFT/DOWN/RGHT=rojo)
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,        MG_BLUE,   MG_RED,    MG_RED,    MG_RED,    ___off___, ___off___,
    // bot   L                                                                bot   R (BTN3=azul)
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,        MG_BLUE,   ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L                                  thumb R (LLOCK=cyan)
    ___off___, ___off___, ___off___,             MG_CYAN,   ___off___, ___off___
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
