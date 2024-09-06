// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "v2.h"
#include "hid_display.h"
#include "raw_hid.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *        .-----------------------------------------.
     *        | Enter|   1  |   2  |   3  |   4  |   5  |
     *        |------+------+------+------+------+------|
     *        | Tab  |   Q  |   W  |   E  |   R  |   T  |
     * .------+------+------+------+------+------+------|
     * |  =   | Shift|   A  |   S  |   D  |   F  |   G  |
     * |------+------+------+------+------+------+------|
     * |  -   | Ctrl |   Z  |   X  |   C  |   V  |   B  |
     * '------------------------------------------------|
     *      F1   F2   F3    | Enter| MO(2)|  Alt | Space|
     *                      '---------------------------'
     */
    // clang-format off
    [0] = LAYOUT(
                  KC_ENT,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
                  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
        KC_EQL,   KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_MINS,  KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
        KC_F1,    KC_F2,    KC_F3,    KC_ESC,   MO(2),    KC_LALT,  KC_SPC
    ),

    [1] = LAYOUT(
                  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  KC_UP,    _______,  _______,  _______,
        _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),

    [2] = LAYOUT(
                  KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                  KC_CAPS,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        TG(1),    KC_LSFT,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
        OSL(3),   KC_LCTL,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
        KC_F5,    KC_F9,    KC_F12,   KC_MPRV,  MO(2),    KC_MNXT,  KC_MPLY
    ),

    [3] = LAYOUT(
                  KC_BSPC,  KC_INS,   KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_PGUP,
                  KC_DEL,   KC_F7,    KC_F8,    KC_F9,    KC_F11,   KC_PGDN,
        KC_BSLS,  KC_LSFT,  KC_F4,    KC_F5,    KC_F6,    KC_F12,   KC_HOME,
        KC_QUOT,  KC_LCTL,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_END,
        RGB_TOG,  BL_TOGG,  QK_BOOT,  KC_LBRC,  MO(2),    KC_LALT,  KC_RBRC
    ),
    // clang-format on
};

/* Active Layer processing */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    }

    return state;
}

/* Raw HID processing*/
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    dprintf("raw_hid_receive - received %u bytes \n", length);

    if (is_display_enabled()) {
        display_process_raw_hid_data(data, length);
    }
}
