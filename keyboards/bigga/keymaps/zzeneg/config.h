// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID { 0xF6, 0xFA, 0xD8, 0x61, 0xDE, 0xD5, 0x4A, 0x87 }

/* VIAL secure unlock keystroke - currently both big keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS { 3, 6 }
#define VIAL_UNLOCK_COMBO_COLS { 5, 5 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0

#define TAP_CODE_DELAY 25

#define CAPS_WORD_IDLE_TIMEOUT 2500
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
