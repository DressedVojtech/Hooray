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
void vec2::rotate(float angle) {
    x = (pow(x, 2) + pow(y, 2)) * sin(atan(x/y) + angle);
    y = (pow(x, 2) + pow(y, 2)) * cos(atan(x/y) + angle);
}