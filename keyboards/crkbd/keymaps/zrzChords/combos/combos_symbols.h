#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

// --- Apertura de brackets (ESC + fila)
extern const uint16_t PROGMEM bracket_combo[];
extern const uint16_t PROGMEM curly_brace_combo[];
extern const uint16_t PROGMEM paren_combo[];

// --- Cierre de brackets (pares horizontales Q+W / A+S / Z+X)
extern const uint16_t PROGMEM bracket_close_combo[];
extern const uint16_t PROGMEM curly_close_combo[];
extern const uint16_t PROGMEM paren_close_combo[];

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

extern const uint16_t PROGMEM left_eq[];
extern const uint16_t PROGMEM left_min[];
extern const uint16_t PROGMEM left_unds[];
extern const uint16_t PROGMEM left_plus[];
