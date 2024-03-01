// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID { 0xF6, 0xFA, 0xD8, 0x61, 0xDE, 0xD5, 0x4A, 0x85 }

/* VIAL secure unlock keystroke - currently both inner thumb keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS { 3, 7 }
#define VIAL_UNLOCK_COMBO_COLS { 4, 4 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

#define AZOTEQ_IQS5XX_TPS43
#define AZOTEQ_IQS5XX_ROTATION_90
