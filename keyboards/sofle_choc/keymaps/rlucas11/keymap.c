 /* Copyright 2022 Brian Low
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

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
};

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Tap Dance declarations
enum {
    TD_GRV_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GRV_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESC/~ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShft | A/Ctl| S/Alt| D/GUI|F/Shft|   G  |-------.    ,-------|   H  |J/Shft| K/GUI| L/Alt| ;/Ctl|'/Shft|
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Ent/Ct|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Caps | LGUI | LCMD |L/SPC | /Enter  /       \Space \  |R/ENTR| _FUNC| ROPT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
    TD(TD_GRV_ESC),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,     KC_7,     KC_8,    KC_9,      KC_0,         KC_MINS,
    KC_TAB,           KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,         KC_BSPC,
    KC_LSFT,        HOME_A, HOME_S,  HOME_D,  HOME_F,    KC_G,                               KC_H,   HOME_J,   HOME_K,  HOME_L, HOME_SCLN, RSFT_T(KC_QUOT),
    KC_LCTL,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,           KC_MPLY,KC_N,     KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  RCTL_T(KC_ENT),
                      KC_CAPSLOCK, KC_LALT, KC_HYPR,LT(_LOWER, KC_ENTER),KC_ENT, KC_SPC, LT(_RAISE, KC_SPC), MO(_FUNCTION), KC_RALT, KC_RGUI
),
/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Right|  Del | Bspc |
 * |------+------+------+------+------+------|       |    | MSEL  |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    KC_BSLS, _______, _______, _______, _______,  _______,                         _______, _______,   _______,   KC_LBRC,   KC_RBRC,    KC_EQL,
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                         _______, KC_BTN1,   KC_MS_U,   KC_BTN2,   KC_WH_U,    KC_DEL,
    _______,   KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,                         _______, KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_WH_D,   KC_PIPE,
    _______, _______, _______,  _______, _______, _______,   KC_MPRV,       KC_MNXT, _______, _______,   _______,   _______,   _______,   _______,
                      _______, _______, _______,  _______, _______,       _______, _______,  _______,   _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_GRV, _______,   _______,  _______,   _______,  _______,                          _______, _______, _______, _______, _______,   KC_PLUS,
    KC_BSLS, _______,  KC_PGUP,    KC_UP,   KC_HOME,  _______,                          _______, _______, _______, _______, _______,    KC_F12,
    _______, _______,  KC_LEFT,  KC_DOWN,   KC_RGHT,  _______,                          _______, _______, _______, _______, _______,   KC_PIPE,
    _______, _______,  KC_PGDN,  _______,    KC_END,  _______,  _______,       _______, _______, _______, _______, _______, _______,   _______,
                       KC_APP,  _______,   _______,  _______,  _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET| Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MacWin|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |  F11 | F12  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUNCTION] = LAYOUT(
    _______,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    _______, _______, _______,  _______,  _______,  _______,                      _______,_______, _______,  KC_F11,  KC_F12, _______,
    _______, _______, _______,  _______,  _______,  _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______,  _______,  _______,  _______,  _______,         KC_MSEL, _______, _______, _______, _______, _______, _______,
                      _______,  _______,  _______,  _______,  _______,       _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case KC_LOWER: */
/*             if (record->event.pressed) { */
/*                 layer_on(_LOWER); */
/*                 update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*             } else { */
/*                 layer_off(_LOWER); */
/*                 update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*             } */
/*             return false; */
/*         case KC_RAISE: */
/*             if (record->event.pressed) { */
/*                 layer_on(_RAISE); */
/*                 update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*             } else { */
/*                 layer_off(_RAISE); */
/*                 update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*             } */
/*             return false; */
/*         case KC_ADJUST: */
/*             if (record->event.pressed) { */
/*                 layer_on(_ADJUST); */
/*             } else { */
/*                 layer_off(_ADJUST); */
/*             } */
/*             return false; */
/*         case KC_PRVWD: */
/*             if (record->event.pressed) { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     register_mods(mod_config(MOD_LALT)); */
/*                     register_code(KC_LEFT); */
/*                 } else { */
/*                     register_mods(mod_config(MOD_LCTL)); */
/*                     register_code(KC_LEFT); */
/*                 } */
/*             } else { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     unregister_mods(mod_config(MOD_LALT)); */
/*                     unregister_code(KC_LEFT); */
/*                 } else { */
/*                     unregister_mods(mod_config(MOD_LCTL)); */
/*                     unregister_code(KC_LEFT); */
/*                 } */
/*             } */
/*             return false; */
/*         case KC_NXTWD: */
/*              if (record->event.pressed) { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     register_mods(mod_config(MOD_LALT)); */
/*                     register_code(KC_RIGHT); */
/*                 } else { */
/*                     register_mods(mod_config(MOD_LCTL)); */
/*                     register_code(KC_RIGHT); */
/*                 } */
/*             } else { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     unregister_mods(mod_config(MOD_LALT)); */
/*                     unregister_code(KC_RIGHT); */
/*                 } else { */
/*                     unregister_mods(mod_config(MOD_LCTL)); */
/*                     unregister_code(KC_RIGHT); */
/*                 } */
/*             } */
/*             return false; */
/*         case KC_LSTRT: */
/*             if (record->event.pressed) { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                      // CMD-arrow on Mac, but we have CTL and GUI swapped */
/*                     register_mods(mod_config(MOD_LCTL)); */
/*                     register_code(KC_LEFT); */
/*                 } else { */
/*                     register_code(KC_HOME); */
/*                 } */
/*             } else { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     unregister_mods(mod_config(MOD_LCTL)); */
/*                     unregister_code(KC_LEFT); */
/*                 } else { */
/*                     unregister_code(KC_HOME); */
/*                 } */
/*             } */
/*             return false; */
/*         case KC_LEND: */
/*             if (record->event.pressed) { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     // CMD-arrow on Mac, but we have CTL and GUI swapped */
/*                     register_mods(mod_config(MOD_LCTL)); */
/*                     register_code(KC_RIGHT); */
/*                 } else { */
/*                     register_code(KC_END); */
/*                 } */
/*             } else { */
/*                 if (keymap_config.swap_lctl_lgui) { */
/*                     unregister_mods(mod_config(MOD_LCTL)); */
/*                     unregister_code(KC_RIGHT); */
/*                 } else { */
/*                     unregister_code(KC_END); */
/*                 } */
/*             } */
/*             return false; */
/*         case KC_DLINE: */
/*             if (record->event.pressed) { */
/*                 register_mods(mod_config(MOD_LCTL)); */
/*                 register_code(KC_BSPC); */
/*             } else { */
/*                 unregister_mods(mod_config(MOD_LCTL)); */
/*                 unregister_code(KC_BSPC); */
/*             } */
/*             return false; */
/*         case KC_COPY: */
/*             if (record->event.pressed) { */
/*                 // CMD-c on Mac, but we have CTL and GUI swapped */
/*                 register_mods(mod_config(MOD_LCTL)); */
/*                 register_code(KC_C); */
/*             } else { */
/*                 unregister_mods(mod_config(MOD_LCTL)); */
/*                 unregister_code(KC_C); */
/*             } */
/*             return false; */
/*         case KC_PASTE: */
/*             if (record->event.pressed) { */
/*                 // CMD-v on Mac, but we have CTL and GUI swapped */
/*                 register_mods(mod_config(MOD_LCTL)); */
/*                 register_code(KC_V); */
/*             } else { */
/*                 unregister_mods(mod_config(MOD_LCTL)); */
/*                 unregister_code(KC_V); */
/*             } */
/*             return false; */
/*         case KC_CUT: */
/*             if (record->event.pressed) { */
/*                 // CMD-x on Mac, but we have CTL and GUI swapped */
/*                 register_mods(mod_config(MOD_LCTL)); */
/*                 register_code(KC_X); */
/*             } else { */
/*                 unregister_mods(mod_config(MOD_LCTL)); */
/*                 unregister_code(KC_X); */
/*             } */
/*             return false; */
/*             return false; */
/*         case KC_UNDO: */
/*             if (record->event.pressed) { */
/*                 // CMD-z on Mac, but we have CTL and GUI swapped */
/*                 register_mods(mod_config(MOD_LCTL)); */
/*                 register_code(KC_Z); */
/*             } else { */
/*                 unregister_mods(mod_config(MOD_LCTL)); */
/*                 unregister_code(KC_Z); */
/*             } */
/*             return false; */
/*         default: */
/*             return true; */
/*     } */
/* } */

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    if (get_highest_layer(layer_state) == _ADJUST) {
        uint8_t mode  = rgb_matrix_get_mode();
        HSV     hsv   = rgb_matrix_get_hsv();
        uint8_t speed = rgb_matrix_get_speed();

        if (keymap_config.swap_lctl_lgui) {
            oled_write_ln_P(PSTR("MAC\n"), false);
        } else {
            oled_write_ln_P(PSTR("WIN\n"), false);
        }

        oled_write_ln("RGB", false);
        write_int_ln(PSTR("Mo"), mode);
        write_int_ln(PSTR("H "), hsv.h);
        write_int_ln(PSTR("S "), hsv.s);
        write_int_ln(PSTR("V "), hsv.v);
        write_int_ln(PSTR("Sp"), speed);
        oled_write_P(PSTR("\n\n\n"), false);
    } else {
        oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        if (led_usb_state.caps_lock) {
            oled_write_ln_P(PSTR(" CAP "), true);
        } else {
            oled_write_ln_P(PSTR("     "), false);
        }
    }

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Alpha"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_QUOT):
            return TAPPING_TERM - 50;
        case RCTL_T(KC_ENT):
            return TAPPING_TERM - 50;
        case RALT_T(KC_L):
	    return TAPPING_TERM + 50;
        case LALT_T(KC_S):
	    return TAPPING_TERM + 50;
        case RGUI_T(KC_K):
	    return TAPPING_TERM + 50;
        case LGUI_T(KC_D):
	    return TAPPING_TERM + 50;
        case RCTL_T(KC_SCLN):
	    return TAPPING_TERM - 50;
        case LCTL_T(KC_A):
	    return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
