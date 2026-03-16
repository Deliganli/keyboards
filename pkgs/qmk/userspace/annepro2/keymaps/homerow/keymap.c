#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    HMR,
    NAV,
    MOU,
    MED,
    NUM,
    SYM,
    FUN,
    FN1,
    FN2,
};

#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS // https://docs.qmk.fm/tap_hold#hold-on-other-key-press

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
#define U_FN1 LT(FN1, KC_LEFT)
#define U_FN2 LT(FN2, KC_DOWN)
#define U_CAPS LT(FN1, KC_ESC)

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * Layer BASE
  * ,-----------------------------------------------------------------------------------------.
  * | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer TAP in BASE
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |       UP       |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
  * \-----------------------------------------------------------------------------------------/
  */
  [BASE] = LAYOUT_60_ansi(
     KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
     KC_TAB,           KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
     LT(FN1, KC_CAPS), KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
     KC_LSFT,          KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
     KC_LCTL,          KC_LGUI, KC_LALT,             KC_SPC,       KC_RALT, U_FN1,   U_FN2,  RCTL_T(KC_RGHT)
  ),
  /*
  * ,-----------------------------------------------------------------------------------------.
  * |     |  q  |  w  |  e  |  r  |  t  |     |  y  |  u  |  i  |  o  |  p  |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |  a  |  s  |  d  |  f  |  g  |     |  h  |  j  |  k  |  l  |  '  |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |  z  |  x  |  c  |  v  |  b  |     |  n  |  m  |  ,  |  .  |  /  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     | esc | spc | tab |     | ent | bsp | del |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  FN1  |  FN2  |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [HMR] = LAYOUT_60_ansi(
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, _______,
     _______, U_A,     U_S,     U_D,     U_F,     KC_G,    XXXXXXX, KC_H,    U_J,     U_K ,    U_L,     U_QUOT,  XXXXXXX, _______,
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
     _______, XXXXXXX, U_ESC,   U_SPC,   U_TAB,   XXXXXXX, U_ENT,   U_BSP,   U_DEL,   XXXXXXX, XXXXXXX, _______,
     _______, _______, _______,                            XXXXXXX,          _______, MO(FN1), MO(FN2), _______
  ),
  [NAV] = LAYOUT_60_ansi(
     _______, _______, _______, _______, _______, _______, _______, _______, KC_PASTE,KC_COPY, KC_CUT , KC_UNDO, _______, _______,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, _______,
     _______, _______, KC_RALT, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS , _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______,                            _______,          _______, _______, _______, _______
  ),
  [MED] = LAYOUT_60_ansi(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_CAPS, _______, _______,
     _______, _______, KC_RALT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______, _______,
     _______, _______, _______,                            _______,          _______, _______, _______, _______
  ),
  [MOU] = LAYOUT_60_ansi(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______, _______,
     _______, _______, KC_RALT, _______, _______, _______, _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, _______,
     _______, _______, _______, _______, _______, _______, MS_BTN2, MS_BTN1, MS_BTN3, _______, _______, _______,
     _______, _______, _______,                            _______,          _______, _______, _______, _______
  ),
  [NUM] = LAYOUT_60_ansi(
     _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,
     _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______, _______, _______, KC_RALT, _______, _______,
     _______, _______, KC_DOT,  KC_0,    KC_MINS, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______,                            _______,          _______, _______, _______, _______
  ),
  [SYM] = LAYOUT_60_ansi(
     _______, S(KC_LBRC), S(KC_7),  S(KC_8), S(KC_9),    S(KC_RBRC), _______, _______, _______, _______, _______, _______, _______, _______,
     _______, S(KC_SCLN), S(KC_4),  S(KC_5), S(KC_6),    S(KC_EQL),  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______,
     _______, S(KC_GRV),  S(KC_1),  S(KC_2), S(KC_3),    S(KC_BSLS), _______, _______, _______, KC_RALT, _______, _______, _______,
     _______, _______,    S(KC_9),  S(KC_0), S(KC_MINS), _______,    _______, _______, _______, _______, _______, _______,
     _______, _______,    _______,                                   _______,          _______, _______, _______, _______
  ),
  [FUN] = LAYOUT_60_ansi(
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, _______, _______, KC_RALT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______,                   _______,          _______, _______, _______, _______
  ),
  /*
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
  [FN1] = LAYOUT_60_ansi(
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
     _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
     _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
     _______, _______, _______,                   _______,          _______, _______, MO(FN2), _______
  ),
  /*
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |  F8 |LEDTG|LEDI+|LEDPV|LEDNX|    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |BASE | HMR |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
  [FN2] = LAYOUT_60_ansi(
     _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
     _______, _______,    KC_UP,      _______,    _______,    _______, _______, _______, _______, _______,       KC_PSCR,       KC_HOME,       KC_END,        _______,
     _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______,       KC_PGUP,       KC_PGDN,       _______,
     _______, DF(BASE),   DF(HMR),    _______,    _______,    _______, _______, _______, _______, KC_INS ,       KC_DEL,        _______,
     _______, _______,    _______,                            _______,          _______, _______, _______,       _______
  ),
  // [MYLAYER] = LAYOUT_60_ansi(
  //    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  // ),
};

void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FN1:
            // Set the leds to green
            ap2_led_set_foreground_color(0x00, 0xFF, 0x00);
            break;
        case FN2:
            // Set the leds to blue
            ap2_led_set_foreground_color(0x00, 0x00, 0xFF);
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_sticky_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_mask_set_mono */
    } else {
        // Reset the capslock if there is no layer active
        ap2_led_unset_sticky_key(2, 0);
    }

    return true;
}
