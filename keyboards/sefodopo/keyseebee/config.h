// Copyright 2024 Joshua Zander (@Sefodopo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

#define SPLIT_HAND_PIN_LOW_IS_LEFT

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN A9
#define SERIAL_USART_RX_PIN A10
#define SERIAL_USART_TX_PAL_MODE 1
#define SERIAL_USART_RX_PAL_MODE 1
#define SERIAL_USART_DRIVER SD1
