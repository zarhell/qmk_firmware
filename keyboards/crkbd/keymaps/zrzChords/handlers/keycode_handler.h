#pragma once

#include "quantum.h"

extern bool is_mac;

bool handle_keycode(uint16_t keycode, keyrecord_t* record);
void win_swap_cancel(void);
