#pragma once
#include "raylib.h"

// Colors
const Color red = { 232, 18, 18, 255 };
const Color blue = { 13, 64, 216, 255 };
const Color green = { 47, 230, 23, 255 };
const Color purple = { 166, 0, 247, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color dark_gray = { 26, 31, 40, 255 };
const Color EMPTY_COLOR = dark_gray;
const Color yellow = { 237, 234, 4, 255 };
const Color cyan = { 21, 204, 209, 255 };

inline bool operator==(const Color& c1, const Color& c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}
