// Copyright 2021 Nicolas Druoton (druotoni)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// layer name : must be 3 chars
#define LAYER_NAME_0 "ABC"
#define LAYER_NAME_1 "SYM"
#define LAYER_NAME_2 "NUM"
#define LAYER_NAME_3 "CUR"
#define LAYER_NAME_4 "EDT"
#define LAYER_NAME_5 "GAM"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _NUMPAD,
  _CURSOR,
  _EDIT,
  _GAME
};
void render_gears(void);
void render_layer_frame(gui_state_t t);
void update_layer_frame(layer_state_t state);