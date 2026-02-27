#pragma once

#include "quantum.h"

extern bool is_mac;  // true = macOS, false = Windows (toggle con TOG_OS)

bool handle_keycode(uint16_t keycode, keyrecord_t* record);