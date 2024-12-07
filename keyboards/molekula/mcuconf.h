// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE

#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1 TRUE

/* Reallocate the SysTick timer from TIM2 to TIM3, TIM2 is used for in switch leds */
#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 3
