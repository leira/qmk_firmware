// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_plover_hid.h"

// define layer names
enum layer_names {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _FUNKEY,
  _PLOVER,
  _MEDIA,
  _HIDDEN,
};

// define special keys
#define LALT_TAB LALT_T(KC_TAB)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LSFT_GRV LSFT_T(KC_GRV)

#define FUN_QUOT LT(_FUNKEY, KC_QUOT)
#define RSFT_BSL RSFT_T(KC_BSLS)
#define MED_SLSH LT(_MEDIA, KC_SLSH)

#define NUMBER MO(_NUMBER)
#define SYMBOL MO(_SYMBOL)

#define MEDIA MO(_MEDIA)
#define HIDDEN MO(_HIDDEN)
#define T_QWERTY TO(_QWERTY)
#define T_PLOVER TO(_PLOVER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        LALT_TAB,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL_ESC,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, FUN_QUOT,
        LSFT_GRV,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  MED_SLSH,RSFT_BSL,
                                            KC_LGUI, NUMBER,  KC_TAB,    KC_SPC,  SYMBOL,  KC_ENT
    ),

    [_NUMBER] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,                      KC_ASTR, KC_UNDS, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_EQL,  _______,
        _______, _______, KC_LPRN, KC_RPRN, KC_MINS, KC_PLUS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    [_FUNKEY] = LAYOUT_split_3x6_3(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_F11,  _______, _______, _______, _______,                     _______, _______, _______, _______, KC_F12,  _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    [_PLOVER] = LAYOUT_split_3x6_3(
        PLV_X1,  PLV_SL,  PLV_TL,  PLV_PL,  PLV_HL,  PLV_STR,                     PLV_STR, PLV_FR,  PLV_PR,  PLV_LR,  PLV_TR,  PLV_DR,
        PLV_X2,  PLV_SL,  PLV_KL,  PLV_WL,  PLV_RL,  PLV_STR,                     PLV_STR, PLV_RR,  PLV_BR,  PLV_GR,  PLV_SR,  PLV_ZR,
        PLV_X3,  PLV_X4,  PLV_X5,  PLV_X6,  PLV_X7,  PLV_X8,                      PLV_X9,  PLV_X10, PLV_X11, PLV_X12, MEDIA,   PLV_X13,
                                            PLV_NUM, PLV_A,   PLV_O,     PLV_E,   PLV_U,   PLV_NUM
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, KC_MUTE, _______, _______, _______, _______,
                                            _______, _______, _______,   KC_MPLY, HIDDEN,  _______
    ),

    [_HIDDEN] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, T_PLOVER,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, T_QWERTY,                    _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),
};
