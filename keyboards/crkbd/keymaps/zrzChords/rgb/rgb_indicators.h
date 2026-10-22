#pragma once
#include <stdint.h>
#include <stdbool.h>

// Palette indices used by the ledmap in keymap.c (colors live in rgb_indicators.c)
enum led_color { C_OFF, C_CYAN, C_RED, C_BLUE, C_PURPLE, C_WHITE };

void rgb_lock_sync_init(void);
void rgb_lock_sync_task(void);
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max);
