// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_PWM_USE_PWM5
#define RP_PWM_USE_PWM5 TRUE
