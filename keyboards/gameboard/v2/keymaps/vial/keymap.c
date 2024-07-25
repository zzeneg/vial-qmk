// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *        .-----------------------------------------.
     *        |  Esc |   1  |   2  |   3  |   4  |   5  |
     * .------+------+------+------+------+------+------|
     * |  F1  |  Tab |   Q  |   W  |   E  |   R  |   T  |
     * |------+------+------+------+------+------+------|
     * |  F5  | Shift|   A  |   S  |   D  |   F  |   G  |
     * |------+------+------+------+------+------+------|
     * |  F12 | Ctrl |   Z  |   X  |   C  |   V  |   B  |
     * '------------------------------------------------|
     *     -      -      -  | Enter| MO(1)|  Alt | Space|
     *                      '---------------------------'
     *  Left, Down, Up, Right
     */
    // clang-format off
    [0] = LAYOUT(
                  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,
                  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,
        KC_EQL,   KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,
        KC_MINS,  KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,
        KC_F5,    KC_F9,    KC_PSCR,  KC_ENT,   MO(1),    KC_LALT,   KC_SPC
    ),

    [1] = LAYOUT(
                  KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,      KC_0,
                  KC_TAB,   KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,
        KC_F1,    _______,  KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,
        KC_F2,    _______,  KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,
        KC_F3,    KC_F4,    QK_BOOT,  KC_BSPC,  _______,  KC_DEL,    KC_SPC
    ),
    // clang-format on
};
