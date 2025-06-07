#pragma once

#include "quantum.h"

void process_combo_event(uint16_t combo_index, bool pressed);
void define_key_combos(void);

extern combo_t* key_combos_ptr;
