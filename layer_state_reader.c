#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "lily58.h"

#define L_QWERTY 0
#define L_ALSO_QWERTY (1 << 0)
#define L_COLEMAK (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_QWERTY:
        case L_ALSO_QWERTY:
            snprintf(layer_state_str, sizeof(layer_state_str), "QWERT");
            break;
        case L_COLEMAK:
            snprintf(layer_state_str, sizeof(layer_state_str), "COLEM");
            break;
        case L_COLEMAK | L_LOWER:
        case L_LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "LOWER");
            break;
        case L_COLEMAK | L_RAISE:
        case L_RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "RAISE");
            break;
        case L_ADJUST:
        case L_ADJUST_TRI:
        case L_COLEMAK | L_ADJUST:
        case L_COLEMAK | L_ADJUST_TRI:
            snprintf(layer_state_str, sizeof(layer_state_str), " ADJ ");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "UNDEF:%u", layer_state);
    }

    return layer_state_str;
}
