#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    // BASE,
    QWER,
    HMR,
    NAV,
    MOU,
    MED,
    NUM,
    SYM,
    FUN,
    SYMB,
    MDIA,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// Homerow
#define U_A LGUI_T(KC_A)
#define U_S LALT_T(KC_S)
#define U_D LCTL_T(KC_D)
#define U_F LSFT_T(KC_F)
#define U_J LSFT_T(KC_J)
#define U_K LCTL_T(KC_K)
#define U_L LALT_T(KC_L)
#define U_QUOT LGUI_T(KC_QUOT)

// Left thumbs
#define U_ESC LT(MED, KC_ESC)
#define U_SPC LT(NAV, KC_SPC)
#define U_TAB LT(MOU, KC_TAB)

// Right thumbs
#define U_ENT LT(SYM, KC_ENT)
#define U_BSP LT(NUM, KC_BSPC)
#define U_DEL LT(FUN, KC_DEL)

// Functions
#define U_FN1 LT(SYMB, KC_LEFT)
#define U_FN2 LT(MDIA, KC_RGHT)
#define U_CAPS LT(SYMB, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// [BASE] = LAYOUT_ergodox_pretty(
//   KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    U_FN1,              U_FN2,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
//   KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),           TG(SYMB),   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
//   KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
//   KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    HYPR_T(KC_NO),      MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,            CTL_T(KC_SLSH), KC_RSFT,
//   LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,                                          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
//                                                            ALT_T(KC_APP), KC_LGUI,            KC_LALT, CTL_T(KC_ESC),
//                                                                           KC_HOME,            KC_PGUP,
//                                                          KC_SPC, KC_BSPC, KC_END,             KC_PGDN, KC_TAB, KC_ENT
// ),
[QWER] = LAYOUT_ergodox_pretty(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    U_FN1,           U_FN2,        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),        TG(SYMB),     KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
  U_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                   KC_H,     KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    HYPR_T(KC_NO),   MEH_T(KC_NO), KC_N,     KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,                                         KC_UP,    KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
                                         ALT_T(KC_APP), KC_LGUI,         KC_LALT, CTL_T(KC_ESC),
                                                        KC_HOME,         KC_PGUP,
                                       KC_SPC, KC_BSPC, KC_END,          KC_PGDN, KC_TAB, KC_ENT
),
[HMR] = LAYOUT_ergodox_pretty(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    U_FN1,       U_FN2,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,     XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, U_A,     U_S,     U_D,     U_F,     KC_G,                          KC_H,    U_J,     U_K,     U_L,     U_QUOT,  XXXXXXX,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
  _______, KC_LGUI, KC_LALT, U_ESC,   U_SPC,                                           U_BSP,   U_DEL,   U_FN1,   U_FN2,   XXXXXXX,
                                               _______, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                        _______,     _______,
                                      U_TAB,   XXXXXXX, _______,     _______, XXXXXXX, U_ENT
),
[NAV] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_PASTE,KC_COPY, KC_CUT , KC_UNDO, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______,
  _______, _______, KC_RALT, _______, _______, _______, _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS , _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[MED] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_CAPS, _______,
  _______, _______, KC_RALT, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         KC_MPLY, KC_MUTE, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, KC_MSTP
),
[MOU] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______,
  _______, _______, KC_RALT, _______, _______, _______, _______,     _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, _______,
  _______, _______, _______, _______, _______,                                         MS_BTN1, MS_BTN3, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, MS_BTN2
),
[NUM] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,     _______, _______, _______, _______, KC_RALT, _______, _______,
  _______, _______, _______, KC_DOT,  KC_0,                                            _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      KC_MINS, _______, _______,     _______, _______, _______
),
[SYM] = LAYOUT_ergodox_pretty(
  _______, _______,    _______, _______, _______, _______,    _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC), _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, S(KC_SCLN), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL),                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______, S(KC_GRV),  S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS), _______,     _______, _______, _______, _______, KC_RALT, _______, _______,
  _______, _______,    _______, S(KC_9), S(KC_0),                                            _______, _______, _______, _______, _______,

                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                         S(KC_MINS), _______, _______,     _______, _______, _______
),
[FUN] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,     _______, _______, _______, _______, KC_RALT, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  EE_CLR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               RM_NEXT, KC_TRNS,     RM_TOGG, RGB_M_P,
                                                        KC_TRNS,     KC_TRNS,
                                      RM_VALD, RM_VALU, KC_TRNS,     KC_TRNS, RM_HUED, RM_HUEU
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, MS_UP,   KC_TRNS, KC_TRNS, KC_TRNS,     DF(HMR),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     DF(QWER), KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2,                                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS, KC_WBAK
),
// [LYR] = LAYOUT_ergodox_pretty(
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
//
//                                                _______, _______,     _______, _______,
//                                                         _______,     _______,
//                                       _______, _______, _______,     _______, _______, _______
// ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
