// Copyright 2023 Supermagnum (@Supermagnum)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define SPLIT_HAND_MATRIX_GRID GP27, GP26 // Only used for prototype PCB
// #define SPLIT_HAND_PIN GP26 // Use for proper PCB.

/* split configuration */
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode

#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_USART_PIN_SWAP       // Swap TX and RX pins if keyboard is master halve. (Only available on some MCUs)

#define SPLIT_LED_STATE_ENABLE      // Sync lock LED status between halves

#define LED_CAPS_LOCK_PIN GP16 	//The pin that controls the Caps Lock LED
#define LED_SCROLL_LOCK_PIN GP17 	//The pin that controls the Scroll Lock LED


#define LED_PIN_ON_STATE 1 	//The state of the indicator pins when the LED is "on" - 1 for high, 0 for low
#define LED1_PIN GP18 //PWM3 L1 LED
#define LED2_PIN GP19 //PWM4 L2 LED
#define LED3_PIN GP22 //Controls NUM layer LED on or off, PWM5

#define DEBOUNCE 10
