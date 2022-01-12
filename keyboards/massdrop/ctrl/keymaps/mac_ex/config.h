#pragma once

#include "config_common.h"

#undef NKRO_ENABLE // not compatible with Apple Fn key
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_COLOR_MODO2 150,220,212
#define RGBLIGHT_LIMIT_VAL 200
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#define HSV_COLOR_MODO2 84,200,200
#define HSV_COLOR_CAPS 247,175,216
#define APPLE_KEYBOARD
#undef VENDOR_ID
#define VENDOR_ID 0x05ac
#undef PRODUCT_ID
#define PRODUCT_ID 0x024f
