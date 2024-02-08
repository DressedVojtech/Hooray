#include "vec2.h"
#include <math.h>

vec2 vec2::operator + (vec2 A) {
    vec2 res = {x + A.x, y + A.y};
    return res;
}

vec2 vec2::operator - (vec2 A) {
    vec2 res = {x - A.x, y - A.y};
    return res;
}

vec2 vec2::operator * (vec2 A) {
    vec2 res = {x * A.x, y * A.y};
    return res;
}

vec2 vec2::operator / (vec2 A) {
    vec2 res = {x / A.x, y / A.y};
    return res;
}

vec2::vec2() {
    x = 0;
    y = 0;
}

vec2::vec2(float X, float Y) {
    x = X;
    y = Y;
}
