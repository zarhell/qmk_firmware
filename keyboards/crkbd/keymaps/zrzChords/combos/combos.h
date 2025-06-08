#pragma once

#include "quantum.h"


extern combo_t key_combos[];
uint16_t get_combo_len(void);

#define COMBO_LEN (sizeof(key_combos) / sizeof(combo_t))

void process_combo_event(uint16_t combo_index, bool pressed);
void define_key_combos(void);
