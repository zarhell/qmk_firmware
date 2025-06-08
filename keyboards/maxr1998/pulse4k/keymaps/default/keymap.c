/*
 * Copyright (C) 2019-2020  Maxr1998 <max.rumpf1998@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    DEFAULT
};

enum combo_events {
    LED_ADJUST
};

const uint16_t PROGMEM led_adjust_combo[] = {KC_LEFT, KC_RGHT, COMBO_END};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT(
        KC_END,  KC_UP,   KC_MUTE,
        KC_LEFT, KC_DOWN, KC_RGHT
    )
};

combo_t key_combos[] = {
    [LED_ADJUST] = COMBO_ACTION(led_adjust_combo)
};

bool led_adjust_active = false;

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    // Ejemplos: solo los que requieren lógica (COMBO_ACTION simulada)
    if (combo_index == 0) SEND_STRING(SS_RALT("a"));  // tilde_a_combo
    else if (combo_index == 1) SEND_STRING(SS_RALT("e"));
    else if (combo_index == 2) SEND_STRING(SS_RALT("i"));
    else if (combo_index == 3) SEND_STRING(SS_RALT("o"));
    else if (combo_index == 4) SEND_STRING(SS_RALT("u"));
    else if (combo_index == 5) SEND_STRING(SS_RALT("n"));
    else if (combo_index == 6) SEND_STRING(SS_LALT("0241")); // Ñ
    else if (combo_index == 7) SEND_STRING(SS_RALT("1"));     // ¡
    else if (combo_index == 8) SEND_STRING(SS_RALT("/"));     // ¿
    else if (combo_index == 9) SEND_STRING("johan.zubieta@gmail.com");
    else if (combo_index == 10) SEND_STRING("johan.zubieta@globant.com");
    else if (combo_index == 11) SEND_STRING("jzubieta");
    else if (combo_index == 12) SEND_STRING("Colombia234*");
    else if (combo_index == 13) SEND_STRING("git status");
    else if (combo_index == 14) SEND_STRING("git commit -m \"\"");
    else if (combo_index == 15) SEND_STRING("git pull");
    else if (combo_index == 16) SEND_STRING("git push");
    else if (combo_index == 17) SEND_STRING("git log");
    else if (combo_index == 18) SEND_STRING("git add .");
    else if (combo_index == 19) SEND_STRING("git checkout ");
    else if (combo_index == 20) SEND_STRING("git restore ");
    else if (combo_index == 21) SEND_STRING("git revert ");
    else if (combo_index == 22) SEND_STRING("git stash");
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (led_adjust_active) {
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
            return false;
        }
    } else if (index == 1) {
        if (led_adjust_active) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
            return false;
        }
    }

    return true;
}
