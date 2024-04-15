// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    // clang-format off
    _QWERTY = 0,
    _EU,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC
    // clang-format on
};

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
#define SYM_SPC LT(_SYMBOL, KC_SPC)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define EU_DEL LT(_EU, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .----------------------------------.                    ,----------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
     * .------+------+------+------+------|                    |------+------+------+------+------.
     * |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------|                    |------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  |________.  .________|   N  |   M  |   ,  |   .  |   /  |
     * `----------------------------------/       /    \       \----------------------------------'
     *                  | Esc  | Tab  |  / Space /      \  OSM  \  | Bsps | Del  |
     *                  |_FUNC | _NUM | /_SYMBOL/        \ Shift \ | _NAV | _EU |
     *                  `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN,
        HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_P,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                        FUNC_ESC,  NUM_TAB,  SYM_SPC,      OSM(MOD_LSFT),  NAV_BSPC,  EU_DEL, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    ),

    [_EU] = LAYOUT(
        XXXXXXX,     XXXXXXX,     RALT(KC_E),  XXXXXXX,  XXXXXXX,             XXXXXXX,     RALT(KC_U),  XXXXXXX,  RALT(KC_O),  XXXXXXX,
        RALT(KC_A),  RALT(KC_S),  KC_MINS,     KC_LSFT,  XXXXXXX,             XXXXXXX,     KC_RSFT,     KC_QUOT,  RALT(KC_L),  XXXXXXX,
        RALT(KC_Z),  RALT(KC_X),  RALT(KC_C),  XXXXXXX,  XXXXXXX,             RALT(KC_N),  XXXXXXX,     XXXXXXX,  XXXXXXX,     XXXXXXX,
                                      _______,   _______,   _______,      _______,  _______,   _______, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX,  DT_UP,    DT_DOWN,  DT_PRNT,  XXXXXXX,             KC_BSPC,        KC_CAPS,  KC_PGDN,  KC_PGUP,  KC_PAUS,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,             LALT(KC_UP),    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             LALT(KC_DOWN),  KC_HOME,  KC_END,   KC_INS,   KC_APP,
                             _______,   _______,   _______,      QK_BOOT,  _______,  _______, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    ),

    [_NUMBER] = LAYOUT(
        KC_LCTL,  KC_7,   KC_8,   KC_9,   KC_PLUS,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_0,     KC_4,   KC_5,   KC_6,   KC_DOT,              XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_ENT,   KC_1,   KC_2,   KC_3,   KC_COMM,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                         _______,  _______,  QK_BOOT,      _______,  KC_ENT,  _______, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    ),

    [_SYMBOL] = LAYOUT(
        KC_PIPE,  KC_PERC,  KC_ASTR,  KC_LCBR,  KC_RCBR,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_DLR,   KC_EXLM,  KC_AMPR,  KC_LPRN,  KC_RPRN,            XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_CIRC,  KC_HASH,  KC_AT,    KC_LBRC,  KC_RBRC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                               _______,  KC_BSPC,  _______,      KC_ENT,  KC_BSPC,  KC_DEL, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    ),

    [_FUNC] = LAYOUT(
        KC_LCTL,  KC_F7,   KC_F8,   KC_F9,   KC_BSLS,            RGB_TOG,  RGB_M_P,  RGB_RMOD,  RGB_MOD,  RGB_SPI,
        KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_F12,             RGB_M_R,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_TILD,            RGB_M_SW,  RGB_M_B,  RGB_HUI,  RGB_SAI,  RGB_VAI,
                               _______,  KC_MNXT,  KC_MPLY,     _______,  _______,  _______, XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  XXXXXXX
    )
    // clang-format on
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    // different tapping term for different fingers
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
            return 170;
        // index
        case HOME_F:
        case HOME_J:
            return 140;
        // thumb
        default:
            return TAPPING_TERM;
    }
}

#ifdef CAPS_WORD_ENABLE

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

#endif // CAPS_WORD_ENABLE

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_EU] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_NUMBER] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_SYMBOL] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FUNC] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}
    // clang-format on
};
#endif // ENCODER_MAP_ENABLE

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

const rgblight_segment_t PROGMEM        capslock_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_ORANGE});
const rgblight_segment_t PROGMEM        capslockword_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_MAGENTA});
const rgblight_segment_t* const PROGMEM rgb_layers[]         = RGBLIGHT_LAYERS_LIST(capslock_layer, capslockword_layer);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(2, active);
}

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
