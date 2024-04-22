// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
/*    [0] = LAYOUT_split_3x6_4(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_BSPC, KC_SPC, KC_LGUI, KC_LGUI KC_SPC, KC_ENT, KC_RALT, KC_RALT, KC_RALT)}; */

    [0] = LAYOUT_split_3x6_5(
            KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_A, KC_B, KC_C, KC_D, KC_E, KC_F,
            KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,
            KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,
                  KC_S, KC_T, KC_U, KC_V, KC_W, KC_S, KC_T, KC_U, KC_V, KC_W)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_X, KC_Y), ENCODER_CCW_CW(KC_X, KC_Y) },
};
#endif
