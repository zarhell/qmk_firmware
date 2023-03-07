/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y, KC_U,  KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
    KC_TAB , KC_A,   KC_S,   KC_D,   KC_F,     KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, LGUI_T(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------+--------|
    LSFT_T(KC_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RSFT_T(KC_APP),
        //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, KC_LALT , KC_SPC,               KC_ENT,  KC_SPC, MO(1)
                                       //`--------------------------'                   `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                       ,-----------------------------------------------------.
      TO(0), KC_HOME, KC_UP, KC_END, _______, KC_NUM,                              _______,    KC_P7,    KC_P8,    KC_P9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                       _______,    KC_P4,    KC_P5,    KC_P6, _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, KC_PGDN, KC_PGUP,                          _______,    KC_P1,    KC_P2,    KC_P3,  _______, LLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|         |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,         KC_PENT, KC_P0, _______
                                      //`--------------------------'          `--------------------------'
  ),


  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TO(0),   KC_1, KC_2, KC_3,  _______, KC_NUM,                              _______, _______,   KC_HOME, KC_UP, KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_4, KC_5, KC_6, _______, _______,                             _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_7, KC_8, KC_9, _______, _______,                                 KC_PGUP, KC_PGDN, _______, _______, _______, LLOCK,
  //|--------+--------+--------+--------+--------+-------+--------|        |--------+--------+--------+--------+--------+--------+--------|
                                          KC_0, _______, _______,          _______, _______, _______
                                      //`--------------------------'          `--------------------------'
  ),


  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
      TO(0),_______,_______,_______,_______,_______,                                    _______,  KC_F1,KC_F2,KC_F3,KC_F4, _______,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      _______,KC_PSCR,_______,_______,KC_PAUSE,_______,                                  _______,KC_F5,KC_F6,KC_F7,KC_F8,_______,
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
      _______,KC_INT1,KC_INT2,KC_MPRV,KC_MNXT,KC_MPLY,                               _______ ,KC_F9,KC_F10,KC_F11,KC_F12,LLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                          SELWORD, KC_ENT,  KC_BSPC,                KC_INS, KC_CAPS, _______
                                      //`--------------------------'                           `--------------------------'
  )
};

const uint8_t PROGMEM ledmap[][42][3] = {

[0] = {
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
MG_RED, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE,                       MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_RED,
                                         MG_RED, MG_RED, MG_RED,                MG_RED, MG_RED, MG_RED
      },

[1] = {
MG_CYAN, MG_BLUE, MG_RED, MG_BLUE, ___off___, MG_RED,                               ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,
___off___, MG_RED, MG_RED, MG_RED, ___off___, ___off___,                            ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,
___off___, ___off___, ___off___, ___off___, MG_RED, MG_RED,                         ___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, MG_GREEN,
                                 ___off___, ___off___, ___off___,               MG_RED, MG_BLUE, ___off___
      },

[2] = {
MG_CYAN, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, MG_RED,                        ___off___, ___off___, MG_BLUE, MG_RED, MG_BLUE, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                   ___off___, ___off___,MG_RED, MG_RED, MG_RED, ___off___,
___off___, MG_BLUE, MG_BLUE, MG_BLUE, ___off___, ___off___,                 MG_RED, MG_RED, ___off___, ___off___, ___off___, MG_GREEN,
                                 MG_BLUE, ___off___, ___off___,         ___off___, ___off___, ___off___
      },


[3] = {
___off___, ___off___, ___off___, ___off___, ___off___, ___off___,               ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,
___off___, MG_RED, ___off___, ___off___, MG_RED, ___off___,                     ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, ___off___,
___off___, MG_RED, MG_RED, MG_RED, MG_RED, MG_RED,                              ___off___, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_PURPLE, MG_GREEN,
                                     MG_RED, MG_RED, MG_RED,            MG_RED, MG_RED, ___off___
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
#define _FUNKEY 8

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
        case _FUNKEY:
        case _FUNKEY|_LOWER:
        case _FUNKEY|_RAISE:
        case _FUNKEY|_LOWER|_RAISE:
            oled_write_ln_P(PSTR("Funkey"), false);
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
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

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
    //Number layer
    G_LALT_LAYER,
    H_SPC_LAYER,

    //Function layer
    Q_W_LAYER,

    //Number layer
    numDOT,
    numCOMM,
    numCOLN,
    numSCLN,
    numQUOT,
    numDQUO,

    //Basic math symbols
    Y_U_EQL,
    H_J_MINS,
    H_J_K_PLUS,
    N_M_UNDS,

    //Number layer
    Y_7_EQL,
    H_4_MINS,
    H_4_5_PLUS,
    N_1_UNDS,

    //Parentheses
    BSPC_U_LBRC,
    BSPC_I_RBRC,
    BSPC_J_LPRN,
    BSPC_K_RPRN,
    BSPC_M_LCBR,
    BSPC_COMM_RCBR,
    //Number layer
    BSPC_7_LBRC,
    BSPC_8_RBRC,
    BSPC_4_LPRN,
    BSPC_5_RPRN,
    BSPC_1_LCBR,
    BSPC_2_RCBR,

    //Symbols
    M_K_O_SLSH,
    U_K_DOT_BSLS,
    I_J_SPC_PIPE,
    J_I_L_CIRC,
    I_J_DEL_LT,
    U_K_ENT_GT,
    Y_J_GRV,
    J_P_TILD,
    Y_U_I_HASH,
    U_DOT_PERC,
    U_I_L_EXLM,
    J_K_O_QUES,
    M_COMM_O_DLR,
    U_K_L_AT,
    H_K_AMPR,
    N_M_COMM_ASTR,

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
    K_L_ENT,
    numENT,
    J_K_TAB,

    //Navigation keys
    U_I_O_HOME,
    I_O_P_END,
    H_L_PGUP,
    N_DOT_PGDN,
    SPC_DEL_INS,

    //Additional media keys
    P_VOLU_MPRV,
    L_VOLD_MNXT,
    RGHT_MPLY_MUTE,

    //Mouse keys
    M_COMM_BTN1,
    M_DOT_BTN2,
    M_COMM_DOT_BTN3,
    J_SCLN_WH_U,
    M_SLSH_WH_D,
    M_SCLN_WH_L,
    J_SLSH_WH_R,

    //Misc
    P_C_M_R_LCG_SWP,
    M_A_C_LCG_NRM,
    Q_S_C_F_T_RESET,
    Y_J_LEFT_UP_P_RESET,
    Q_W_E_R_T_NK_TOGG,
    ASDF_LOREM,
    GIT_STATUS,
    GIT_COMMIT,
    GIT_PULL,
    GIT_PUSH,
    GIT_LOG,
    GIT_ADD,
    GIT_CHECKOUT,
    PASS_MC,
    USER_MC,


    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;
    //Number layer
    const uint16_t PROGMEM g_LALT_layer[] = { KC_G, KC_LALT, COMBO_END};
    const uint16_t PROGMEM h_SPC_layer[] = { KC_H, KC_SPC, COMBO_END};

    //Function layer
    const uint16_t PROGMEM q_w_layer[] = { KC_Q, KC_W, COMBO_END};

    //Number layer
    const uint16_t PROGMEM numdot[] = { KC_6, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM numcomm[] = { KC_5, KC_6, COMBO_END};
    const uint16_t PROGMEM numcoln[] = { KC_4, KC_6, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM numscln[] = { KC_4, KC_5, KC_6, COMBO_END};
    const uint16_t PROGMEM numquot[] = { KC_2, KC_6, COMBO_END};
    const uint16_t PROGMEM numdquo[] = { KC_1, KC_6, COMBO_END};

    //Basic math symbols
    const uint16_t PROGMEM y_u_eql[] = { KC_Y, KC_U, COMBO_END};
    const uint16_t PROGMEM h_j_mins[] = { KC_H, KC_J, COMBO_END};
    const uint16_t PROGMEM h_j_k_plus[] = { KC_H, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM n_m_unds[] = { KC_N, KC_M, COMBO_END};
    //Number layer
    const uint16_t PROGMEM y_7_eql[] = { KC_Y, KC_7, COMBO_END};
    const uint16_t PROGMEM h_4_mins[] = { KC_H, KC_4, COMBO_END};
    const uint16_t PROGMEM h_4_5_plus[] = { KC_H, KC_4, KC_5, COMBO_END};
    const uint16_t PROGMEM n_1_unds[] = { KC_N, KC_1, COMBO_END};

    //Parentheses
    const uint16_t PROGMEM bspc_u_lbrc[] = { KC_BSPC, KC_U, COMBO_END};
    const uint16_t PROGMEM bspc_i_rbrc[] = { KC_BSPC, KC_I, COMBO_END};
    const uint16_t PROGMEM bspc_j_lprn[] = { KC_BSPC, KC_J, COMBO_END};
    const uint16_t PROGMEM bspc_k_rprn[] = { KC_BSPC, KC_K, COMBO_END};
    const uint16_t PROGMEM bspc_m_lcbr[] = { KC_BSPC, KC_M, COMBO_END};
    const uint16_t PROGMEM bspc_COMM_rcbr[] = { KC_BSPC, KC_COMM, COMBO_END};
    //Number layer
    const uint16_t PROGMEM bspc_7_lbrc[] = { KC_BSPC, KC_7, COMBO_END};
    const uint16_t PROGMEM bspc_8_rbrc[] = { KC_BSPC, KC_8, COMBO_END};
    const uint16_t PROGMEM bspc_4_lprn[] = { KC_BSPC, KC_4, COMBO_END};
    const uint16_t PROGMEM bspc_5_rprn[] = { KC_BSPC, KC_5, COMBO_END};
    const uint16_t PROGMEM bspc_1_lcbr[] = { KC_BSPC, KC_1, COMBO_END};
    const uint16_t PROGMEM bspc_2_rcbr[] = { KC_BSPC, KC_2, COMBO_END};

    //Symbols
    const uint16_t PROGMEM m_k_o_slsh[] = { KC_M, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM u_k_DOT_bsls[] = { KC_U, KC_K, KC_DOT, COMBO_END};
    const uint16_t PROGMEM i_j_spc_pipe[] = { KC_I, KC_J, KC_SPC, COMBO_END};
    const uint16_t PROGMEM j_i_l_circ[] = { KC_J, KC_I, KC_L, COMBO_END};
    const uint16_t PROGMEM i_j_del_lt[] = { KC_I, KC_J, KC_DEL, COMBO_END};
    const uint16_t PROGMEM u_k_ent_gt[] = { KC_U, KC_K, KC_ENT, COMBO_END};
    const uint16_t PROGMEM y_j_grv[] = { KC_Y, KC_J, COMBO_END};
    const uint16_t PROGMEM j_p_tild[] = { KC_J, KC_P, COMBO_END};
    const uint16_t PROGMEM y_u_i_hash[] = { KC_Y, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM u_dot_perc[] = { KC_U, KC_DOT, COMBO_END};
    const uint16_t PROGMEM u_i_l_exlm[] = { KC_U, KC_I, KC_L, COMBO_END};
    const uint16_t PROGMEM j_k_o_ques[] = { KC_J, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM m_comm_o_dlr[] = { KC_M, KC_COMM, KC_O, COMBO_END};
    const uint16_t PROGMEM u_k_l_at[] = { KC_U, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM h_k_ampr[] = { KC_H, KC_K, COMBO_END};
    const uint16_t PROGMEM n_m_comm_astr[] = { KC_N, KC_M, KC_COMM, COMBO_END};
    //Symbols on number layer
    const uint16_t PROGMEM numslsh[] = { KC_P1, KC_P5, KC_P9, COMBO_END};
    const uint16_t PROGMEM numbsls[] = { KC_P7, KC_P5, KC_P3, COMBO_END};
    const uint16_t PROGMEM numpipe[] = { KC_P7, KC_P4, KC_P0, COMBO_END};
    const uint16_t PROGMEM numcirc[] = { KC_P4, KC_P8, KC_P6, COMBO_END};
    const uint16_t PROGMEM numlt[] = { KC_P8, KC_P4, KC_DEL, COMBO_END};
    const uint16_t PROGMEM numgt[] = { KC_7, KC_P5, KC_BSPC, COMBO_END};
    const uint16_t PROGMEM numgrv[] = { KC_Y, KC_P4, COMBO_END};
    const uint16_t PROGMEM numtild[] = { KC_P4, KC_P, COMBO_END};
    const uint16_t PROGMEM numhash[] = { KC_Y, KC_P7, KC_P8, COMBO_END};
    const uint16_t PROGMEM numperc[] = { KC_P7, KC_3, COMBO_END};
    const uint16_t PROGMEM numexlm[] = { KC_P7, KC_P8, KC_P6, COMBO_END};
    const uint16_t PROGMEM numques[] = { KC_P4, KC_P5, KC_P9, COMBO_END};
    const uint16_t PROGMEM numdlr[] = { KC_P1, KC_P2, KC_P9, COMBO_END};
    const uint16_t PROGMEM numat[] = { KC_P7, KC_P5, KC_P6, COMBO_END};
    const uint16_t PROGMEM numampr[] = { KC_H, KC_P5, COMBO_END};
    const uint16_t PROGMEM numastr[] = { KC_N, KC_P1, KC_P2, COMBO_END};

    //Control keys
    const uint16_t PROGMEM k_L_ent[] = { KC_K, KC_L, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM nument[] = { KC_5, KC_6, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM j_k_tab[] = { KC_J, KC_K, COMBO_END};

    //Navigation keys
    const uint16_t PROGMEM u_i_o_home[] = { KC_U, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM i_o_p_end[] = { KC_I, KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM h_l_pgup[] = { KC_H, KC_L, COMBO_END};
    const uint16_t PROGMEM n_dot_pgdn[] = { KC_N, KC_DOT, COMBO_END};
    const uint16_t PROGMEM spc_del_ins[] = { KC_SPC, KC_DEL, COMBO_END};

    //Additional media keys
    const uint16_t PROGMEM p_volu_mprv[] = { KC_F, KC_G, COMBO_END};
    const uint16_t PROGMEM l_vold_mnxt[] = { KC_V, KC_B, COMBO_END};
    const uint16_t PROGMEM rght_mply_mute[] = { KC_B, KC_T, COMBO_END};

    //Mouse keys
    const uint16_t PROGMEM m_comm_btn1[] = { KC_M, KC_COMM, COMBO_END};
    const uint16_t PROGMEM m_dot_btn2[] = { KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM m_comm_dot_btn3[] = { KC_M, KC_DOT, KC_COMM, COMBO_END};
    const uint16_t PROGMEM j_SCLN_wh_u[] = { KC_J, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM m_SLSH_wh_d[] = { KC_M, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM m_SCLN_wh_l[] = { KC_M, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM j_SLSH_wh_r[] = { KC_J, KC_SLSH, COMBO_END};

    //Misc
    const uint16_t PROGMEM p_c_m_r_lcg_swp[] = { KC_P, KC_C, KC_M, KC_R, COMBO_END};
    const uint16_t PROGMEM m_a_c_lcg_nrm[] = { KC_M, KC_A, KC_C, COMBO_END};
    const uint16_t PROGMEM q_s_c_f_t_reset[] = { KC_Q, KC_S, KC_C, KC_F, KC_T, COMBO_END};
    const uint16_t PROGMEM y_j_left_UP_p_reset[] = { KC_Y, KC_J, KC_LEFT, KC_UP, KC_P, COMBO_END};
    const uint16_t PROGMEM q_w_e_r_t_nk_togg[] = { KC_Q, KC_W, KC_E, KC_R, KC_T, COMBO_END};
    const uint16_t PROGMEM lorem_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
    const uint16_t PROGMEM git_status_combo[] = {KC_G, KC_S, COMBO_END};
    const uint16_t PROGMEM git_commit_combo[] = {KC_G, KC_C, COMBO_END};
    const uint16_t PROGMEM git_pull_combo[] = {KC_G, KC_P, KC_L, COMBO_END};
    const uint16_t PROGMEM git_push_combo[] = {KC_G, KC_P, KC_H, COMBO_END};
    const uint16_t PROGMEM git_log_combo[] = {KC_G, KC_L, COMBO_END};
    const uint16_t PROGMEM git_add_combo[] = {KC_G, KC_A, COMBO_END};
    const uint16_t PROGMEM git_checkout_combo[] = {KC_G, KC_C, KC_K, COMBO_END};
    const uint16_t PROGMEM pass_mc_combo[] = {KC_P, KC_W, COMBO_END};
    const uint16_t PROGMEM user_mc_combo[] = {KC_U, KC_I, KC_D, COMBO_END};


combo_t key_combos[] = {
    //Number layer
    [H_SPC_LAYER] = COMBO(h_SPC_layer, TT(1)),
    [G_LALT_LAYER] = COMBO(g_LALT_layer, TT(2)),

    //Function layer
    [Q_W_LAYER] = COMBO(q_w_layer, TT(3)),

    //Number layer
    [numDOT] = COMBO(numdot, KC_DOT),
    [numCOMM] = COMBO(numcomm, KC_COMM),
    [numCOLN] = COMBO(numcoln, KC_COLN),
    [numSCLN] = COMBO(numscln, KC_SCLN),
    [numQUOT] = COMBO(numquot, KC_QUOT),
    [numDQUO] = COMBO(numdquo, KC_DQUO),

    //Basic math symbols
    [Y_U_EQL] = COMBO(y_u_eql, KC_EQL),
    [H_J_MINS] = COMBO(h_j_mins, KC_MINS),
    [H_J_K_PLUS] = COMBO(h_j_k_plus, KC_PLUS),
    [N_M_UNDS] = COMBO(n_m_unds, KC_UNDS),
    //Number layer
    [Y_7_EQL] = COMBO(y_7_eql, KC_EQL),
    [H_4_MINS] = COMBO(h_4_mins, KC_MINS),
    [H_4_5_PLUS] = COMBO(h_4_5_plus, KC_PLUS),
    [N_1_UNDS] = COMBO(n_1_unds, KC_UNDS),

    //Parentheses
    [BSPC_U_LBRC] = COMBO(bspc_u_lbrc, KC_LBRC),
    [BSPC_I_RBRC] = COMBO(bspc_i_rbrc, KC_RBRC),
    [BSPC_J_LPRN] = COMBO(bspc_j_lprn, KC_LPRN),
    [BSPC_K_RPRN] = COMBO(bspc_k_rprn, KC_RPRN),
    [BSPC_M_LCBR] = COMBO(bspc_m_lcbr, KC_LCBR),
    [BSPC_COMM_RCBR] = COMBO(bspc_COMM_rcbr, KC_RCBR),
    //Number layer
    [BSPC_7_LBRC] = COMBO(bspc_7_lbrc, KC_LBRC),
    [BSPC_8_RBRC] = COMBO(bspc_8_rbrc, KC_RBRC),
    [BSPC_4_LPRN] = COMBO(bspc_4_lprn, KC_LPRN),
    [BSPC_5_RPRN] = COMBO(bspc_5_rprn, KC_RPRN),
    [BSPC_1_LCBR] = COMBO(bspc_1_lcbr, KC_LCBR),
    [BSPC_2_RCBR] = COMBO(bspc_2_rcbr, KC_RCBR),

    //Symbols
    [M_K_O_SLSH] = COMBO(m_k_o_slsh, KC_SLSH),
    [U_K_DOT_BSLS] = COMBO(u_k_DOT_bsls, KC_BSLS),
    [I_J_SPC_PIPE] = COMBO(i_j_spc_pipe, KC_PIPE),
    [J_I_L_CIRC] = COMBO(j_i_l_circ, KC_CIRC),
    [I_J_DEL_LT] = COMBO(i_j_del_lt, KC_LT),
    [U_K_ENT_GT] = COMBO(u_k_ent_gt, KC_GT),
    [Y_J_GRV] = COMBO(y_j_grv, KC_GRV),
    [J_P_TILD] = COMBO(j_p_tild, KC_TILD),
    [Y_U_I_HASH] = COMBO(y_u_i_hash, KC_HASH),
    [U_DOT_PERC] = COMBO(u_dot_perc, KC_PERC),
    [U_I_L_EXLM] = COMBO(u_i_l_exlm, KC_EXLM),
    [J_K_O_QUES] = COMBO(j_k_o_ques, KC_QUES),
    [M_COMM_O_DLR] = COMBO(m_comm_o_dlr, KC_DLR),
    [U_K_L_AT] = COMBO(u_k_l_at, KC_AT),
    [H_K_AMPR] = COMBO(h_k_ampr, KC_AMPR),
    [N_M_COMM_ASTR] = COMBO(n_m_comm_astr, KC_ASTR),
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
    [K_L_ENT] = COMBO(k_L_ent, KC_ENT),
    [numENT] = COMBO(nument, KC_ENT),
    [J_K_TAB] = COMBO(j_k_tab, KC_TAB),

    //Navigation keys
    [U_I_O_HOME] = COMBO(u_i_o_home, KC_HOME),
    [I_O_P_END] = COMBO(i_o_p_end, KC_END),
    [H_L_PGUP] = COMBO(h_l_pgup, KC_PGUP),
    [N_DOT_PGDN] = COMBO(n_dot_pgdn, KC_PGDN),
    [SPC_DEL_INS] = COMBO(spc_del_ins, KC_INS),

    //Additional media keys
    [P_VOLU_MPRV] = COMBO(p_volu_mprv, KC_MPRV),
    [L_VOLD_MNXT] = COMBO(l_vold_mnxt, KC_MNXT),
    [RGHT_MPLY_MUTE] = COMBO(rght_mply_mute, KC_MUTE),

    //Mouse keys
    [M_COMM_BTN1] = COMBO(m_comm_btn1, KC_BTN1),
    [M_DOT_BTN2] = COMBO(m_dot_btn2, KC_BTN2),
    [M_COMM_DOT_BTN3] = COMBO(m_comm_dot_btn3, KC_BTN3),
    [J_SCLN_WH_U] = COMBO(j_SCLN_wh_u, KC_WH_U),
    [M_SLSH_WH_D] = COMBO(m_SLSH_wh_d, KC_WH_D),
    [M_SCLN_WH_L] = COMBO(m_SCLN_wh_l, KC_WH_L),
    [J_SLSH_WH_R] = COMBO(j_SLSH_wh_r, KC_WH_R),

    //Misc
    [ASDF_LOREM] = COMBO_ACTION(lorem_combo),
    [GIT_STATUS] = COMBO_ACTION(git_status_combo),
    [GIT_COMMIT] = COMBO_ACTION(git_commit_combo),
    [GIT_PULL] = COMBO_ACTION(git_pull_combo),
    [GIT_PUSH] = COMBO_ACTION(git_push_combo),
    [GIT_LOG] = COMBO_ACTION(git_log_combo),
    [GIT_ADD] = COMBO_ACTION(git_add_combo),
    [GIT_CHECKOUT] = COMBO_ACTION(git_checkout_combo),
    [PASS_MC] = COMBO_ACTION(pass_mc_combo),
    [USER_MC] = COMBO_ACTION(user_mc_combo),
    [P_C_M_R_LCG_SWP] = COMBO(p_c_m_r_lcg_swp, LCG_SWP),
    [M_A_C_LCG_NRM] = COMBO(m_a_c_lcg_nrm, LCG_NRM),
    [Q_S_C_F_T_RESET] = COMBO(q_s_c_f_t_reset, RESET),
    [Y_J_LEFT_UP_P_RESET] = COMBO(y_j_left_UP_p_reset, RESET),
    [Q_W_E_R_T_NK_TOGG] = COMBO(q_w_e_r_t_nk_togg, NK_TOGG),
};



void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ASDF_LOREM:
            if (pressed) {
                SEND_STRING("Lorem ipsum dolor sit amet ");
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

    case PASS_MC:
            if (pressed) {
                SEND_STRING("Colombia1222*");
            }
            break;

    case USER_MC:
            if (pressed) {
                SEND_STRING("E138208");
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
    // if (layerNum == 0) {
    //     return;
    // }

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
