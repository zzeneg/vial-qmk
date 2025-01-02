// Copyright 2024 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "hid_display.h"
#include "display.h"
#include "raw_hid.h"

typedef enum {
    // clang-format off
    _QWERTY = 0,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC
    // clang-format on
} layer_number;

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// bottom mods
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define NUM_SPC LT(_NUMBER, KC_SPC)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define RA_DEL RALT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *               .---------------------------.                        ,---------------------------.
     *               |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |
     * .-------------+------+------+------+------|                        |------+------+------+------+-------------.
     * |   Q  |   A  |   S  |   D  |   F  |   G  |                        |   H  |   J  |   K  |   L  |   ;  |  P   |
     * `------+------+------+------+------+------|                        |------+------+------+------+------+------'
     *        |   Z  |   X  |   C  |   V  |   B  |                        |   N  |   M  |   ,  |   .  |   /  |
     *        `----------------------------------+ .-------.    .-------. +----------------------------------'
     *                           | Esc  | Space|  /  Tab  /      \ Enter \  | Bsps | Del  |
     *                           |_FUNC | _NUM | /_SYMBOL/        \       \ | _NAV | RAlt |
     *                           `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
                            KC_W,     KC_E,     KC_R,     KC_T,                KC_Y,     KC_U,     KC_I,     KC_O,
        KC_Q,     HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,                KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN, KC_P,
                  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                        FUNC_ESC,  NUM_SPC,  SYM_TAB,      KC_ENT,  NAV_BSPC,  RA_DEL
    ),

    [_NAV] = LAYOUT(
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  KC_INS,   KC_PGDN,  KC_PGUP,
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_CAPS,             XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  XXXXXXX,
                                       _______,   _______,   _______,      _______,  _______,  _______
    ),

    [_NUMBER] = LAYOUT(
                            KC_7,     KC_8,     KC_9,     XXXXXXX,             XXXXXXX,  XXXXXXX,  KC_QUOT,  KC_GRV,
        XXXXXXX,  KC_0,     KC_4,     KC_5,     KC_6,     KC_LBRC,             KC_RBRC,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,             XXXXXXX,  KC_MINS,  KC_EQL,   KC_BSLS,  XXXXXXX,
                                         _______,  _______,  _______,      _______,  _______,  _______
    ),

    [_SYMBOL] = LAYOUT(
                            KC_AMPR,  KC_ASTR,  KC_LPRN,  XXXXXXX,             XXXXXXX,  XXXXXXX,  KC_DQUO,  KC_TILD,
        XXXXXXX,  KC_RPRN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_LCBR,             KC_RCBR,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  XXXXXXX,             XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_PIPE,  XXXXXXX,
                                        _______,  _______,  _______,      _______,  _______,  _______
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,    KC_F8,    KC_F9,    KC_F10,              BL_UP,    KC_PSCR,  KC_SCRL,  KC_PAUS,
        XXXXXXX,  KC_LCTL,  KC_F4,    KC_F5,    KC_F6,    KC_F11,              BL_TOGG,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F12,              BL_DOWN,  KC_CAPS,  KC_NUM,   XXXXXXX,  XXXXXXX,
                                        _______,  KC_MNXT,  KC_MPLY,      _______,  _______,  _______
    ),
    // clang-format on
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_NUMBER] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_SYMBOL] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FUNC] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}
    // clang-format on
};
#endif // ENCODER_MAP_ENABLE

/* Caps Word processing */
#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    if (is_display_enabled()) {
        display_process_caps(active);
    }
}
#endif

/* Active Layer processing */
static void display_process_layer(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
            display_set_layer("QWERTY");
            break;
        case _NAV:
            display_set_layer("NAV");
            break;
        case _NUMBER:
            display_set_layer("NUMBER");
            break;
        case _SYMBOL:
            display_set_layer("SYMBOL");
            break;
        case _FUNC:
            display_set_layer("FUNC");
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer(get_highest_layer(state));
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

void keyboard_post_init_user(void) {
    if (is_display_enabled()) {
        display_process_layer(0);
    }
}
