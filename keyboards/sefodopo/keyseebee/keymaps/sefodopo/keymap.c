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

// clang-format off

#include "repeat_key.h"
#include QMK_KEYBOARD_H

#define GALLIUM_LAYER 0
#define COLEMAK_LAYER 1
#define GAME_LAYER 2 // This is actually two layers
#define STICKY_LAYER 4
#define NUM_LAYER 5
#define SYM_LAYER 6
#define MEDIA_LAYER 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[COLEMAK_LAYER] = LAYOUT_split_3x6_5(
//,,-------------------------------------------------------------.                    ,-----------------------------------------------------.
    LT(STICKY_LAYER, KC_ESC), KC_Q, KC_W, KC_F, KC_P, KC_B,                                 KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(MEDIA_LAYER, KC_TAB), KC_A, KC_R, ALT_T(KC_S), CTL_T(KC_T), KC_G,                                KC_M, CTL_T(KC_N), ALT_T(KC_E), KC_I, KC_O, KC_QUOT,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LGUI, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MUTE,                               KC_MPLY, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
    //|--------+--------+--------+------------+------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

    KC_BSPC, LT(NUM_LAYER, QK_AREP), SFT_T(QK_REP), MO(SYM_LAYER), LT(MEDIA_LAYER, KC_ENT), KC_SPC, KC_BSPC, KC_BSPC
    //`--------------------------'  `--------------------------'
    ),

[GALLIUM_LAYER] = LAYOUT_split_3x6_5(
    //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
    LT(STICKY_LAYER, KC_ESC), KC_B, KC_L, KC_D, KC_C, KC_V,                              KC_J, KC_F, KC_O, KC_U, KC_SCLN, KC_BSLS,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(MEDIA_LAYER, KC_TAB), KC_N, KC_R, ALT_T(KC_T), CTL_T(KC_S), KC_G,                              KC_Y, CTL_T(KC_H), ALT_T(KC_A), KC_E, KC_I, KC_QUOT,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LGUI, KC_X, KC_Q, KC_M, KC_W, KC_Z, KC_MUTE,                         KC_MPLY, KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
    //|--------+--------+--------+------------+------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

    KC_BSPC, LT(NUM_LAYER, QK_AREP), SFT_T(QK_REP), MO(SYM_LAYER),                  LT(MEDIA_LAYER, KC_ENT), KC_SPC, KC_BSPC, KC_BSPC
    //`--------------------------'  `--------------------------'
    ),

// Sticky Layer
[STICKY_LAYER] = LAYOUT_split_3x6_5(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, EE_CLR, _______, _______, _______, _______, _______, _______, _______, _______, DF(COLEMAK_LAYER), DF(GALLIUM_LAYER),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    TO(GAME_LAYER), TO(NUM_LAYER), TO(0), TO(SYM_LAYER), TO(MEDIA_LAYER), KC_SCRL, KC_SCRL, _______
    //`--------------------------'  `--------------------------'
    ),

// Num Layer
[NUM_LAYER] = LAYOUT_split_3x6_5(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, KC_CALC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, C(KC_X), C(KC_C), C(KC_V), _______,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,    _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    //`--------------------------'  `--------------------------'
    ),

// Sym Layer
[SYM_LAYER] = LAYOUT_split_3x6_5(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, KC_UNDS, KC_MINS, KC_PLUS, KC_ASTR, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERC, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_GRV, KC_PIPE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, KC_ENT, KC_SPC, KC_BSPC, _______
    //`--------------------------'  `--------------------------'
    ),

// Media Layer
[MEDIA_LAYER] = LAYOUT_split_3x6_5(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MPRV, KC_PSCR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, _______, _______, KC_MPLY, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, KC_MNXT, KC_APP,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, TO(0), _______, _______, _______
    //`--------------------------'  `--------------------------'
    ),

// Game Layer
[GAME_LAYER] = LAYOUT_split_3x6_5(
    //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC, _______, _______,     _______,     _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB, _______, _______,        KC_T,        KC_S, _______,                      _______,    KC_H,    KC_A, _______, _______, _______,
    //|--------+--------+--------+------------+------------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _______, _______, _______, _______, _______, TO(0), _______, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+------------+------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
TT(GAME_LAYER+1), KC_LCTL,  KC_SPC, KC_LALT, _______, _______, _______, _______
    //`--------------------------'  `--------------------------'
    ),
// Game Layer 2
[GAME_LAYER + 1] = LAYOUT_split_3x6_5(
//,-------------------------------------------------------------.                    ,-----------------------------------------------------.
    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,    _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______,                                   _______, _______, _______, _______
//`--------------------------'  `--------------------------'
    ),
};

static uint16_t    next_keycode;
static keyrecord_t next_record;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LT(NUM_LAYER, QK_AREP):
            if (record->tap.count) {
                // Handle tap press and release events
                if(process_last_key(QK_AREP, record)) {
                    process_repeat_key(QK_AREP, record);
                }
                return false;
            }
            break;
        case SFT_T(QK_REP):
            if (record->tap.count) {
                process_repeat_key(QK_REP, record);
                return false;
            }
            break;
    }
    return true; // perform default code
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case LT(NUM_LAYER, QK_AREP):
        case SFT_T(QK_REP):
            return false;
    }
    // Don't record encoder turns or presses
    if (record->event.type == ENCODER_CW_EVENT ||
            record->event.type == ENCODER_CCW_EVENT ||
            (record->event.key.row == 3 && record->event.key.col == 5) ||
            (record->event.key.row == 7 && record->event.key.col == 0) ) return false;
    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (!mods) switch (keycode) {
        case KC_F: return KC_D; // CVAT Forwards to backwards
        case KC_D: return KC_F; // CVAT Backwards to forwards
    }
    return KC_TRNS; // Deler to default definitions
}

// BELOW IS TAKEN FROM https://github.com/filterpaper/qmk_userspace?tab=readme-ov-file#instant-tap
// Matches rows on a 3x5_2 split keyboard
#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)

#define IS_BILATERAL(r, n) ((r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2))
#define IS_UNILATERAL(r, n) ( \
        (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
        (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) )

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // return !IS_HOMEROW(record); // || IS_BILATERAL(record, next_record);
    //     switch (keycode) {
    //         case LT(NUM_LAYER, KC_BSPC):
    //         case LT(SYM_LAYER, KC_ENT):
    //         case LT(MEDIA_LAYER, KC_ENT):
    //         case SFT_T(KC_SPC):
    //             return true;
    //         default:
    //             return IS_BILATERAL(record, next_record);
    //     }
    if (IS_UNILATERAL(record, next_record)) {
        // Set the tap keycode and send the pressed event
        record->keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        process_record(record);
        // Release the tap keycode and send the event
        record->event.pressed = false;
        process_record(record);
    }
    return record->event.key.row == 3 || record->event.key.row == 7;
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_BILATERAL(record, next_record);
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(MEDIA_LAYER, KC_ENT):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
#endif

// BELOW IS TAKEN FROM https://github.com/filterpaper/qmk_userspace?tab=readme-ov-file#instant-tap
#define INPUT_INTERVAL TAPPING_TERM / 2
#define IS_TYPING(kc) (last_input_activity_elapsed() < INPUT_INTERVAL && KC_A <= (uint8_t)kc && (uint8_t)kc <= KC_SLSH && !IS_QK_LAYER_TAP(kc))

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t prev_keycode;
    //static keyrecord_t prev_record;
    static bool     is_pressed[UINT8_MAX];

    if (record->event.pressed) {
        prev_keycode = next_keycode;
        //prev_record = next_record;

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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [2] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [3] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [4] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [5] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [6] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [7] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case GALLIUM_LAYER:
            oled_write_P(PSTR("Ga v2\n"), false);
            break;
        case COLEMAK_LAYER:
            oled_write_P(PSTR("Colem\n"), false);
            break;
        case GAME_LAYER:
            oled_write_P(PSTR("Game \n"), false);
            break;
        case GAME_LAYER+1:
            oled_write_P(PSTR("Game#\n"), false);
            break;
        case STICKY_LAYER:
            oled_write_P(PSTR("Stick\n"), false);
            break;
        case NUM_LAYER:
            oled_write_P(PSTR("Numbr\n"), false);
            break;
        case SYM_LAYER:
            oled_write_P(PSTR("Symbl\n"), false);
            break;
        case MEDIA_LAYER:
            oled_write_P(PSTR("Media\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }

    char wpm_str[6];
    sprintf(wpm_str, "%i\n", get_current_wpm());
    oled_write(wpm_str, false);

    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock)
        oled_write_P(PSTR("\nNUM\n"), false);
    if (led_state.caps_lock)
        oled_write_P(PSTR("\nCAP\n"), false);
    if (led_state.scroll_lock)
        oled_write_P(PSTR("\nNUM\n"), false);

    if (is_keyboard_master()) {
        oled_write_P(PSTR("\nMASTR"), false);
    } else {
        oled_write_P(PSTR("\nSLAVE"), false);
    }

    return false;
}
#endif
