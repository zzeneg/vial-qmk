// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

typedef enum {
    _QWERTY = 0,
    _GAME,
    _EU,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC,
    _SYS,
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
#define HOME_P RGUI_T(KC_P)

// bottom mods
#define SYM_SPC LT(_SYMBOL, KC_SPC)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define FUNC_ENT LT(_FUNC, KC_ENT)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define EU_DEL LT(_EU, KC_DEL)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_QUOT LGUI_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *               .---------------------------.                    .---------------------------.
     *               |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |
     * .------+------+------+------+------+------|                    |------+------+------+------+------+------.
     * |  Q   |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   P  |  ;   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  -   |   Z  |   X  |   C  |   V  |   B  |--------.  .--------|   N  |   M  |   ,  |   .  |   /  |  '   |
     * '-----------------------------------------/       /    \       \-----------------------------------------'
     *                         | Esc  | Tab  |  / Space /      \ Enter \  | Bsps | Del  |
     *                         |_FUNC | _NUM | /_SYMBOL/        \ _FUNC \ | _NAV | _EU  |
     *                         `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
                            KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,     KC_O,
        KC_Q,     HOME_A,   HOME_S,  HOME_D,  HOME_F,  KC_G,                KC_H,    HOME_J,  HOME_K,   HOME_L,  HOME_P,   KC_SCLN,
        KC_MINS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_QUOT,
                                   FUNC_ESC,  NUM_TAB,  SYM_SPC,     FUNC_ENT,  NAV_BSPC,  EU_DEL,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_GAME] = LAYOUT(
                            KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,     KC_O,
        LALT_Q,     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,     KC_L,    KC_P,     KC_SCLN,
        LSFT_MINS,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  LGUI_QUOT,
                                    LCTL_ESC,  NUM_TAB,  SYM_SPC,    FUNC_ENT,  NAV_BSPC,  EU_DEL,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                              KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_EU] = LAYOUT(
                               XXXXXXX,     RALT(KC_E),  XXXXXXX,     XXXXXXX,               KC_MUTE,     RALT(KC_U),  XXXXXXX,  RALT(KC_O),
        XXXXXXX,  RALT(KC_A),  RALT(KC_S),  LCTL(KC_C),  KC_LSFT,     XXXXXXX,               XXXXXXX,     KC_RSFT,     XXXXXXX,  RALT(KC_L),  XXXXXXX,  XXXXXXX,
        XXXXXXX,  RALT(KC_Z),  RALT(KC_X),  RALT(KC_C),  LCTL(KC_V),  XXXXXXX,               RALT(KC_N),  XXXXXXX,     XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,
                                                    FUNC_ESC,   NUM_TAB,   SYM_SPC,      XXXXXXX,  XXXXXXX,   _______,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_NAV] = LAYOUT(
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,        XXXXXXX,  KC_PGDN,  KC_PGUP,
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,             LALT(KC_UP),    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PAUS,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             LALT(KC_DOWN),  KC_HOME,  KC_END,   KC_INS,   KC_APP,   XXXXXXX,
                                       FUNC_ESC,   NUM_TAB,   SYM_SPC,     XXXXXXX,  _______,  EU_DEL,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_NUMBER] = LAYOUT(
                           KC_7,    KC_8,    KC_9,    KC_PLUS,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_GRV,   KC_0,    KC_4,    KC_5,    KC_6,    KC_DOT,              XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_BSPC,  KC_AT,   KC_1,    KC_2,    KC_3,    KC_ASTR,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                    KC_ENT,  _______,  TG(_GAME),       FUNC_ENT,  NAV_BSPC,  EU_DEL,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_SYMBOL] = LAYOUT(
                            KC_PERC,  KC_PLUS,  KC_LCBR,  KC_RCBR,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_DLR,   KC_AMPR,  KC_EXLM,  KC_EQL,   KC_LPRN,  KC_RPRN,            XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_BSLS,  KC_PIPE,  KC_HASH,  KC_ASTR,  KC_LBRC,  KC_RBRC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                         MO(_SYS),  KC_BSPC, _______,     FUNC_ENT,  NAV_BSPC,  EU_DEL,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,   KC_F8,   KC_F9,   KC_CAPS,            XXXXXXX,  KC_PSCR,  KC_SCRL,  KC_NUM,
        KC_LCTL,  KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_F12,             XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_CIRC,  KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_TILD,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                         _______, KC_MNXT, KC_MPLY,     _______, XXXXXXX,  MO(_SYS),
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    ),

    [_SYS] = LAYOUT(
                            BL_DOWN,  BL_UP,    BL_TOGG,  XXXXXXX,            XXXXXXX,   RGB_TOG,  RGB_MOD,  RGB_RMOD,
        XXXXXXX,  XXXXXXX,  DT_UP,    DT_DOWN,  DT_PRNT,  XXXXXXX,            XXXXXXX,   RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,
        EH_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EH_RGHT,            EH_RGHT,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  EH_LEFT,
                                            _______, QK_BOOT, _______,     _______, QK_BOOT, _______,
        KC_LEFT,  KC_UP,    KC_RGHT, KC_DOWN, XXXXXXX,                               KC_HOME, KC_PGUP,  KC_END,  KC_PGDN,  XXXXXXX
    )
    // clang-format on
};

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
                // if S is pressed and CTRL is active, and < 140 passed since CTRL was pressed, cancel CTRL and send D instead
                custom_home_row_ctrl(record, 140);
                break;
            case HOME_A:
                // if A is pressed and CTRL is active, and < 180 passed since CTRL was pressed, cancel CTRL and send D instead
                custom_home_row_ctrl(record, 180);
                break;
        }
    }

    return true;
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
