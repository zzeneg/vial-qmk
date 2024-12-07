// Copyright 2024 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "zzeneg_display.h"
#include "display.h"
#include "raw_hid.h"

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_P RGUI_T(KC_P)

// bottom mods
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define NUM_SPC LT(_NUMBER, KC_SPC)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define EU_DEL LT(_EU, KC_DEL)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_ENT LSFT_T(KC_ENT)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_SCLN LGUI_T(KC_SCLN)

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
        KC_Q,     HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,                KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_P,   KC_SCLN,
                  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                        FUNC_ESC,  NUM_SPC,  SYM_TAB,     KC_ENT,  NAV_BSPC,  EU_DEL
    ),

    [_EU] = LAYOUT(
                               _______,     RALT(KC_E),  _______,  _______,               _______,     RALT(KC_U),  _______,  RALT(KC_O),
        _______,  RALT(KC_A),  RALT(KC_S),  _______,     KC_LSFT,  _______,               _______,     KC_RSFT,     _______,  RALT(KC_L),  _______,  _______,
                  RALT(KC_Z),  RALT(KC_X),  RALT(KC_C),  _______,  _______,               RALT(KC_N),  _______,     _______,  _______,     _______,
                                                  _______,   _______,   _______,      _______,  _______,   _______
    ),

    [_NAV] = LAYOUT(
                            C(KC_Z),  C(KC_Y),    C(KC_GRV),   XXXXXXX,             XXXXXXX,     KC_INS,   KC_PGDN,  KC_PGUP,
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,    KC_LSFT,     XXXXXXX,             A(KC_UP),    KC_LEFT,  KC_DOWN,  KC_UP,     KC_RGHT,  XXXXXXX,
                  XXXXXXX,  XXXXXXX,  S(KC_END),  S(KC_HOME),  XXXXXXX,             A(KC_DOWN),  KC_HOME,  KC_END,   XXXXXXX,   XXXXXXX,
                                            _______,   _______,   _______,       _______,  _______,  _______
    ),

    [_NUMBER] = LAYOUT(
                            KC_7,     KC_8,     KC_9,     KC_COMM,             XXXXXXX,  KC_TILD,  KC_UNDS,  KC_DQUO,
        XXXXXXX,  KC_0,     KC_4,     KC_5,     KC_6,     KC_DOT,              XXXXXXX,  KC_GRV,   KC_MINS,  KC_QUOT,  XXXXXXX,  XXXXXXX,
                  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_BSPC,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                        KC_ENT,   _______,  _______,       _______,  _______,  _______
    ),

    [_SYMBOL] = LAYOUT(
                            KC_PERC,  KC_PLUS,  KC_LCBR,  XXXXXXX,             XXXXXXX,  KC_RCBR,  KC_AT,    KC_DLR,
        XXXXXXX,  KC_BSLS,  KC_EXLM,  KC_EQL,   KC_LPRN,  KC_MINS,             XXXXXXX,  KC_RPRN,  KC_PIPE,  KC_AMPR,   KC_HASH,  XXXXXXX,
                  XXXXXXX,  XXXXXXX,  KC_ASTR,  KC_LBRC,  KC_DEL,              XXXXXXX,  KC_RBRC,  KC_CIRC,  XXXXXXX,  XXXXXXX,
                                        _______,  _______,  _______,      _______,  _______,  _______
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,    KC_F8,    KC_F9,    KC_F11,              BL_UP,    KC_PSCR,  KC_SCRL,  KC_PAUS,
        XXXXXXX,  KC_LCTL,  KC_F4,    KC_F5,    KC_F6,    KC_F12,              BL_TOGG,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F10,              BL_DOWN,  KC_CAPS,  KC_NUM,   XXXXXXX,  XXXXXXX,
                                        _______,  KC_MNXT,  KC_MPLY,      _______,  _______,  _______
    ),

    [_GAME] = LAYOUT(
                            KC_W,     KC_E,     KC_R,     KC_T,                KC_Y,     KC_U,     KC_I,     KC_O,
        LALT_Q,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     LGUI_SCLN,
                  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                        LCTL_ESC,  NUM_SPC,  SYM_TAB,    LSFT_ENT,  NAV_BSPC,  EU_DEL
    ),
    // clang-format on
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_EU] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_NAV] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_NUMBER] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_SYMBOL] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FUNC] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_GAME] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}
    // clang-format on
};
#endif // ENCODER_MAP_ENABLE

/* different tapping term for different fingers */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // pinkies
        case HOME_A:
        case HOME_P:
            return 250;
        // ring
        case HOME_S:
        case HOME_L:
            return 200;
        // middle
        case HOME_D:
        case HOME_K:
            return 160;
        // index
        case HOME_F:
        case HOME_J:
            return 140;
        // thumb and game
        default:
            return TAPPING_TERM;
    }
}

/* helper function for custom increased tapping term for home row CTRL + other keys */
uint16_t HOME_CTRL_pressed_time = 0;
void     custom_home_row_ctrl(keyrecord_t *record, uint16_t time) {
    if (record->tap.count && get_mods() & MOD_MASK_CTRL) {
        if (TIMER_DIFF_16(record->event.time, HOME_CTRL_pressed_time) < time) {
            del_mods(MOD_MASK_CTRL);
            tap_code(KC_D);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("process_record_user %u %s %s %d\n", keycode, record->event.pressed ? "pressed" : "depressed", record->tap.interrupted ? "interrupted" : "not interrupted", record->tap.count);

    if (record->event.pressed) {
        switch (keycode) {
            // custom increased tapping term for home row CTRL + other keys
            case HOME_D:
                // save time when CTRL from D key is pressed
                if (!record->tap.count) {
                    HOME_CTRL_pressed_time = record->event.time;
                }
                break;
            case HOME_S:
                // if S is pressed and CTRL is active, and < 150 passed since CTRL was pressed, cancel CTRL and send D instead
                custom_home_row_ctrl(record, 150);
                break;
            case HOME_A:
                // if A is pressed and CTRL is active, and < 180 passed since CTRL was pressed, cancel CTRL and send D instead
                custom_home_row_ctrl(record, 180);
                break;
        }
    }

    return true;
}

/* Active Layer processing */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    }

    return state;
}

/* Caps Word processing */
void caps_word_set_user(bool active) {
    if (is_display_enabled()) {
        display_process_caps(active);
    }
}

/* default caps word logic that allows KC_MINS. Underscore can be typed with KC_RSFT + KC_MINS */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_RSFT:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

/* Raw HID processing*/
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    dprintf("raw_hid_receive - received %u bytes \n", length);

    if (is_display_enabled()) {
        display_process_raw_hid_data(data, length);
    }
}
