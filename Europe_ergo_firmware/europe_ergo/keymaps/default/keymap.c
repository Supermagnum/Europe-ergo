// Copyright 2022 Supermagnum (@Supermagnum)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour,turned debug on.
  debug_enable=true;
  debug_matrix=true;
  setPinOutput(LED1_PIN);
  setPinOutput(LED2_PIN);
} 

// added for debug purposes of the Pcb's:
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

enum custom_layers {
    _QWERTY,
    _NORWEGIAN,  //DVORAK
};

enum custom_keycodes {
    FN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x9(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       /**/                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUM,
        KC_GRV,  NO_1,    NO_2,    NO_3,    NO_4,    NO_5,    NO_6,    NO_7,               /**/           NO_8,    NO_9,    NO_0,    NO_PLUS, NO_BSLS,  KC_SCRL, KC_PAUS, KC_PSCR,
        KC_TAB,  NO_Q,    NO_W,    NO_E,    NO_R,    NO_T,    NO_Y,    KC_INS,             /**/           KC_HOME, NO_U,    NO_I,    NO_O,    NO_P,    NO_ARNG, NO_DIAE, KC_BSPC,
        KC_CAPS, NO_A,    NO_S,    NO_D,    NO_F,    NO_G,    NO_H,                        /**/                    NO_J,    NO_K,    NO_L,    NO_OSTR, NO_AE, NO_QUOT, KC_ENT,
        KC_LSFT, KC_NUBS, NO_Z,    NO_X,    NO_C,    NO_V,    NO_B,    KC_DEL,             /**/           KC_END,  NO_N,    NO_M,    NO_COMM, NO_DOT,  NO_MINS, KC_PGUP, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,   TG(_NORWEGIAN),                             /**/                             TG(_NORWEGIAN),   KC_PGDN, KC_RGUI, FN,      KC_RCTL,
                                                                       KC_NO,              /**/           KC_UP,
                                                              KC_NO,   KC_NO,   KC_NO,     /**/  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_NORWEGIAN] = LAYOUT_6x9(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       /**/                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUM,
        NO_PIPE, NO_1,    NO_2,    NO_3,    NO_4,    NO_5,    NO_6,    NO_7,               /**/           NO_8,    NO_9,    NO_0,    NO_PLUS, NO_BSLS, KC_SCRL, KC_PAUS, KC_PSCR,
        KC_TAB,  NO_Q,    NO_W,    NO_E,    NO_R,    NO_T,    NO_Y,    KC_INS,             /**/           KC_HOME, NO_U,    NO_I,    NO_O,    NO_P,    NO_ARNG, KC_RBRC, KC_BSPC,
        KC_CAPS, NO_A,    NO_S,    NO_D,    NO_D,    NO_G,    NO_H,                        /**/                    NO_J,    NO_K,    NO_L,    NO_OSTR, NO_AE,   NO_QUOT, KC_ENT,
        KC_LSFT, NO_LABK, NO_Z,    NO_X,    NO_C,    NO_V,    NO_B,    KC_DEL,             /**/           KC_END,  NO_N,    NO_M,    NO_COMM, NO_DOT,  NO_MINS, KC_PGUP, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,   KC_TRANSPARENT,                             /**/                              KC_TRANSPARENT,   KC_RALT, KC_RGUI, KC_PGDN, KC_RCTL,
                                                                       KC_NO,              /**/           KC_UP,
                                                              KC_NO,   KC_NO,   KC_NO,     /**/  KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

//keymap.c
// Added layer state notification
layer_state_t layer_state_set_user(layer_state_t state) {
  uprintf("Layer state changed\n");
  switch(get_highest_layer(state)) {
    case _QWERTY:
      writePinHigh(LED1_PIN);
      writePinLow(LED2_PIN);
      break;
    case _NORWEGIAN:
      writePinHigh(LED2_PIN);
      writePinLow(LED1_PIN);
      break;
    default:
      writePinLow(LED1_PIN);
      writePinLow(LED2_PIN);
      break;
  }
  return state;
}

