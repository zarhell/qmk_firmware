#include QMK_KEYBOARD_H

#include "features/layer_lock.h"
#include "features/select_word.h"

#define KC_ KC_TRNS

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

  [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.              ,-----------------------------------------------------.
          KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y, KC_U,  KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
            KC_TAB , KC_A,   KC_S,   KC_D,   KC_F,     KC_G,                   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, LGUI_T(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, KC_LALT , KC_SPC,               KC_ENT,   MO(1), MO(2)
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
___off___, MG_BLUE, MG_RED, MG___BLUE, ___off___, ___off___,                      ___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,
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

#define _QWERTY 0
#define _RAISE 2
#define _LOWER 4

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ':', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

enum combos {
    //spanish characters
    ALT_ENYE,
    TILDE_A,
    TILDE_E,
    TILDE_I,
    TILDE_O,
    TILDE_U,

    //Number layer
    F_LALT_LAYER,
    G_LALT_LAYER,

    //Function layer
    H_ENT_LAYER,

    //Number layer
    numDOT,
    numCOMM,
    numCOLN,
    numQUOT,
    numDQUO,

    //Left Keyboard: Basic math symbols
    R_T_EQL,
    F_G_MINS,
    D_F_G_PLUS,
    V_B_UNDS,

    //Right Keyboard: Number layer
    Y_7_EQL,
    H_4_MINS,
    H_4_5_PLUS,
    N_1_UNDS,

    //Left Keyboard Parentheses
    LEFT_BRACKET,
    LEFT_CURLY_BRACE,
    LEFT_PAREN,

    //Left Keyboard Symbols
    LEFT_SLSH,
    LEFT_BSLS,
    LEFT_PIPE,
    LEFT_CIRC,
    LEFT_LOWER_THAN,
    LEFT_GREATHER_THAN,
    LEFT_GRV,
    LEFT_TILD,
    LEFT_HASH,
    LEFT_PERC,
    LEFT_EXLM,
    LEFT_QUES,
    LEFT_DLR,
    LEFT_AT,
    LEFT_AMPR,
    LEFT_ASTR,

    //Symbols on number layer
    numSLSH,
    numBSLS,
    numPIPE,
    numCIRC,
    numLT,
    numGT,
    numGRV,
    numTILD,
    numHASH,
    numPERC,
    numEXLM,
    numQUES,
    numDLR,
    numAT,
    numAMPR,
    numASTR,

    //Control keys
    LEFT_ENT,
    LEFT_BSPC,
    N_ENT_SPC,
    Z_X_LSFT_CAPS,
    T_SPC_DEL,
    DOT_SLSH_RSFT_APP,
    SELECT_WORD,

    //Navigation keys
    GO_HOME,
    GO_END,
    PG_UP,
    PG_DN,

    //Additional media keys
    P_VOLU_MPRV,
    L_VOLD_MNXT,
    RGHT_MPLY_MUTE,

    //Fuction Keys
    FUNC_KEY_1,
    FUNC_KEY_2,
    FUNC_KEY_3,
    FUNC_KEY_4,
    FUNC_KEY_5,
    FUNC_KEY_6,
    FUNC_KEY_7,
    FUNC_KEY_8,
    FUNC_KEY_9,
    FUNC_KEY_10,
    FUNC_KEY_11,
    FUNC_KEY_12,


    //Misc
    P_C_M_R_LCG_SWP,
    M_A_C_LCG_NRM,
    Q_S_C_F_T_RESET,
    Y_J_LEFT_UP_P_RESET,
    ASDF_MAIL,
    GIT_STATUS,
    GIT_COMMIT,
    GIT_PULL,
    GIT_PUSH,
    GIT_LOG,
    GIT_ADD,
    GIT_CHECKOUT,
    GIT_RESTORE,
    GIT_REVERT,
    GIT_STASH,
    PASS_MC,
    USER_MC,

    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
    //spanish letters
    const uint16_t PROGMEM nj_combo[] = {KC_N, KC_J, COMBO_END};
    const uint16_t PROGMEM a_tilde_combo[] = {KC_A, KC_G, COMBO_END};
    const uint16_t PROGMEM e_tilde_combo[] = {KC_E, KC_G, COMBO_END};
    const uint16_t PROGMEM i_tilde_combo[] = {KC_I, KC_H, COMBO_END};
    const uint16_t PROGMEM o_tilde_combo[] = {KC_O, KC_H, COMBO_END};
    const uint16_t PROGMEM u_tilde_combo[] = {KC_U, KC_H, COMBO_END};

    //Number layer
    const uint16_t PROGMEM g_LALT_layer[] = { KC_G, KC_LALT, COMBO_END};
    const uint16_t PROGMEM f_LALT_layer[] = { KC_F, KC_LALT, COMBO_END};

    //Function layer
    const uint16_t PROGMEM h_ENT_layer[] = { KC_H, KC_ENT, COMBO_END};

    //Number layer
    const uint16_t PROGMEM numdot[] = { KC_P2, KC_P3, COMBO_END};
    const uint16_t PROGMEM numcomm[] = { KC_P1, KC_P5, COMBO_END};
    const uint16_t PROGMEM numcoln[] = { KC_H, KC_P4, KC_P6, COMBO_END};
    const uint16_t PROGMEM numquot[] = { KC_P2, KC_P6, COMBO_END};
    const uint16_t PROGMEM numdquo[] = { KC_P1, KC_P6, COMBO_END};

    //Left Keyboard: Basic math symbols
    const uint16_t PROGMEM r_t_eql[] = { KC_R, KC_T, COMBO_END};
    const uint16_t PROGMEM f_g_mins[] = { KC_F, KC_G, COMBO_END};
    const uint16_t PROGMEM d_f_g_plus[] = { KC_D, KC_F, KC_G, COMBO_END};
    const uint16_t PROGMEM v_b_unds[] = { KC_V, KC_B, COMBO_END};

    //Right  Keyboard: Number layer
    const uint16_t PROGMEM y_7_eql[] = { KC_Y, KC_P7, COMBO_END};
    const uint16_t PROGMEM h_4_mins[] = { KC_H, KC_P4, COMBO_END};
    const uint16_t PROGMEM h_4_5_plus[] = { KC_H, KC_P4, KC_P5, COMBO_END};
    const uint16_t PROGMEM n_1_unds[] = { KC_N, KC_P1, COMBO_END};

    //Left Keyboard: Parentheses
    const uint16_t PROGMEM bracket_combo[] = { KC_ESC, KC_Q, COMBO_END};
    const uint16_t PROGMEM curly_brace_combo[] = { KC_ESC, KC_A, COMBO_END};
    const uint16_t PROGMEM paren_combo[] = { KC_ESC, KC_Z, COMBO_END};

    //Left Keyboard Symbols
    const uint16_t PROGMEM left_slsh[] = { KC_X, KC_D, KC_R, COMBO_END};
    const uint16_t PROGMEM left_bsls[] = { KC_W, KC_D, KC_V, COMBO_END};
    const uint16_t PROGMEM left_pipe[] = { KC_E, KC_D, KC_C, COMBO_END};
    const uint16_t PROGMEM left_circ[] = { KC_F, KC_E, KC_S, COMBO_END};
    const uint16_t PROGMEM left_lower_than[] = { KC_E, KC_S, KC_C, COMBO_END};
    const uint16_t PROGMEM left_greather_than[] = { KC_E, KC_F, KC_C, COMBO_END};
    const uint16_t PROGMEM left_grv[] = { KC_R, KC_G, COMBO_END};
    const uint16_t PROGMEM left_tild[] = { KC_Q, KC_F, COMBO_END};
    const uint16_t PROGMEM left_hash[] = { KC_T, KC_R, KC_E, COMBO_END};
    const uint16_t PROGMEM left_perc[] = { KC_W, KC_V, COMBO_END};
    const uint16_t PROGMEM left_exlm[] = { KC_W, KC_E, KC_F, COMBO_END};
    const uint16_t PROGMEM left_ques[] = { KC_S, KC_D, KC_R, COMBO_END};
    const uint16_t PROGMEM left_dlr[] = { KC_X, KC_C, KC_R, COMBO_END};
    const uint16_t PROGMEM left_at[] = { KC_W, KC_D, KC_F, COMBO_END};
    const uint16_t PROGMEM left_ampr[] = { KC_G, KC_D, COMBO_END};
    const uint16_t PROGMEM left_astr[] = { KC_B, KC_V, KC_C, COMBO_END};


    //Symbols on number layer
    const uint16_t PROGMEM numslsh[] = { KC_P1, KC_P5, KC_P9, COMBO_END};
    const uint16_t PROGMEM numbsls[] = { KC_P7, KC_P5, KC_P3, COMBO_END};
    const uint16_t PROGMEM numpipe[] = { KC_P8, KC_P5, KC_P2, COMBO_END};
    const uint16_t PROGMEM numcirc[] = { KC_P4, KC_P8, KC_P6, COMBO_END};
    const uint16_t PROGMEM numlt[] = { KC_P8, KC_P4, KC_COMM, COMBO_END};
    const uint16_t PROGMEM numgt[] = { KC_P8, KC_P6, KC_COMM, COMBO_END};
    const uint16_t PROGMEM numgrv[] = { KC_Y, KC_P4, COMBO_END};
    const uint16_t PROGMEM numtild[] = { KC_P4, KC_P, COMBO_END};
    const uint16_t PROGMEM numhash[] = { KC_Y, KC_P7, KC_P8, COMBO_END};
    const uint16_t PROGMEM numperc[] = { KC_P7, KC_P3, COMBO_END};
    const uint16_t PROGMEM numexlm[] = { KC_P7, KC_P8, KC_P6, COMBO_END};
    const uint16_t PROGMEM numques[] = { KC_P4, KC_P5, KC_P9, COMBO_END};
    const uint16_t PROGMEM numdlr[] = { KC_P1, KC_P2, KC_P9, COMBO_END};
    const uint16_t PROGMEM numat[] = { KC_P7, KC_P5, KC_P6, COMBO_END};
    const uint16_t PROGMEM numampr[] = { KC_H, KC_P5, COMBO_END};
    const uint16_t PROGMEM numastr[] = { KC_N, KC_P1, KC_P2, COMBO_END};

    //Control keys
    const uint16_t PROGMEM left_enter[] = { KC_B, KC_SPC, COMBO_END};
    const uint16_t PROGMEM left_bspc[] = { KC_G, KC_SPC, COMBO_END};
    const uint16_t PROGMEM t_SPC_DEL[] = { KC_T, KC_SPC, COMBO_END};
    const uint16_t PROGMEM n_ENT_spc[] = { KC_N, KC_ENT, COMBO_END};
    const uint16_t PROGMEM z_x_lsft_caps[] = { KC_Z, KC_X, KC_LSFT, COMBO_END};
    const uint16_t PROGMEM dot_slsh_rsft_app[] = { KC_DOT, KC_SLSH, KC_RSFT, COMBO_END};
    const uint16_t PROGMEM select_word[] = { KC_A, KC_T, COMBO_END};

    //Navigation keys
    const uint16_t PROGMEM go_home[] = { KC_Q, KC_W, KC_E, COMBO_END};
    const uint16_t PROGMEM go_end[] = { KC_W, KC_E, KC_R, COMBO_END};
    const uint16_t PROGMEM pg_up[] = { KC_S, KC_G, COMBO_END};
    const uint16_t PROGMEM pg_dn[] = { KC_X, KC_B, COMBO_END};

    //Additional media keys
    const uint16_t PROGMEM p_volu_mprv[] = { KC_V, KC_E, COMBO_END};
    const uint16_t PROGMEM l_vold_mnxt[] = { KC_V, KC_D, COMBO_END};
    const uint16_t PROGMEM rght_mply_mute[] = { KC_V, KC_T, COMBO_END};

    //Function Keys
    const uint16_t PROGMEM func_1[] = { KC_ESC, KC_W, COMBO_END};
    const uint16_t PROGMEM func_2[] = { KC_ESC, KC_E, COMBO_END};
    const uint16_t PROGMEM func_3[] = { KC_ESC, KC_R, COMBO_END};
    const uint16_t PROGMEM func_4[] = { KC_ESC, KC_T, COMBO_END};
    const uint16_t PROGMEM func_5[] = { KC_ESC, KC_S, COMBO_END};
    const uint16_t PROGMEM func_6[] = { KC_ESC, KC_D, COMBO_END};
    const uint16_t PROGMEM func_7[] = { KC_ESC, KC_F, COMBO_END};
    const uint16_t PROGMEM func_8[] = { KC_ESC, KC_G, COMBO_END};
    const uint16_t PROGMEM func_9[] = { KC_ESC, KC_X, COMBO_END};
    const uint16_t PROGMEM func_10[] = { KC_ESC, KC_C, COMBO_END};
    const uint16_t PROGMEM func_11[] = { KC_ESC, KC_V, COMBO_END};
    const uint16_t PROGMEM func_12[] = { KC_ESC, KC_B, COMBO_END};

    //Misc
    const uint16_t PROGMEM p_c_m_r_lcg_swp[] = { KC_P, KC_C, KC_M, KC_R, COMBO_END};
    const uint16_t PROGMEM m_a_c_lcg_nrm[] = { KC_M, KC_A, KC_C, COMBO_END};
    const uint16_t PROGMEM q_s_c_f_t_reset[] = { KC_Q, KC_S, KC_C, KC_F, KC_T, COMBO_END};
    const uint16_t PROGMEM y_j_left_UP_p_reset[] = { KC_Y, KC_J, KC_LEFT, KC_UP, KC_P, COMBO_END};
    const uint16_t PROGMEM mail_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
    const uint16_t PROGMEM git_status_combo[] = {KC_G, KC_T, KC_S, COMBO_END};
    const uint16_t PROGMEM git_commit_combo[] = {KC_G, KC_T, KC_C, COMBO_END};
    const uint16_t PROGMEM git_pull_combo[] = {KC_G, KC_P, KC_L, COMBO_END};
    const uint16_t PROGMEM git_push_combo[] = {KC_G, KC_P, KC_H, COMBO_END};
    const uint16_t PROGMEM git_log_combo[] = {KC_G, KC_T, KC_L, COMBO_END};
    const uint16_t PROGMEM git_add_combo[] = {KC_G, KC_T, KC_A, COMBO_END};
    const uint16_t PROGMEM git_checkout_combo[] = {KC_G, KC_C, KC_K, COMBO_END};
    const uint16_t PROGMEM git_restore_combo[] = {KC_G, KC_R, KC_T, COMBO_END};
    const uint16_t PROGMEM git_revert_combo[] = {KC_G, KC_T, KC_V, COMBO_END};
    const uint16_t PROGMEM git_stash_combo[] = {KC_G, KC_T, KC_H, COMBO_END};
    const uint16_t PROGMEM pass_mc_combo[] = {KC_P, KC_W, COMBO_END};
    const uint16_t PROGMEM user_mc_combo[] = {KC_U, KC_I, KC_D, COMBO_END};


combo_t key_combos[] = {
    //Spanish Characters
    [ALT_ENYE] = COMBO_ACTION(nj_combo),
    [TILDE_A] = COMBO_ACTION(a_tilde_combo),
    [TILDE_E] = COMBO_ACTION(e_tilde_combo),
    [TILDE_I] = COMBO_ACTION(i_tilde_combo),
    [TILDE_O] = COMBO_ACTION(o_tilde_combo),
    [TILDE_U] = COMBO_ACTION(u_tilde_combo),

    //Number layer
    [F_LALT_LAYER] = COMBO(f_LALT_layer, TG(1)),
    [G_LALT_LAYER] = COMBO(g_LALT_layer, TG(2)),


    //Number layer
    [numDOT] = COMBO(numdot, KC_DOT),
    [numCOMM] = COMBO(numcomm, KC_COMM),
    [numCOLN] = COMBO(numcoln, KC_COLN),
    [numQUOT] = COMBO(numquot, KC_QUOT),
    [numDQUO] = COMBO(numdquo, KC_DQUO),

    //Left Keyboard: Basic math symbols
    [R_T_EQL] = COMBO(r_t_eql, KC_EQL),
    [F_G_MINS] = COMBO(f_g_mins, KC_MINS),
    [D_F_G_PLUS] = COMBO(d_f_g_plus, KC_PLUS),
    [V_B_UNDS] = COMBO(v_b_unds, KC_UNDS),

    //Right Keyboard: Number layer
    [Y_7_EQL] = COMBO(y_7_eql, KC_EQL),
    [H_4_MINS] = COMBO(h_4_mins, KC_MINS),
    [H_4_5_PLUS] = COMBO(h_4_5_plus, KC_PLUS),
    [N_1_UNDS] = COMBO(n_1_unds, KC_UNDS),

    //Left Parentheses
    [LEFT_BRACKET] = COMBO_ACTION(bracket_combo),
    [LEFT_CURLY_BRACE] = COMBO_ACTION(curly_brace_combo),
    [LEFT_PAREN] = COMBO_ACTION(paren_combo),

    //Left Keyboard Symbols
    [LEFT_SLSH] = COMBO(left_slsh, KC_SLSH),
    [LEFT_BSLS] = COMBO(left_bsls, KC_BSLS),
    [LEFT_PIPE] = COMBO(left_pipe, KC_PIPE),
    [LEFT_CIRC] = COMBO(left_circ, KC_CIRC),
    [LEFT_LOWER_THAN] = COMBO(left_lower_than, KC_LT),
    [LEFT_GREATHER_THAN] = COMBO(left_greather_than, KC_GT),
    [LEFT_GRV] = COMBO(left_grv, KC_GRV),
    [LEFT_TILD] = COMBO(left_tild, KC_TILD),
    [LEFT_HASH] = COMBO(left_hash, KC_HASH),
    [LEFT_PERC] = COMBO(left_perc, KC_PERC),
    [LEFT_EXLM] = COMBO(left_exlm, KC_EXLM),
    [LEFT_QUES] = COMBO(left_ques, KC_QUES),
    [LEFT_DLR] = COMBO(left_dlr, KC_DLR),
    [LEFT_AT] = COMBO(left_at, KC_AT),
    [LEFT_AMPR] = COMBO(left_ampr, KC_AMPR),
    [LEFT_ASTR] = COMBO(left_astr, KC_ASTR),


    //Symbols on number layer
    [numSLSH] = COMBO(numslsh, KC_SLSH),
    [numBSLS] = COMBO(numbsls, KC_BSLS),
    [numPIPE] = COMBO(numpipe, KC_PIPE),
    [numCIRC] = COMBO(numcirc, KC_CIRC),
    [numLT] = COMBO(numlt, KC_LT),
    [numGT] = COMBO(numgt, KC_GT),
    [numGRV] = COMBO(numgrv, KC_GRV),
    [numTILD] = COMBO(numtild, KC_TILD),
    [numHASH] = COMBO(numhash, KC_HASH),
    [numPERC] = COMBO(numperc, KC_PERC),
    [numEXLM] = COMBO(numexlm, KC_EXLM),
    [numQUES] = COMBO(numques, KC_QUES),
    [numDLR] = COMBO(numdlr, KC_DLR),
    [numAT] = COMBO(numat, KC_AT),
    [numAMPR] = COMBO(numampr, KC_AMPR),
    [numASTR] = COMBO(numastr, KC_ASTR),

    //Control keys
    [LEFT_ENT] = COMBO(left_enter, KC_ENT),
    [LEFT_BSPC] = COMBO(left_bspc, KC_BSPC),
    [N_ENT_SPC] = COMBO(n_ENT_spc, KC_SPC),
    [Z_X_LSFT_CAPS] = COMBO(z_x_lsft_caps, KC_CAPS),
    [T_SPC_DEL] = COMBO(t_SPC_DEL, KC_DEL),
    [DOT_SLSH_RSFT_APP] = COMBO(dot_slsh_rsft_app, KC_APP),
    [SELECT_WORD] = COMBO(select_word, SELWORD),


    //Navigation keys
    [GO_HOME] = COMBO(go_home, KC_HOME),
    [GO_END] = COMBO(go_end, KC_END),
    [PG_UP] = COMBO(pg_up, KC_PGUP),
    [PG_DN] = COMBO(pg_dn, KC_PGDN),

    //Additional media keys
    [P_VOLU_MPRV] = COMBO(p_volu_mprv, KC_MPRV),
    [L_VOLD_MNXT] = COMBO(l_vold_mnxt, KC_MNXT),
    [RGHT_MPLY_MUTE] = COMBO(rght_mply_mute, KC_MUTE),

    //Function Keys
    [FUNC_KEY_1] = COMBO(func_1, KC_F1),
    [FUNC_KEY_2] = COMBO(func_2, KC_F2),
    [FUNC_KEY_3] = COMBO(func_3, KC_F3),
    [FUNC_KEY_4] = COMBO(func_4, KC_F4),
    [FUNC_KEY_5] = COMBO(func_5, KC_F5),
    [FUNC_KEY_6] = COMBO(func_6, KC_F6),
    [FUNC_KEY_7] = COMBO(func_7, KC_F7),
    [FUNC_KEY_8] = COMBO(func_8, KC_F8),
    [FUNC_KEY_9] = COMBO(func_9, KC_F9),
    [FUNC_KEY_10] = COMBO(func_10, KC_F10),
    [FUNC_KEY_11] = COMBO(func_11, KC_F11),
    [FUNC_KEY_12] = COMBO(func_12, KC_F12),

    //Misc
    [ASDF_MAIL] = COMBO_ACTION(mail_combo),
    [GIT_STATUS] = COMBO_ACTION(git_status_combo),
    [GIT_COMMIT] = COMBO_ACTION(git_commit_combo),
    [GIT_PULL] = COMBO_ACTION(git_pull_combo),
    [GIT_PUSH] = COMBO_ACTION(git_push_combo),
    [GIT_LOG] = COMBO_ACTION(git_log_combo),
    [GIT_ADD] = COMBO_ACTION(git_add_combo),
    [GIT_CHECKOUT] = COMBO_ACTION(git_checkout_combo),
    [GIT_RESTORE] = COMBO_ACTION(git_restore_combo),
    [GIT_REVERT] = COMBO_ACTION(git_revert_combo),
    [GIT_STASH] = COMBO_ACTION(git_stash_combo),
    [PASS_MC] = COMBO_ACTION(pass_mc_combo),
    [USER_MC] = COMBO_ACTION(user_mc_combo),
    [P_C_M_R_LCG_SWP] = COMBO(p_c_m_r_lcg_swp, LCG_SWP),
    [M_A_C_LCG_NRM] = COMBO(m_a_c_lcg_nrm, LCG_NRM),
    [Q_S_C_F_T_RESET] = COMBO(q_s_c_f_t_reset, RESET),
    [Y_J_LEFT_UP_P_RESET] = COMBO(y_j_left_UP_p_reset, RESET),
};



void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case TILDE_A:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P5);
                unregister_code(KC_LALT);
            }
            break;
    case TILDE_E:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P3);
                tap_code(KC_P3);
                unregister_code(KC_LALT);
            }
            break;
    case TILDE_I:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P3);
                tap_code(KC_P7);
                unregister_code(KC_LALT);
            }
            break;
    case TILDE_O:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P4);
                tap_code(KC_P3);
                unregister_code(KC_LALT);
            }
            break;
    case TILDE_U:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P0);
                unregister_code(KC_LALT);
            }
            break;
    case ALT_ENYE:
            if (pressed) {
                register_code(KC_LALT);
                tap_code(KC_P1);
                tap_code(KC_P6);
                tap_code(KC_P4);
                unregister_code(KC_LALT);
            }
            break;
    case ASDF_MAIL:
            if (pressed) {
                SEND_STRING("johan.zubieta@gmail.com");
            }
            break;
    case GIT_STATUS:
            if (pressed) {
                SEND_STRING("git status");
            }
            break;
    case GIT_COMMIT:
            if (pressed) {
                SEND_STRING("git commit -m ");
            }
            break;
    case GIT_PULL:
            if (pressed) {
                SEND_STRING("git pull");
            }
            break;
    case GIT_PUSH:
            if (pressed) {
                SEND_STRING("git push");
            }
            break;
    case GIT_LOG:
            if (pressed) {
                SEND_STRING("git log -");
            }
            break;
    case GIT_ADD:
            if (pressed) {
                SEND_STRING("git add ");
            }
            break;
    case GIT_CHECKOUT:
            if (pressed) {
                SEND_STRING("git checkout ");
            }
            break;
    case GIT_RESTORE:
            if (pressed) {
                SEND_STRING("git restore ");
            }
            break;
    case GIT_REVERT:
            if (pressed) {
                SEND_STRING("git revert ");
            }
            break;
    case GIT_STASH:
            if (pressed) {
                SEND_STRING("git stash ");
            }
            break;
    case PASS_MC:
            if (pressed) {
                SEND_STRING("Colombia234*");
            }
            break;
    case USER_MC:
            if (pressed) {
                SEND_STRING("johan.zubietam@globant.com");
            }
            break;
    case LEFT_BRACKET:
            if (pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            break;
    case LEFT_CURLY_BRACE:
            if (pressed) {
                SEND_STRING("{}");
                tap_code(KC_LEFT);
            }
            break;
    case LEFT_PAREN:
            if (pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;
  }
}


void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;


void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // (180, 255, 231) is purple
    rgb_matrix_mode_noeeprom(1);

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


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
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
#endif // OLED_ENABLE
