// Copyright 2022 Supermagnum (@Supermagnum)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(LED1_PIN);
    setPinOutput(LED2_PIN);
    setPinOutput(LED3_PIN);
    writePinLow(LED1_PIN);
    writePinLow(LED2_PIN);
    writePinLow(LED3_PIN);
}

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
    _NUM
};

enum custom_keycodes {
    FN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       /**/                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(_NUM),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,               /**/           KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_SCRL, KC_PAUS, KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_INS,             /**/           KC_HOME, KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,                        /**/                    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,             /**/           KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGUP, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE, TG(_NORWEGIAN),                               /**/                            TG(_NORWEGIAN),   KC_PGDN, KC_ALGR, FN, KC_RCTL,
                                                                       KC_SPACE,            /**/           KC_UP,
                                                              KC_SPACE, KC_SPACE, KC_SPACE, /**/   KC_RIGHT, KC_DOWN, KC_LEFT
    ),
    [_NORWEGIAN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       /**/                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
        NO_PIPE, NO_1,    NO_2,    NO_3,    NO_4,    NO_5,    NO_6,    NO_7,               /**/           NO_8,    NO_9,    NO_0,    NO_PLUS, NO_BSLS, KC_SCRL, KC_PAUS, KC_PSCR,
        KC_TAB,  NO_ARNG,  NO_SCLN, NO_COLN, NO_Y ,    NO_Y,  NO_F  ,    KC_INS,           /**/           KC_HOME, NO_G,    NO_C,    NO_R,    NO_P,     NO_ASTR, NO_TILD, KC_BSPC,
        KC_CAPS, NO_A,    NO_O,    NO_E,    NO_U,    NO_I,    NO_D,                        /**/                    NO_H,    NO_T,    NO_N,    NO_S, NO_MINS,   NO_RABK, KC_ENT,
        KC_LSFT, NO_OSTR, NO_AE,    NO_Q,    NO_J,    NO_K,    NO_X,    KC_DEL,            /**/           KC_END,  NO_B,    NO_M,    NO_W, NO_COMM,  NO_DOT, KC_PGUP, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,   KC_TRNS,                                    /**/                             KC_TRNS,   KC_RALT, KC_ALGR, KC_PGDN, KC_RCTL,
                                                                       KC_SPACE,           /**/           KC_UP,
                                                         KC_SPACE,   KC_SPACE,   KC_SPACE, /**/   KC_RIGHT, KC_DOWN, KC_LEFT
    ),
    [_NUM] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       /**/                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
        NO_PIPE, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        /**/           KC_NO,    KC_NO,   KC_NO,    NO_PLUS, NO_BSLS, KC_SCRL, KC_PAUS, KC_PSCR,
        KC_TAB,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_INS,       /**/           KC_HOME, KC_KP_7,    KC_KP_8,    KC_KP_9,    NO_P,    NO_ARNG, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  /**/                    KC_KP_4, KC_KP_5,  KC_KP_6,   KC_NO, KC_NO,   KC_NO, KC_ENT,
        KC_LSFT, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_DEL,          /**/           KC_KP_0,  KC_KP_1, KC_KP_2,  KC_KP_3, KC_NO,  NO_MINS, KC_PGUP, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,   KC_NO,                                      /**/                                      KC_NO,   KC_RALT, KC_ALGR, KC_PGDN, KC_RCTL,
                                                                       KC_SPACE,           /**/           KC_UP,
                                                            KC_SPACE, KC_SPACE,   KC_SPACE,/**/   KC_RIGHT, KC_DOWN, KC_LEFT
    ),
};

//keymap.c
void housekeeping_task_user(void) {
  switch(get_highest_layer(layer_state)) {
    case _QWERTY:
      writePinHigh(LED1_PIN);
      writePinLow(LED2_PIN);
      writePinLow(LED3_PIN);
      break;
    case _NORWEGIAN:
      writePinHigh(LED2_PIN);
      writePinLow(LED1_PIN);
      writePinLow(LED3_PIN);
      break;
    case _NUM:
      writePinLow(LED1_PIN);
      writePinLow(LED2_PIN);
      writePinHigh(LED3_PIN);
    default:
      writePinLow(LED1_PIN);
      writePinLow(LED2_PIN);
      writePinLow(LED3_PIN);
      break;
  }
}
