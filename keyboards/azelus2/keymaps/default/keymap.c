// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _SYM 3
#define _NAV 2
#define _QWERTY 1
#define _COLEMAK_DH 0

#define _____ KC_TRNS
#define XXXXX KC_NO

/*
How to build and flash on Ubuntu
--------------------------------
QMK master has a lot of setup changes (Python, potentially Docker):
  - Follow https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk if necessary.

Linux: Make sure ModemManager is not running:
- systemctl status ModemManager.service
- systemctl stop ModemManager.service

Uninstall permanently if you wish:
- sudo systemctl disable ModemManager.service

Install:
- sudo apt-get install avrdude avr-libc binutils-avr gcc-avr

Navigate to qmk folder:
 - qmk compile -kb azelus2 -km default

Flash the arduino micro:
 - double tap the reset button, give it a second to register with the system, and within 5 seconds execute:
 - avrdude -D -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -Uflash:w:/home/.../github/qmk_firmware/azelus2_default.hex:i
 (-D avoids clearing the memory before trying to read the new firmware)
 (absolute path mandatory!)


*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_DH] = {
  {KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,         KC_U,    KC_Y,       XXXXX,     XXXXX},
  {_____, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,         KC_E,    KC_I,       KC_O,        KC_BSPC},
  {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,         KC_COMM, KC_DOT,     KC_SLSH,     KC_RSFT},
  {_____,   KC_ESC, KC_LCTL,  KC_LOPT, KC_LGUI,  MO(_SYM),            KC_ENT,  MO(_NAV),     KC_SPC,  XXXXX,      XXXXX,       XXXXX}
},
[_QWERTY] = {
   {KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,         KC_I,    KC_O,       KC_P,     XXXXX},
   {_____, KC_A,   KC_S,    KC_D,    KC_F,    KC_H,                KC_J,    KC_K,         KC_L,    KC_SCLN,       KC_QUOT,        KC_BSPC},
   {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,         KC_COMM, KC_DOT,     KC_SLSH,     KC_RSFT},
   {_____,   KC_ESC, KC_LCTL,  KC_LOPT, KC_LGUI,  MO(_SYM),            KC_ENT,  MO(_NAV),     KC_SPC,  XXXXX,      XXXXX,       XXXXX}
},
[_NAV] = {
  {_____,     _____,  KC_F9,   KC_F10,   KC_F11, KC_F12,      KC_PGUP, _____,   KC_UP,   KC_KB_MUTE,  KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP},
  {_____,           _____,  KC_F5,   KC_F6,    KC_F7,  KC_F8,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,    _____, KC_DEL},
  {_____,           _____,  KC_F1,   KC_F2,    KC_F3,  KC_F4,      _____,   _____,   _____,   _____,       _____, _____},
  {DF(_COLEMAK_DH), _____,  _____,   _____,  _____,  _____,       _____,  _____,   _____,   _____,       DF(_QWERTY), _____}
},
[_SYM] = {
  {_____, KC_EXLM, KC_AT, KC_DLR, KC_LCBR, KC_RCBR,            KC_ASTR, KC_7,    KC_8,   KC_9,  KC_PERC, KC_TILD},
  {_____, KC_DQT, KC_EQL, KC_SCLN, KC_LPRN, KC_RPRN,            KC_PLUS, KC_4,    KC_5,   KC_6,  KC_DOT, KC_BSPC},
  {_____,  KC_AMPR, KC_PIPE, KC_COLON, KC_LBRC, KC_RBRC,            KC_MINS,  KC_1,    KC_2,   KC_3,  KC_UNDS, KC_GRV},
  {KC_QUOT, _____, _____, _____,   _____,   _____,              _____,  KC_0,   _____,  KC_HASH,  KC_CIRC, KC_BSLS}
}
};
