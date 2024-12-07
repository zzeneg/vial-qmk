// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* reset config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* common SPI/I2C config */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_MISO_PIN B4
#define SPI_MOSI_PIN B5

/* common LCD config */
#define LCD_DC_PIN A0
#define LCD_CS_PIN A2
#define LCD_RST_PIN A8 // any unused pin
#define BACKLIGHT_PWM_DRIVER PWMD2
#define BACKLIGHT_PWM_CHANNEL 2
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
