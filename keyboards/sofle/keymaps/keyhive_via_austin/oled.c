/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

// Sets up what the OLED screens display.

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    // static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    // oled_write_P(qmk_logo, false);

    // static const char PROGMEM raw_logo[] = {
    //     0, 0, 0, 128, 128, 128, 128, 128, 128, 196, 252, 24, 48, 32, 96, 192, 192, 64, 64, 192, 128, 128, 128, 0, 0, 0, 0,   0,   0,   0,  0, 0, 0, 0, 128, 192, 224, 240, 112, 120, 56, 56, 56, 120, 112, 240, 224, 192, 128, 0, 0,   0,   0,  0,  0,   0,   0,   0,   0,  0,   0,   0, 0, 0, 0, 0, 14, 30, 255, 255, 239, 15, 15, 14, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 14, 28, 60, 120, 240, 192, 128, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192, 192, 192, 224, 224, 240, 248, 12, 0, 0, 224, 224, 224, 224, 192, 0, 0, 0, 192, 0, 129, 129, 129, 129, 129, 129, 129, 129, 129, 195, 127, 0, 0, 0, 0, 129, 195, 0, 0, 0, 0, 129, 129, 129, 195, 66, 102, 36, 24, 0, 0, 0, 14, 15, 7, 3, 0, 0, 96, 240, 248, 248, 240, 96, 0, 0, 3, 15, 255, 254, 252, 60, 56, 56, 56, 56, 56, 56, 56, 56, 56, 16, 0,
    //     0, 0, 0, 0,   255, 255, 255, 0,   0,   0,   49,  49, 49, 49, 49, 49,  49,  49, 49, 49,  49,  49,  48,  0, 0, 0, 195, 255, 255, 28, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,  0,  0,  0,   0,   0,   0,   0,   1,   3, 143, 156, 24, 48, 115, 115, 115, 115, 56, 152, 206, 7, 3, 0, 0, 0, 1,  1,  1,   1,   1,   1,  35, 63, 24,  12,  4,   6,   3,   3,   2,   2,   3,   1,   1,   1,   0,  0,  0,  0,   0,   0,   0,   0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   1,   1,   0,   0,   0,   0,   24,  31,  7,   1,   0,   0,  0, 0, 0,   0,   0,   0,   0,   0, 0, 0, 0,   0, 0,   0,   0,   63,  127, 63,  0,   0,   0,   6,   6,   6, 6, 6, 6, 6,   6,   6, 6, 6, 6, 0,   0,   0,   8,   7,  3,   0,  0,  0, 0, 0, 0,  0,  0, 0, 0, 0, 0,  0,   0,   0,   0,   0,  0, 0, 4, 6,  3,   3,   1,   1,  1,  7,  31, 3,  1,  1,  1,  3,  6,  4,
    // };
    static const char PROGMEM raw_logo[] = {
        32, 96, 192, 128, 128, 128, 192, 248, 224, 128, 128, 128, 192, 192, 96,  32,  0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0,   0,   0,   0,   0, 0, 0, 0,  0,  192, 224, 16,  0,   0,   0,   96, 96, 96, 96, 96,  96,  96, 96, 96, 96, 96,  96,  0,   0,   0,   252, 254, 252, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0,  0,  128, 224, 248, 24, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,   128, 128, 128, 192, 64,  192, 192, 192, 96,  32,  48,  24,  252, 196, 128, 128, 128, 128, 128, 128, 0, 0, 0, 192, 224, 115, 25, 28, 142, 206, 206, 142, 12, 24, 57, 241, 192, 128, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 56, 255, 255, 195, 0, 0, 0, 12, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 0,  0, 0, 255, 255, 255, 0, 0, 0, 0, 0,
        8,  28, 28,  28,  28,  28,  28,  28,  28,  28,  60,  63,  127, 255, 240, 192, 0, 0, 6, 15, 31, 31, 15, 6, 0, 0, 192, 224, 240, 112, 0, 0, 0, 24, 36, 102, 66,  195, 129, 129, 129, 0,  0,  0,  0,  195, 129, 0,  0,  0,  0,  254, 195, 129, 129, 129, 129, 129, 129, 129, 129, 129, 0, 3, 0, 0, 0, 3, 7, 15, 15, 7, 3, 0, 48, 31, 15,  7,   7,   3,  3, 3, 3, 3, 3,   3,   1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 3, 15, 30, 60, 56, 112, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 112, 240, 240, 247, 255, 255, 120, 112, 0, 0, 0, 0,   0,   0,   0,  0,  0,   0,   0,   0,   0,  0,  0,  0,   0,   1,   3, 7, 15, 14, 30, 28, 28, 28, 30, 14, 15, 7, 3, 1, 0, 0, 0, 0, 0,  0,   0,   0,   0, 0, 0, 1,  1,   1,   3,   2,   3,   3,   3,   6,   4,   12,  24,  63,  35, 1, 1, 1,   1,   1,   1, 0, 0, 0,
    };

    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
        // render_logo();
    } else {
        render_logo();
        // print_status_narrow();
    }
}

#endif