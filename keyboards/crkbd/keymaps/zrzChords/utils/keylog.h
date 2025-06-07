#pragma once

#include "quantum.h"

void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *get_keylog_str(void);
