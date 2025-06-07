#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

// --- Declaración de combos usados con COMBO_ACTION ---
extern const uint16_t PROGMEM bracket_combo[];
extern const uint16_t PROGMEM curly_brace_combo[];
extern const uint16_t PROGMEM paren_combo[];

// --- Declaración de combos usados con COMBO ---
extern const uint16_t PROGMEM left_slsh[];
extern const uint16_t PROGMEM left_bsls[];
extern const uint16_t PROGMEM left_pipe[];
extern const uint16_t PROGMEM left_circ[];
extern const uint16_t PROGMEM left_lower_than[];
extern const uint16_t PROGMEM left_greather_than[];
extern const uint16_t PROGMEM left_grv[];
extern const uint16_t PROGMEM left_tild[];
extern const uint16_t PROGMEM left_hash[];
extern const uint16_t PROGMEM left_perc[];
extern const uint16_t PROGMEM left_exlm[];
extern const uint16_t PROGMEM left_ques[];
extern const uint16_t PROGMEM left_dlr[];
extern const uint16_t PROGMEM left_at[];
extern const uint16_t PROGMEM left_ampr[];
extern const uint16_t PROGMEM left_astr[];

extern const uint16_t PROGMEM numslsh[];
extern const uint16_t PROGMEM numbsls[];
extern const uint16_t PROGMEM numpipe[];
extern const uint16_t PROGMEM numcirc[];
extern const uint16_t PROGMEM numlt[];
extern const uint16_t PROGMEM numgt[];
extern const uint16_t PROGMEM numgrv[];
extern const uint16_t PROGMEM numtild[];
extern const uint16_t PROGMEM numhash[];
extern const uint16_t PROGMEM numperc[];
extern const uint16_t PROGMEM numexlm[];
extern const uint16_t PROGMEM numques[];
extern const uint16_t PROGMEM numdlr[];
extern const uint16_t PROGMEM numat[];
extern const uint16_t PROGMEM numampr[];
extern const uint16_t PROGMEM numastr[];

// --- Combo definition macro ---
#define COMBOS_SYMBOLS \
    [LEFT_BRACKET] = COMBO_ACTION(bracket_combo), \
    [LEFT_CURLY_BRACE] = COMBO_ACTION(curly_brace_combo), \
    [LEFT_PAREN] = COMBO_ACTION(paren_combo), \
    [LEFT_SLSH] = COMBO(left_slsh, KC_SLSH), \
    [LEFT_BSLS] = COMBO(left_bsls, KC_BSLS), \
    [LEFT_PIPE] = COMBO(left_pipe, KC_PIPE), \
    [LEFT_CIRC] = COMBO(left_circ, KC_CIRC), \
    [LEFT_LOWER_THAN] = COMBO(left_lower_than, KC_LT), \
    [LEFT_GREATHER_THAN] = COMBO(left_greather_than, KC_GT), \
    [LEFT_GRV] = COMBO(left_grv, KC_GRV), \
    [LEFT_TILD] = COMBO(left_tild, KC_TILD), \
    [LEFT_HASH] = COMBO(left_hash, KC_HASH), \
    [LEFT_PERC] = COMBO(left_perc, KC_PERC), \
    [LEFT_EXLM] = COMBO(left_exlm, KC_EXLM), \
    [LEFT_QUES] = COMBO(left_ques, KC_QUES), \
    [LEFT_DLR] = COMBO(left_dlr, KC_DLR), \
    [LEFT_AT] = COMBO(left_at, KC_AT), \
    [LEFT_AMPR] = COMBO(left_ampr, KC_AMPR), \
    [LEFT_ASTR] = COMBO(left_astr, KC_ASTR), \
    [numSLSH] = COMBO(numslsh, KC_SLSH), \
    [numBSLS] = COMBO(numbsls, KC_BSLS), \
    [numPIPE] = COMBO(numpipe, KC_PIPE), \
    [numCIRC] = COMBO(numcirc, KC_CIRC), \
    [numLT] = COMBO(numlt, KC_LT), \
    [numGT] = COMBO(numgt, KC_GT), \
    [numGRV] = COMBO(numgrv, KC_GRV), \
    [numTILD] = COMBO(numtild, KC_TILD), \
    [numHASH] = COMBO(numhash, KC_HASH), \
    [numPERC] = COMBO(numperc, KC_PERC), \
    [numEXLM] = COMBO(numexlm, KC_EXLM), \
    [numQUES] = COMBO(numques, KC_QUES), \
    [numDLR] = COMBO(numdlr, KC_DLR), \
    [numAT] = COMBO(numat, KC_AT), \
    [numAMPR] = COMBO(numampr, KC_AMPR), \
    [numASTR] = COMBO(numastr, KC_ASTR)
