#include "vec3.h"
#include <math.h>

vec3 vec3::operator + (vec3 A) {
    vec3 res = {x + x, y + y, z + z};
    return res;
}

vec3 vec3::operator - (vec3 A) {
    vec3 res = {x - x, y - y, z - z};
    return res;
}

vec3 vec3::operator * (vec3 A) {
    vec3 res = {x * x, y * y, z * z};
    return res;
}

vec3 vec3::operator * (float a) {
    vec3 res = {x * a, y * a, z * a};
    return res;
}

vec3 vec3::operator / (vec3 A) {
    vec3 res = {x / x, y / y, z / z};
    return res;
}

void vec3::rotate(float angle, char axis) {
    if(axis == x) {
        y = (pow(y, 2) + pow(z, 2)) * cos(atan(y/z) + angle);
        z = (pow(y, 2) + pow(z, 2)) * sin(atan(y/z) + angle);
    } else if (axis == y) {
        x = (pow(x, 2) + pow(z, 2)) * cos(atan(x/z) + angle);
        z = (pow(x, 2) + pow(z, 2)) * sin(atan(x/z) + angle);
    } else if (axis == z) {
        x = (pow(x, 2) + pow(y, 2)) * sin(atan(x/y) + angle);
        y = (pow(x, 2) + pow(y, 2)) * cos(atan(x/y) + angle);
    }
}
vec3 vec3::cross_product(vec3 B) {
    return {y * B.z - z * B.y, z * B.x - x * B.z, x * B.y - y * B.x};
}
float vec3::dot_product(vec3 B) {
    return (x * B.x + y * B.y + z * B.z);
}
float vec3::distance_from(vec3 B) {
    return sqrt(pow(x - B.x, 2) + pow(y - B.y, 2) + pow(z - B.z, 2));
}
float vec3::magnitude() {
    return sqrt(pow(x, 2) + pow (y, 2) + pow(z, 2));
}
float vec3::angle(vec3 B) {
    return acos(dot_product(B)/(magnitude() * B.magnitude()));
}