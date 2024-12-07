// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <lv_conf.h>

/*
Custom fonts:
    - montserrat_20_en_ru - english/cyrillic symbols, range 0x20-0x7E,0x0410-0x044F,0x0401,0x0451, 3bpp,compressed
    - montserrat_48_digits - digits, dot and colon only, range 0x2E,0x30-0x3A, 3bpp, compressed

Ranges from https://www.utf8-chartable.de/unicode-utf8-table.pl
 */

#undef LV_FONT_CUSTOM_DECLARE
#define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(montserrat_20_en_ru) LV_FONT_DECLARE(montserrat_48_digits)

#undef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &montserrat_20_en_ru

#undef LV_DRAW_COMPLEX
#define LV_DRAW_COMPLEX 1

#undef LV_USE_ARC
#define LV_USE_ARC 1
