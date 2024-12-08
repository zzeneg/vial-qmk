// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* common SPI/I2C config */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_SCK_PAL_MODE 0
#define SPI_MISO_PIN B4
#define SPI_MISO_PAL_MODE 0
#define SPI_MOSI_PIN B5
#define SPI_MOSI_PAL_MODE 0

/* common LCD config */
#define LCD_DC_PIN A0
#define LCD_CS_PIN A2
#define LCD_RST_PIN A8 // any unused pin
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
