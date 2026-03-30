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
#include "combos/combos_spanish.h"

// ---------------------------------------------------------------------------
// Aliases — mod-tap & layer-tap
//
//   GUI_ESC  tap:Esc    hold:GUI     |  GUI_QT   tap:'      hold:GUI
//   L2_TAB   tap:Tab    hold:Layer2  |  ALT_G    tap:G      hold:Alt
//   L2_PSCR  tap:PrtScr hold:Layer2
//
// Pinky izquierdo home row:
//   L2_TAB   Tab / Layer2 — acceso a Mouse y F-keys desde mano izquierda
//
// Home row izquierdo col 5:
//   ALT_G    G tap, Alt hold — modificador Alt sin salir de home row
//
// Thumb izquierdo:
//   KC_LCTL  Ctrl puro — 0 delay para Ctrl+C/V/Z/X
//   MO(1)    Layer 1 momentáneo (sin tap)
//   KC_SPC   Space puro — permite combos B+SPC, G+SPC, T+SPC
//
// Thumb derecho:
//   KC_ENT   Enter puro
//   MO(1)    Layer 1 momentáneo
//   L2_PSCR  tap:PrtScr hold:Layer2 — acceso Layer2 desde mano derecha
//
// Nota L2_TAB / ALT_G: PERMISSIVE_HOLD deshabilitado vía get_permissive_hold()
//   para evitar activación accidental de capa/modificador en combos rápidos.
//
// Layer 1, posición L2_PSCR:
//   KC_0 — tap cuando Layer1 está activo vía MO(1)
//
// Short aliases:
//   WD_LEFT = DEV_WORD_LEFT  Alt+← (macOS) / Ctrl+← (Windows)
//   WD_RGHT = DEV_WORD_RIGHT Alt+→ (macOS) / Ctrl+→ (Windows)
//   D_HOME  = DEV_HOME       Cmd+← (macOS) / Home (Windows)
//   D_END   = DEV_END        Cmd+→ (macOS) / End (Windows)
//
// COMMENT eliminado del layout → X+D+F combo → DEV_COMMENT
// WIN_SWAP en Layer 1 posición Tab → Alt+Tab(Win) / Cmd+Tab(Mac)
// ---------------------------------------------------------------------------
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_QT   LGUI_T(KC_QUOT)
#define L2_TAB   LT(2, KC_TAB)
#define ALT_G    LALT_T(KC_G)
#define L2_PSCR  LT(2, KC_PSCR)

#define WD_LEFT  DEV_WORD_LEFT
#define WD_RGHT  DEV_WORD_RIGHT
#define D_HOME   DEV_HOME
#define D_END    DEV_END

// ---------------------------------------------------------------------------
// Combos
// ---------------------------------------------------------------------------
combo_t key_combos[] = {

    // — Selección de palabra
    COMBO(sel_word_combo, SELWORD),   // E+T → SELWORD

    // — Símbolos (layer base, mano izquierda)
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
    COMBO(left_acute,         ACUTE_ACC),  // D+R → ´
    COMBO(left_comment,       DEV_COMMENT),// X+D+F → Ctrl+/

    // — Puntuación mano izquierda
    COMBO(left_comma,   KC_COMM),   // S+C → ,
    COMBO(left_dot,     KC_DOT),    // D+V → .
    COMBO(left_semi,    KC_SCLN),   // F+B → ;
    COMBO(left_quote,   KC_QUOT),   // W+R → '

    // — macOS: navegación entre escritorios
    COMBO(mac_desk_right, LGUI(KC_RGHT)),  // Q+D   → Cmd+→ (escritorio derecho)
    COMBO(mac_desk_left,  LGUI(KC_LEFT)),  // A+E   → Cmd+← (escritorio izquierdo)
    COMBO(mac_desk_up,    LGUI(KC_UP)),    // A+W+D → Cmd+↑ (Mission Control)

    // — Control
    COMBO(left_enter,     KC_ENT),
    COMBO(left_bspc,      KC_BSPC),
    COMBO(t_SPC_DEL,      KC_DEL),
    COMBO(n_ENT_spc,      KC_SPC),
    COMBO(caps_combo,     KC_CAPS),       // LSFT+Z+X → CapsLock
    COMBO(app_menu_combo, APP_MENU),      // M+N → KC_APP / Shift+F10

    // — Brackets (apertura)
    COMBO(bracket_combo,     KC_LBRC),
    COMBO(curly_brace_combo, KC_LCBR),
    COMBO(paren_combo,       KC_LPRN),

    // — Brackets (cierre)
    COMBO(bracket_close_combo, KC_RBRC),
    COMBO(curly_close_combo,   KC_RCBR),
    COMBO(paren_close_combo,   KC_RPRN),

    // — Acentos españoles (BSPC = tecla a la derecha de P)
    COMBO(bspc_a_combo, TILDE_A),   // BSPC+A → á/Á
    COMBO(bspc_e_combo, TILDE_E),   // BSPC+E → é/É
    COMBO(bspc_i_combo, TILDE_I),   // BSPC+I → í/Í
    COMBO(bspc_o_combo, TILDE_O),   // BSPC+O → ó/Ó
    COMBO(bspc_u_combo, TILDE_U),   // BSPC+U → ú/Ú
    COMBO(bspc_n_combo, ENIE),      // BSPC+N → ñ/Ñ

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
/*
 * Cambios clave vs. versión anterior:
 *   SFT_SCL(;/Shift) → KC_LSFT  — Shift dedicado: IntelliJ double-Shift funciona nativamente
 *   CTL_CMM(,/Ctrl)  → KC_LCTL  — Ctrl dedicado: 0ms delay en Ctrl+C/V/Z/X
 *   L1_DOT(./Layer1) → MO(1)    — Layer puro: punto pasa a combo X+C y tecla física derecha
 *   WD_LEFT/WD_RGHT  → KC_COMM/KC_DOT — Fila inferior derecha = layout estándar N M , . /
 *   D_END            → KC_SLSH  — D_END solo en Layer 1 (evita accidente con Win+Right)
 */
[0] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     GUI_ESC,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     L2_TAB,    KC_A,      KC_S,      KC_D,      KC_F,      ALT_G,          KC_H,      KC_J,      KC_K,      KC_L,      KC_RCTL,   GUI_QT,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_RALT,   KC_RSFT,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       KC_LCTL,   MO(1),     KC_SPC,        KC_ENT,   MO(1),    L2_PSCR
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 1 — NAV (LEFT) + NÚMEROS (RIGHT)                                     */
/* ========================================================================== */
/*
 * Izquierda: cluster de navegación rediseñado
 *   - Col 0 transparente: TAB/Alt vuelve a funcionar (caída a Layer 0)
 *   - WD_LEFT/WD_RGHT en fila 3, bajo LEFT/RIGHT (alineación vertical intuitiva)
 *   - D_HOME/D_END en fila 1 junto a UP
 *   - PGUP/PGDN en columna exterior derecha
 *
 * Derecha: Numpad (más frecuente que funciones → Layer primario)
 *   - 7-8-9 / 4-5-6 / 1-2-3 alineados en cols 1-2-3
 *   - KC_0 en tercer thumb derecho (L1_PSCR position)
 */
[1] = LAYOUT_split_3x6_3(
  // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
     _______,   D_HOME,    KC_UP,     D_END,     _______,   LLOCK,        LLOCK,   KC_7,      KC_8,      KC_9,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    WIN_SWAP,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   KC_PGUP,        _______,   KC_4,      KC_5,      KC_6,      _______,   _______,
  // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
     _______,   WD_LEFT,   _______,   WD_RGHT,   _______,   KC_PGDN,        KC_LNUM,   KC_1,      KC_2,      KC_3,      _______,   _______,
  // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────╯
                                       _______,   _______,   _______,         _______,   _______,   KC_0
  //                                  ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
),

/* ========================================================================== */
/* LAYER 2 — MOUSE (LEFT) + FUNCIÓN (RIGHT)                                   */
/* ========================================================================== */
/*
 * Izquierda: controles de mouse en diamond ergonómico
 *   - MS_UP en fila top col 2 (W position)
 *   - MS_LEFT/DOWN/RIGHT en fila home cols 1-2-3
 *   - Scroll wheel en cols 4-5 de fila home
 *   - Botones en col 0-1 de fila bot / thumb
 *   - TOG_OS en esquina top-left (Layer 2 necesario para acceder = protección natural)
 *
 * Derecha: Teclas de función (menos frecuentes → Layer secundario)
 *   - F7-F12 en fila top, F1-F6 en fila home
 */
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

// ---------------------------------------------------------------------------
// LED indicator map
//
// Layer 1 (índice 0): Navegación (izquierda BLUE) + Números (derecha RED)
// Layer 2 (índice 1): Mouse (izquierda CYAN) + Función (derecha PURPLE)
//
// Orden de posiciones (42 total): 12 top + 12 home + 12 bot + 6 thumbs
//   Cada fila: [L col0..col5] [R col0..col5]
//   Thumbs:    [L t0 t1 t2]   [R t0 t1 t2]
// ---------------------------------------------------------------------------
const uint8_t PROGMEM ledmap[2][42][3] = {

{   // Layer 1: Navegación (L) + Números (R)
    //
    // top   L: ___   | D_HOME | UP    | D_END  | ___  | ___       top   R: ___  | 7    | 8    | 9    | ___  | ___
    ___off___, ___off___, MG_BLUE, ___off___, ___off___, ___off___,    ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // home  L: ___   | LEFT   | DOWN  | RIGHT  | ___  | PGUP      home  R: ___  | 4    | 5    | 6    | ___  | ___
    ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,      ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // bot   L: ___   | WD_L   | ___   | WD_R   | ___  | PGDN      bot   R: ___  | 1    | 2    | 3    | ___  | ___
    ___off___, ___off___, ___off___, ___off___, ___off___, ___off___,    ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
    // thumb L: ___  | ___  | ___                                   thumb R: ___  | ___  | 0
                               ___off___, ___off___, ___off___,                                ___off___, ___off___, MG_RED
},

{   // Layer 2: Mouse (L) + Función (R)
    //
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

// Desactiva PERMISSIVE_HOLD para mod-taps de home row izquierdo:
// evita que combos rápidos (G+SPC, R+G, etc.) activen Alt o Layer2
// antes de que expire el TAPPING_TERM.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_TAB:
        case ALT_G:
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

// Libera el modificador de WIN_SWAP al salir del layer 1.
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
