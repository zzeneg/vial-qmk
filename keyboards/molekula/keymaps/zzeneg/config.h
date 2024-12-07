// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID { 0xF6, 0xFA, 0xD8, 0x61, 0xDE, 0xD5, 0x4A, 0x88 }

/* VIAL secure unlock keystroke - currently both middle thumb keys */
#define VIAL_UNLOCK_COMBO_ROWS { 3, 7 }
#define VIAL_UNLOCK_COMBO_COLS { 4, 4 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0

#define TAP_CODE_DELAY 10

#define CAPS_WORD_IDLE_TIMEOUT 2500
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
