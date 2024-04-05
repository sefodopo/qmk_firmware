/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define STICKY_LAYER 1
#define NUM_LAYER 2
#define SYM_LAYER 3
#define MEDIA_LAYER 4
#define GAME_LAYER 5
#define BLU_LAYER 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
        LT(STICKY_LAYER, KC_ESC), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
        LT(MEDIA_LAYER, KC_TAB), KC_A, KC_R, ALT_T(KC_S), CTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RALT_T(KC_E), KC_I, KC_O, KC_QUOT,
        //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
        //|--------+--------+--------+------------+------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        LT(NUM_LAYER, KC_BSPC), SFT_T(KC_SPC), LT(SYM_LAYER, KC_ENT), LT(MEDIA_LAYER, KC_ENT), KC_SPC, KC_BSPC
        //`--------------------------'  `--------------------------'

        ),

    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        TO(NUM_LAYER), TO(0), TO(SYM_LAYER), TO(MEDIA_LAYER), KC_SCRL, KC_SCRL
        //`--------------------------'  `--------------------------'
        ),

    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______, KC_SLSH, KC_7, KC_8, KC_9, KC_MINS, KC_CALC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, C(KC_X), C(KC_C), C(KC_V), _______, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_DOT, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______
        //`--------------------------'  `--------------------------'
        ),

    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, KC_UNDS, KC_MINS, KC_PLUS, KC_ASTR, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERC, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_GRV, KC_PIPE,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, KC_ENT, KC_SPC, KC_BSPC
        //`--------------------------'  `--------------------------'
        ),

    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MPRV, KC_PSCR,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_MPLY, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, KC_MNXT, KC_APP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, TO(0), _______, _______
        //`--------------------------'  `--------------------------'
        ),
};

// BELOW IS TAKEN FROM https://github.com/filterpaper/qmk_userspace?tab=readme-ov-file#instant-tap
// Matches rows on a 3x5_2 split keyboard
#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)

#define IS_BILATERAL(r, n) ((r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2))

static uint16_t    next_keycode;
static keyrecord_t next_record;

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !IS_HOMEROW(record); // || IS_BILATERAL(record, next_record);
    //     switch (keycode) {
    //         case LT(NUM_LAYER, KC_BSPC):
    //         case LT(SYM_LAYER, KC_ENT):
    //         case LT(MEDIA_LAYER, KC_ENT):
    //         case SFT_T(KC_SPC):
    //             return true;
    //         default:
    //             return IS_BILATERAL(record, next_record);
    //     }
}

// BELOW IS TAKEN FROM https://github.com/filterpaper/qmk_userspace?tab=readme-ov-file#instant-tap
#define INPUT_INTERVAL TAPPING_TERM / 2
#define IS_TYPING(kc) (last_input_activity_elapsed() < INPUT_INTERVAL && KC_A <= (uint8_t)kc && (uint8_t)kc <= KC_SLSH && !IS_QK_LAYER_TAP(kc))

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t prev_keycode;
    static bool     is_pressed[UINT8_MAX];

    if (record->event.pressed) {
        prev_keycode = next_keycode;

        next_keycode = keycode;
        next_record  = *record;
    }

    if (IS_HOMEROW(record) && IS_QK_MOD_TAP(keycode)) {
        uint8_t const tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        if (record->event.pressed && IS_TYPING(prev_keycode)) {
            record->keycode         = tap_keycode;
            is_pressed[tap_keycode] = true;
        } else if (!record->event.pressed && is_pressed[tap_keycode]) {
            record->keycode         = tap_keycode;
            is_pressed[tap_keycode] = false;
        }
    }
    return true;
}
