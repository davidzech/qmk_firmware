/* Copyright 2020 Yiancar
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
#include "raw_hid.h"

enum custom_keycodes {
    KC_SWTCH_WIN = SAFE_RANGE,
    KC_SWTCH_MAC,
    KC_PRTSC,
    KC_APLCK,
    KC_WINLCK
};

#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

enum layer {
    MAC,
    MAC_FN,
    WIN,
    WIN_FN
} layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC] = LAYOUT_all( /* Base */
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_APLCK,  KC_MSNP, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,
    KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                                            KC_RGUI, KC_APFN,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[MAC_FN] = LAYOUT_all( /* FN */
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SWTCH_WIN, KC_TRNS, KC_NLCK, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,                   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[WIN] = LAYOUT_all( /* Base */
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_WINLCK,  KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                                            KC_RALT, MO(WIN_FN),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[WIN_FN] = LAYOUT_all( /* FN */
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SWTCH_MAC, KC_TRNS, KC_NLCK, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,                   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case KC_SWTCH_MAC:
            if (record->event.pressed) {
                layer_move(MAC);
            }
            return false;

        case KC_SWTCH_WIN:
            if (record->event.pressed) {
                layer_move(WIN);
            }
            return false;

        case KC_APFN:
            if (record->event.pressed) {
                layer_on(1);
            } else {
                layer_off(1);
            }
            return true;

        case KC_APLCK:
            if (record->event.pressed) {
                register_code(KC_MENU);
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 150) {
                    SEND_STRING(SS_LGUI(SS_LCTRL("q")));
                }
                unregister_code(KC_MENU);
            }

            return false;

        case KC_WINLCK:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 1000) {
                    SEND_STRING(SS_LGUI("l"));
                }
            }
            return false;

        default:
            return true;
    }
}

/* Indicator LEDS are part of the LED driver
 * Top LED is blue only. LED driver 2 RGB 63 Blue channel
 * Middle LED is blue and red. LED driver 2 RGB 63 Red and Green channel
 * Bottom LED is red only LED driver 2 RGB 48 Blue channel.
 */


uint8_t CAPS = 0; // Top LED
uint8_t FN1_BLUE = 0; // Middle LED BLUE channel
uint8_t FN1_RED = 0; // Middle LED RED channel
uint8_t FN2 = 0; // Bottom LED

extern void IS31FL3733_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        CAPS = 255;
    } else {
        CAPS = 0;
    }

    if (led_state.scroll_lock) {
        FN2 = 255;
    } else {
        FN2 = 0;
    }

    IS31FL3733_set_color( 63+64-1, FN1_BLUE, FN1_RED, CAPS );
    IS31FL3733_set_color( 48+64-1, 0, 0, FN2 );

    return false;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case MAC:
        case MAC_FN:
            FN1_BLUE = 255;
            FN1_RED = 0;
            break;

        case WIN:
        case WIN_FN:
            FN1_BLUE = 0;
            FN1_RED = 255;
            break;

        default:
            FN1_BLUE = 0;
            FN1_RED = 0;
            break;
    }
    led_update_kb(host_keyboard_led_state());
    return state;
}

#define MSG_MOVE_LAYER 0

typedef uint8_t message_type_t;
typedef struct __attribute__((packed)) {
    message_type_t type;
    uint8_t data[];
} message_t;

typedef struct __attribute__((packed))  {
    uint8_t layer;
} move_layer_t;

typedef union __attribute__((packed))  {
    uint8_t success;
    uint8_t raw[32];
} move_layer_response_t;

void handle_move_layer(move_layer_t *data, move_layer_response_t *response) {
    switch (data->layer) {
        case MAC:
            if (!IS_LAYER_ON(MAC))
                layer_move(MAC);
            response->success = 1;
            break;

        case WIN:
            if (!IS_LAYER_ON(WIN))
                layer_move(WIN);
            response->success = 1;
            break;
        default:
            response->success = 0;
            break;
    }
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your code goes here. data is the packet received from host.
    uint8_t resp[32] = {0xff};
    if (length > 0) {
        message_t *msg = (message_t*)data;
        switch (msg->type) {
            case MSG_MOVE_LAYER:
                handle_move_layer((move_layer_t*)msg->data, (move_layer_response_t*)resp);
                break;

            default:
                break;
        }
    }

    raw_hid_send(resp, sizeof(resp));
}


