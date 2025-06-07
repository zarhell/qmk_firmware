#pragma once

#include "quantum.h"

void oled_render_layer_state(void);
void oled_render_keylog(void);
void oled_render_logo(void);
void render_bootmagic_status(bool status);
bool oled_task_user(void);
