/* Copyright 2020 Naoki Katahira
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// extern uint8_t is_master;

enum layer_number {
    _DVORAK = 0,
    _QWERTY,
    _FUNCS,
};

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

enum anne_pro_keycodes { SOCD_W = SAFE_RANGE, SOCD_A, SOCD_S, SOCD_D };

bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;

#define DVORAK TG(_DVORAK)
#define QWERTY TG(_QWERTY)
#define FUNCS MO(_FUNCS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _DVORAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | BKSP |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LS/TAB|LCTL/;|LALT/Q|   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |RALT/V|RCTL/Z| RS// |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | TG1  | MO2  |Space | / LWIN  /       \Enter \  |Space | MO2  | MO2  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_DVORAK] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PLUS, KC_EQL, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_BSPC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, MT(MOD_LSFT, KC_TAB), MT(MOD_LCTL, KC_SCLN), MT(MOD_LALT, KC_Q), KC_J, KC_K, KC_X, KC_LBRC, KC_RBRC, KC_B, KC_M, KC_W, MT(MOD_RALT, KC_V), MT(MOD_RCTL, KC_Z), MT(MOD_RSFT, KC_SLSH), TG(_QWERTY), FUNCS, KC_SPC, KC_LGUI, KC_ENT, KC_SPC, FUNCS, FUNCS),

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | BKSP |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LS/TAB|LCTL/Z|LALT/X|   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |RALT/.|RCTL//| RS/- |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |  TG1 | MO2  |Space | / LWIN  /       \Enter \  | Space| MO2  |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `-------------------''-------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, SOCD_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_BSPC, SOCD_A, SOCD_S, SOCD_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, MT(MOD_LSFT, KC_TAB), MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, MT(MOD_RALT, KC_DOT), MT(MOD_RCTL, KC_SLSH), MT(MOD_RSFT, KC_MINS), TG(_QWERTY), FUNCS, KC_SPC, KC_LGUI, KC_ENT, KC_SPC, FUNCS, FUNCS),

    /* FUNCS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |MVPRV | MPLY | MNKT |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |MSBTN1|MSBTN2|MSBTN3|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      | Down |  Up  |      |-------|    |-------|      | Left |Right |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `-------------------''-------'           '------''--------------------'
     */

    [_FUNCS] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _______, _______, _______, _______, _______, KC_DOWN, KC_UP, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SOCD_W:
            if (record->event.pressed) {
                if (s_down) {
                    unregister_code(KC_S);
                }
                register_code(KC_W);
                w_down = true;
            } else {
                unregister_code(KC_W);
                w_down = false;

                if (s_down) {
                    register_code(KC_S);
                }
            }
            return false;
            break;
        case SOCD_A:
            if (record->event.pressed) {
                if (d_down) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
                a_down = true;
            } else {
                unregister_code(KC_A);
                a_down = false;

                if (d_down) {
                    register_code(KC_D);
                }
            }
            return false;
            break;
        case SOCD_S:
            if (record->event.pressed) {
                if (w_down) {
                    unregister_code(KC_W);
                }
                register_code(KC_S);
                s_down = true;
            } else {
                unregister_code(KC_S);
                s_down = false;

                if (w_down) {
                    register_code(KC_W);
                }
            }
            return false;
            break;
        case SOCD_D:
            if (record->event.pressed) {
                if (a_down) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
                d_down = true;
            } else {
                unregister_code(KC_D);
                d_down = false;

                if (a_down) {
                    register_code(KC_A);
                }
            }
            return false;
            break;
    }
    return true;
}
