#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

// --- Declaración de combos (COMBO_ACTION requiere visibilidad de los arrays) ---
extern const uint16_t PROGMEM tilde_a_combo[];
extern const uint16_t PROGMEM tilde_e_combo[];
extern const uint16_t PROGMEM tilde_i_combo[];
extern const uint16_t PROGMEM tilde_o_combo[];
extern const uint16_t PROGMEM tilde_u_combo[];
extern const uint16_t PROGMEM tilde_n_combo[];
extern const uint16_t PROGMEM enie_combo[];
extern const uint16_t PROGMEM exclam_combo[];
extern const uint16_t PROGMEM question_combo[];

// --- Definición de índice ↔ combo ---
#define COMBOS_SPANISH \
    [TILDE_A]   = COMBO_ACTION(tilde_a_combo), \
    [TILDE_E]   = COMBO_ACTION(tilde_e_combo), \
    [TILDE_I]   = COMBO_ACTION(tilde_i_combo), \
    [TILDE_O]   = COMBO_ACTION(tilde_o_combo), \
    [TILDE_U]   = COMBO_ACTION(tilde_u_combo), \
    [TILDE_N]   = COMBO_ACTION(tilde_n_combo), \
    [ENIE]      = COMBO_ACTION(enie_combo),    \
    [EXCLAM]    = COMBO_ACTION(exclam_combo),  \
    [QUESTION]  = COMBO_ACTION(question_combo)
