#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "rgb/rgb_indicators.h"
#include "handlers/keycode_handler.h"
#include "init/init_user.h"
#include "combos/combos.h"
#include "keycodes/keycodes.h"
#include "combos/combos_symbols.h"
#include "combos/combos_control.h"

#define GUI_QT   LGUI_T(KC_QUOT)
#define ALGR_TAB RALT_T(KC_TAB)
#define UNDO     LCTL(KC_Z)
#define CUT      LGUI(KC_X)
#define COPY     LGUI(KC_C)
#define PASTE    LGUI(KC_V)
#define CLIP_HIST LGUI(LCTL(KC_V))

#define D_HOME   KC_HOME
#define D_END    KC_END

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

    COMBO(left_comma,   KC_COMMA),
    COMBO(left_dot,     KC_DOT),
    COMBO(left_semi,    KC_SCLN),
    COMBO(left_colon,   KC_COLON),
    COMBO(left_quote,   KC_DQUO),
    COMBO(left_apos,    KC_QUOT),

    COMBO(left_enter,     KC_ENT),
    COMBO(left_bspc,      KC_BSPC),
    COMBO(t_SPC_DEL,      KC_DEL),
    COMBO(n_ENT_spc,      KC_SPC),
    COMBO(left_caps,        CW_TOGG),

};

// Colors are palette indices (see enum led_color / led_palette in rgb/rgb_indicators.*)
#define ___off___ C_OFF
#define MG_CYAN   C_CYAN
#define MG_RED    C_RED
#define MG_BLUE   C_BLUE
#define MG_PURPLE C_PURPLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ========================================================================== */
/* LAYER 0 — BASE                                                              */
/* ========================================================================== */
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     KC_ESC,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     ALGR_TAB,  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,          KC_H,      KC_J,      KC_K,      KC_L,      KC_RCTL,   GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_RALT,   KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       GUI_CTL,   MO1_ALT,   KC_SPC,               KC_ENT,   MO1_MS,   MO(2)
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 1 — NAV + PORTAPAPELES (LEFT) + NÚMEROS (RIGHT)                     */
/* ========================================================================== */
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     _______,   D_HOME,   KC_UP,        D_END,     XXXXXXX,   LLOCK,          LLOCK,     KC_7,      KC_8,      KC_9,      XXXXXXX,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     WIN_SWAP,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  CLIP_HIST, XXXXXXX,        XXXXXXX,   KC_4,      KC_5,      KC_6,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   UNDO,      CUT,       COPY,      PASTE,     XXXXXXX,        KC_0,      KC_1,      KC_2,      KC_3,      _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       _______,   _______,   _______,         _______,   _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 2 — FUNCIÓN (LEFT) + MOUSE/FLECHAS (RIGHT)                           */
/* ========================================================================== */
[2] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     LLOCK,          LLOCK,     MS_BTN1,   MS_BTN3,   KC_UP,     MS_BTN2,   QK_BOOT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   KC_F5,     KC_F6,     KC_F7,     KC_F8,     XXXXXXX,        XXXXXXX,    XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  XXXXXXX,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    XXXXXXX,        KC_PAUSE,  KC_WBAK,   KC_WFWD,   XXXXXXX,   MS_WHLU,   MS_WHLD,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_INS,    _______,   _______,         LLOCK,     _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 3 — BRACKETS + BOTONES MOUSE (LEFT) + MOUSE VIRTUAL (RIGHT)          */
/* ========================================================================== */
[3] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     _______,   KC_LBRC,   KC_RBRC,   MS_BTN1,   MS_BTN3,   MS_BTN2,        LLOCK,     MV_NW,     MV_N,      MV_NE,     XXXXXXX,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   KC_LCBR,   KC_RCBR,   KC_WBAK,   KC_WFWD,   LLOCK,          XXXXXXX,   MV_W,      XXXXXXX,   MV_E,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   KC_LPRN,   KC_RPRN,   XXXXXXX,   XXXXXXX,   XXXXXXX,        XXXXXXX,   MV_SW,     MV_S,      MV_SE,     _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       _______,   _______,   _______,         _______,   _______,   _______
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
)

};

const uint8_t PROGMEM ledmap[3][42] = {

{   // Layer 1: solo flechas iluminadas a la izquierda (L) + Números (R)
    // top   L: GUI   | D_HOME | UP    | D_END  | ___  | LLOCK     top   R: LLOCK | 7    | 8    | 9    | ___  | BSPC
    ___off___, ___off___, MG_BLUE, ___off___, ___off___, ___off___,    ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // home  L: SWAP  | LEFT   | DOWN  | RIGHT  | CLIP | PGUP      home  R: ___  | 4    | 5    | 6    | ___  | ___
    ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,      ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // bot   L: ___   | UNDO   | CUT   | COPY   | PASTE| PGDN      bot   R: 0     | 1    | 2    | 3    | ___  | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,    MG_RED, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                   thumb R: ___  | ___  | ___
                               ___off___, ___off___, ___off___,                                ___off___, ___off___, ___off___
},

{   // Función (L) + Mouse/Flechas (R)
    // top   L: ___    | F1     | F2     | F3     | F4   | LLOCK     top   R: LLOCK  | BTN1 | BTN3  | UP    | BTN2 | BOOT
    ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,    ___off___, ___off___, ___off___, MG_CYAN, ___off___, ___off___,
    // home  L: ___    | F5     | F6     | F7     | F8   | ___       home  R: ___    | ___  | LEFT  | DOWN  | RIGHT| ___
    ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,    ___off___, ___off___, MG_CYAN, MG_CYAN, MG_CYAN, ___off___,
    // bot   L: ___    | F9     | F10    | F11    | F12  | ___       bot   R: PAUSE  | WBAK | WFWD  | ___   | WHLU | WHLD
    ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,
    // thumb L: INS  | ___  | ___                                   thumb R: LLOCK | ___  | ___
                               ___off___, ___off___, ___off___,                                ___off___, ___off___, ___off___
},

{   // Brackets/botones mouse (L) + Mouse virtual (R): un toque = lento, doble toque = rápido
    // top   L: ESC     | [      | ]      | BTN_IZQ | BTN_MED | BTN_DER   top   R: LLOCK | NW   | N    | NE   | ___  | BSPC
    ___off___, ___off___, ___off___, MG_CYAN, MG_CYAN, MG_CYAN,    ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,
    // home  L: ___   | {      | }      | BACK    | FWD     | LLOCK       home  R: ___  | W    | ___  | E    | ___  | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,    ___off___, MG_BLUE, ___off___, MG_BLUE, ___off___, ___off___,
    // bot   L: ___   | (      | )      | ___     | ___     | ___        bot   R: ___  | SW   | S    | SE   | ___  | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,    ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                   thumb R: ___  | ___  | ___
                               ___off___, ___off___, ___off___,                                ___off___, ___off___, ___off___
}
};

// Caps Word: letras en mayuscula; digitos, - _ Backspace/Delete y las teclas
// propias de capa/modificador no terminan la palabra.
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
        case GUI_CTL:
        case MO1_ALT:
        case MO1_MS:
        case MV_NW ... MV_SE:
            return true;
        default:
            return false;
    }
}

uint16_t get_combo_len(void) {
    return sizeof(key_combos) / sizeof(combo_t);
}

void matrix_scan_user(void) {
    layer_lock_task();
    rgb_lock_sync_task();
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
    return OLED_ROTATION_270;
}
#endif // OLED_ENABLE   