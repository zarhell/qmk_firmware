#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

// --- Declaración de combos ---
extern const uint16_t PROGMEM media_play_pause_combo[];
extern const uint16_t PROGMEM media_vol_up_combo[];
extern const uint16_t PROGMEM media_vol_down_combo[];
extern const uint16_t PROGMEM media_mute_combo[];
extern const uint16_t PROGMEM media_next_combo[];
extern const uint16_t PROGMEM media_prev_combo[];

// --- Definición del macro de combos multimedia ---
#define COMBOS_MEDIA \
    [MEDIA_PLAY_PAUSE]  = COMBO(media_play_pause_combo, KC_MEDIA_PLAY_PAUSE), \
    [MEDIA_VOL_UP]      = COMBO(media_vol_up_combo, KC_AUDIO_VOL_UP), \
    [MEDIA_VOL_DOWN]    = COMBO(media_vol_down_combo, KC_AUDIO_VOL_DOWN), \
    [MEDIA_MUTE]        = COMBO(media_mute_combo, KC_AUDIO_MUTE), \
    [MEDIA_NEXT_TRACK]  = COMBO(media_next_combo, KC_MEDIA_NEXT_TRACK), \
    [MEDIA_PREV_TRACK]  = COMBO(media_prev_combo, KC_MEDIA_PREV_TRACK)
