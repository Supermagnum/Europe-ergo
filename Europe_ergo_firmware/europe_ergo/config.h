// Copyright 2022 Supermagnum (@Supermagnum)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix configuration */
// Rows are doubled-up
// #define MATRIX_COLS 9
// #define MATRIX_ROWS 12

// // wiring of each half    1     2     3     4     5     6     7     8     9
// #define MATRIX_COL_PINS { GP2,  GP3,  GP10, GP11, GP12, GP13, GP14, GP15, GP20 }
// #define MATRIX_ROW_PINS { GP4,  GP5,  GP6,  GP7,  GP8,  GP9 }



/* split configuration */
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode

#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_USART_PIN_SWAP       // Swap TX and RX pins if keyboard is master halve. (Only available on some MCUs)

#define SPLIT_HAND_PIN GP26         // Check voltage on this pin for handedness
#define SPLIT_HAND_PIN_LOW_IS_LEFT  // Connected to GND means it is the left half of the keyboard

#define SPLIT_LED_STATE_ENABLE      // Sync lock LED status between halves

#define LED_CAPS_LOCK_PIN GP16 	//The pin that controls the Caps Lock LED
#define LED_SCROLL_LOCK_PIN GP17 	//The pin that controls the Scroll Lock LED


#define LED_PIN_ON_STATE 1 	//The state of the indicator pins when the LED is "on" - 1 for high, 0 for low
#define LED1_PIN GP18 
#define LED2_PIN GP19

#define DEBOUNCE 5

