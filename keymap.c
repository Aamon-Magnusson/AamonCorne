#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
        VIM_O = SAFE_RANGE,
        VIM_G,
        VIM_QUIT,
        TAG_1,
        TAG_2,
        TAG_3,
        TAG_4,
        TAG_5,
        TEST_EMOJI,
        WINDOW_1,
        WINDOW_2,
        WINDOW_4,
        WINDOW_6,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        static uint8_t current_mods = 0;
    switch (keycode) {
                case VIM_G:
                        current_mods = get_mods() & MOD_MASK_SHIFT;
                        if (record->event.pressed && (current_mods) != 0) {
                                //unregister_mods(MOD_MASK_SHIFT);
                                del_mods(current_mods);
                                SEND_STRING(SS_LCTL(SS_TAP(X_END)));
                                add_mods(current_mods);
                        } else if (record->event.pressed) {
                                SEND_STRING(SS_LCTL(SS_TAP(X_HOME)));
                        }
                        break;
                case VIM_O:
                        current_mods = get_mods() & MOD_MASK_SHIFT;
                        if (record->event.pressed && (current_mods) != 0) {
                                del_mods(current_mods);
                                SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_UP));
                                add_mods(current_mods);
                        } else if (record->event.pressed) {
                                SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));
                        }
                        break;
                case VIM_QUIT:
                        current_mods = get_mods() & MOD_MASK_SHIFT;
                        if (record->event.pressed && (current_mods) != 0) {
                                del_mods(current_mods);
                                SEND_STRING(SS_LALT(SS_TAP(X_F4)));
                                add_mods(current_mods);
                        }
                        break;
                case TAG_1:
                        //current_mods = get_mods() & MOD_MASK_CG;
                        if (record->event.pressed) {
                                //del_mods(current_mods);
                                for (int i = 0; i < 9; i++){
									SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                                }
                                //add_mods(current_mods);
                        }
                        break;
                case TAG_2:
                        //current_mods = get_mods() & MOD_MASK_CG;
                        if (record->event.pressed) {
                                //del_mods(current_mods);
                                for (int i = 0; i < 9; i++){
									SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                                }
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                //add_mods(current_mods);
                        }
                        break;
                case TAG_3:
                        //current_mods = get_mods() & MOD_MASK_CG;
                        if (record->event.pressed) {
                                //del_mods(current_mods);
                                for (int i = 0; i < 9; i++){
									SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                                }
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                //add_mods(current_mods);
                        }
                        break;
                case TAG_4:
                        //current_mods = get_mods() & MOD_MASK_CG;
                        if (record->event.pressed) {
                                //del_mods(current_mods);
                                for (int i = 0; i < 9; i++){
									SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                                }
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                //add_mods(current_mods);
                        }
                        break;
                case TAG_5:
                        //current_mods = get_mods() & MOD_MASK_CG;
                        if (record->event.pressed) {
                                //del_mods(current_mods);
                                for (int i = 0; i < 9; i++){
									SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                                }
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                                //add_mods(current_mods);
                        }
                        break;
                case TEST_EMOJI:
                        if (record->event.pressed) {
                                send_unicode_string("🦆 (ノಠ痊ಠ)ノ彡┻━┻ (⑅∫°ਊ°)∫");
                        }
                        break;
                case WINDOW_1:
                        if (record->event.pressed) {
                                SEND_STRING(SS_LGUI(SS_TAP(X_Z)));
                                //_delay_ms(250);
                                SEND_STRING("11");
                        }
                        break;
                case WINDOW_2:
                        if (record->event.pressed) {
                                SEND_STRING(SS_LGUI(SS_TAP(X_Z)));
                                //_delay_ms(250);
                                SEND_STRING("21");
                        }
                        break;
                case WINDOW_4:
                        if (record->event.pressed) {
                                SEND_STRING(SS_LGUI(SS_TAP(X_Z)));
                                //_delay_ms(250);
                                SEND_STRING("41");
                        }
                        break;
                case WINDOW_6:
                        if (record->event.pressed) {
                                SEND_STRING(SS_LGUI(SS_TAP(X_Z)));
                                //_delay_ms(250);
                                SEND_STRING("62");
                        }
                        break;
        }
        return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
        LT(3,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        LT(4,KC_ESC), MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        MT(MOD_LCTL, KC_LGUI), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,MT(MOD_RGUI, KC_M), MT(MOD_RALT, KC_COMM),MT(MOD_RSFT, KC_DOT), MT(MOD_RCTL, KC_SLSH), MO(3),
        KC_DEL,LT(2,KC_ENT), MO(1), LT(1,KC_SPC), KC_RSFT, KC_BSPC),

// VIM layer
[1] = LAYOUT_split_3x6_3(
        KC_TAB, KC_NO, C(KC_RIGHT), KC_NO, KC_NO, KC_NO, C(KC_C), C(KC_Z), KC_HOME, VIM_O, C(KC_V), KC_PGUP,
        KC_ESC,MT(MOD_LCTL, KC_END), KC_LSFT, KC_LALT, KC_LGUI, VIM_G, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_PGDN,
        KC_LCTL, VIM_QUIT, C(KC_X), KC_NO, KC_NO, C(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, C(KC_F), KC_NO,
        KC_DEL, KC_ENT, KC_NO, KC_SPC, KC_RSFT, KC_BSPC),

// Numbers and special chars
[2] = LAYOUT_split_3x6_3(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR,
        KC_NO,MT(MOD_LCTL, KC_LPRN),MT(MOD_LSFT, KC_RPRN),MT(MOD_LALT, KC_LBRC),MT(MOD_LGUI, KC_RBRC), KC_MINS, KC_DOT, KC_4, KC_5, KC_6, KC_ASTR, KC_SLSH,
        KC_LCTL, KC_LT, KC_GT, KC_LCBR, KC_RCBR, KC_EQL, KC_0, KC_1, KC_2, KC_3, KC_PLUS, KC_MINS,
        KC_DEL, KC_ENT, KC_NO, KC_SPC, KC_RSFT, KC_BSPC),

// Mouse and system
[3] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO,
       	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_BTN2, KC_BTN1, KC_MPLY, KC_MUTE, KC_NO),

// Tag layer
[4] = LAYOUT_split_3x6_3(
        G(KC_TAB), TAG_1, TAG_2, TAG_3, TAG_4, TAG_5, KC_NO, KC_NO, KC_NO, KC_NO, G(C(KC_LEFT)), KC_NO,
        KC_NO, WINDOW_1, WINDOW_2, WINDOW_4, WINDOW_6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, G(C(KC_RIGHT)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

// F-keys
//[4] = LAYOUT_split_3x6_3(
//        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
//        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_F12,
//        TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RGUI, KC_RALT, KC_RSFT, KC_RCTL, KC_NO,
//        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

// Gaming layer (Currently LT don't work)
//[5] = LAYOUT_split_3x6_3(
//        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC,
//        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
//        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(0),
//        KC_LALT, KC_ESC, KC_SPC, KC_SPC, KC_RSFT, KC_BSPC),

};
