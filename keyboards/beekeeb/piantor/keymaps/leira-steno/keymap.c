// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

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
#define LSFT_ESC LSFT_T(KC_ESC)
#define LCTL_GRV LCTL_T(KC_GRV)

#define RSFT_QUOT LSFT_T(KC_QUOT)
#define FUN_BSLS LT(_FUNKEY, KC_BSLS)
#define MED_SLSH LT(_MEDIA, KC_SLSH)

#define NUMBER MO(_NUMBER)
#define SYMBOL MO(_SYMBOL)

#define MEDIA MO(_MEDIA)
#define HIDDEN MO(_HIDDEN)
#define T_QWERTY TO(_QWERTY)
#define T_PLOVER TO(_PLOVER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌───────┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───────┐
    * │Tab|Alt│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │  Bsp  │
    * ├───────┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───────┤
    * │Esc|Sft│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' |Sft│
    * ├───────┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───────┤
    * │ ` |Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ \ |FUN│
    * └───────┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───────┘
    *                   ┌───┬───┬───┐   ┌───┬───┬───┐
    *                   │GUI│   │NUM│   │SYM│   │RET│
    *                   └───┴───┴───┘   └───┴───┴───┘
    */
    [_QWERTY] = LAYOUT_split_3x6_3(
        LALT_TAB,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LSFT_ESC,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_QUOT,
        LCTL_GRV,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  MED_SLSH,FUN_BSLS,
                                            KC_LGUI, KC_SPC,  NUMBER,    SYMBOL,  KC_SPC,  KC_ENT
    ),

    [_NUMBER] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,                      KC_ASTR, KC_MINS, KC_LPRN, KC_RPRN, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_EQL,  _______,
        _______, _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
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
        XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                     STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                     STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MEDIA,   XXXXXXX,
                                            STN_NA,  STN_A,   STN_O,     STN_E,   STN_U,   STN_NB
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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}
