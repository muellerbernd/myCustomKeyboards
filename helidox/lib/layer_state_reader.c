
#include QMK_KEYBOARD_H
#include "myHelidox.h"
#include <stdio.h>

#define L_BASE 0
#define L_BASE2 2
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_NAV (1 << 4)
#define L_ADJUST (1 << 5)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void)
{
    switch (layer_state)
    {
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTZ");
            break;
        case L_BASE2:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: DVORAK");
            break;
        case L_NAV:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
            break;
        case L_RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
            break;
        case L_LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
            break;
        case L_ADJUST:
        case L_ADJUST_TRI:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str),
                     "Layer: Undef-%d", layer_state);
    }

    return layer_state_str;
}
