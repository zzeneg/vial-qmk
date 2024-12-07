// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* disable default features to reduce size */

#include_next <lv_conf.h>

/* Custom fonts:
    - montserrat_20_en - basic latin symbols, range 0x20-0x7E, compressed
 */
#undef LV_FONT_CUSTOM_DECLARE
#define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(montserrat_20_en)

/* change default font */
#undef LV_USE_FONT_COMPRESSED
#define LV_USE_FONT_COMPRESSED 1

#undef LV_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 0

#undef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &montserrat_20_en

/* features */
#undef LV_DRAW_COMPLEX
#define LV_DRAW_COMPLEX 0

/* enable/disable widgets*/
#undef LV_USE_ARC
#define LV_USE_ARC 0
#undef LV_USE_ANIMIMG
#define LV_USE_ANIMIMG 0
#undef LV_USE_BAR
#define LV_USE_BAR 0
#undef LV_USE_BTN
#define LV_USE_BTN 0
#undef LV_USE_BTNMATRIX
#define LV_USE_BTNMATRIX 0
#undef LV_USE_CANVAS
#define LV_USE_CANVAS 0
#undef LV_USE_CHECKBOX
#define LV_USE_CHECKBOX 0
#undef LV_USE_DROPDOWN
#define LV_USE_DROPDOWN 0 /*Requires: lv_label*/
#undef LV_USE_IMG
#define LV_USE_IMG 0 /*Requires: lv_label*/
#undef LV_USE_LABEL
#define LV_USE_LABEL 1
#if LV_USE_LABEL
#    undef LV_LABEL_TEXT_SELECTION
#    define LV_LABEL_TEXT_SELECTION 0 /*Enable selecting text of the label*/
#    undef LV_LABEL_LONG_TXT_HINT
#    define LV_LABEL_LONG_TXT_HINT 0 /*Store some extra info in labels to speed up drawing of very long texts*/
#endif
#undef LV_USE_LINE
#define LV_USE_LINE 0
#undef LV_USE_ROLLER
#define LV_USE_ROLLER 0 /*Requires: lv_label*/
#undef LV_USE_SLIDER
#define LV_USE_SLIDER 0 /*Requires: lv_label*/
#undef LV_USE_SWITCH
#define LV_USE_SWITCH 0
#undef LV_USE_TEXTAREA
#define LV_USE_TEXTAREA 0 /*Requires: lv_label*/
#undef LV_USE_TABLE
#define LV_USE_TABLE 0

/* disable extra components */

#undef LV_USE_CALENDAR
#define LV_USE_CALENDAR 0
#undef LV_USE_CALENDAR_HEADER_ARROW
#define LV_USE_CALENDAR_HEADER_ARROW 0
#undef LV_USE_CALENDAR_HEADER_DROPDOWN
#define LV_USE_CALENDAR_HEADER_DROPDOWN 0
#undef LV_USE_CHART
#define LV_USE_CHART 0
#undef LV_USE_COLORWHEEL
#define LV_USE_COLORWHEEL 0
#undef LV_USE_IMGBTN
#define LV_USE_IMGBTN 0
#undef LV_USE_KEYBOARD
#define LV_USE_KEYBOARD 0
#undef LV_USE_LED
#define LV_USE_LED 0
#undef LV_USE_LIST
#define LV_USE_LIST 0
#undef LV_USE_MENU
#define LV_USE_MENU 0
#undef LV_USE_METER
#define LV_USE_METER 0
#undef LV_USE_MSGBOX
#define LV_USE_MSGBOX 0
#undef LV_USE_SPINBOX
#define LV_USE_SPINBOX 0
#undef LV_USE_SPINNER
#define LV_USE_SPINNER 0
#undef LV_USE_TABVIEW
#define LV_USE_TABVIEW 0
#undef LV_USE_TILEVIEW
#define LV_USE_TILEVIEW 0
#undef LV_USE_WIN
#define LV_USE_WIN 0
#if LV_USE_SPAN
#    undef LV_USE_SPAN
#    define LV_USE_SPAN 0
#endif

/* disable themes */
#undef LV_USE_THEME_DEFAULT
#define LV_USE_THEME_DEFAULT 0
#undef LV_THEME_DEFAULT_GROW
#define LV_THEME_DEFAULT_GROW 0
#undef LV_USE_THEME_BASIC
#define LV_USE_THEME_BASIC 0
#undef LV_USE_THEME_MONO
#define LV_USE_THEME_MONO 0

/* disable layouts */
#undef LV_USE_FLEX
#define LV_USE_FLEX 1
#undef LV_USE_GRID
#define LV_USE_GRID 0

/* disable build examples */
#undef LV_BUILD_EXAMPLES
#define LV_BUILD_EXAMPLES 0
