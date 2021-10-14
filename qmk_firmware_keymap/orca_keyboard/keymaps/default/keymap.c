/* Copyright 2021 GVSolgryn
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
#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    test
};

/*  Base
 * ,---------------------------------------.
 * |ESC|F1 |F2 |F3 |▓▓▓|▓▓▓|F4 |F5 |NK |RST|
 * |---------------------------------------|
 * | A | S | D | F |▓▓▓|▓▓▓| J | K | L | ; |
 * |---------------------------------------|
 * |▓▓▓|▓▓▓| E | R |▓▓▓|▓▓▓| U | I |▓▓▓|▓▓▓|
 * `---------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3,        KC_F4, KC_F5, NK_ON, RESET,
        KC_A,   KC_S,  KC_D,  KC_F,         KC_J,  KC_K,  KC_L, test,
                       KC_E,  KC_R,         KC_U,  KC_I
    )/*,
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,  _______,
            RESET,    XXXXXXX
    )*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time);
    #endif

    switch(keycode){
        case test:
            if (record->event.pressed)
            {
                #ifdef CONSOLE_ENABLE
                    print("LED\n");
                #endif
            }
            else
            {

            }
            break;
    }
    return true;
}
