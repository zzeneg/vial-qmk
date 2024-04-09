/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format offefs

#include QMK_KEYBOARD_H

// Default keymap. This can be changed in Vial.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .-----------------------------------------.
     * |  Esc |  `   |   1  |   2  |   3  |   4  |
     * |------+------+------+------+------+------|
     * |   5  | Tab  |   Q  |   W  |   E  |   R  |
     * |------+------+------+------+------+------|
     * |   6  | Shift|   A  |   S  |   D  |   F  |
     * |------+------+------+------+------+------+------|
     * |   7  | Ctrl |   Z  |   X  |   C  |   V  |      |
     * '------------------------------------------------|
     *               |   -  | Enter| MO(1)|  Alt | Space|
     *               '----------------------------------'
     *  Left, Down, Up, Right
     */
    // clang-format off
    [0] = LAYOUT(
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
        KC_6,    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,
        KC_7,    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,
        KC_8,    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_SCLN,
                           KC_ENT,  KC_ESC,  MO(1),   KC_LALT,  KC_SPC
    ),

    [1] = LAYOUT(
        KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F6,    KC_F7,
        KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,
        KC_G,    _______,  KC_H,    KC_J,    KC_K,     KC_L,
        KC_B,    _______,  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                           QK_BOOT, KC_BSPC, _______,  KC_DEL,  KC_SPC
    ),
    // clang-format on
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  }
    // clang-format on
};
#endif // ENCODER_MAP_ENABLE
