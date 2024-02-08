#include "vec3.h"
#include <math.h>

vec3 vec3::operator + (vec3 A) {
    vec3 res = {x + A.x, y + A.y, z + A.z};
    return res;
}

vec3 vec3::operator - (vec3 A) {
    vec3 res = {x - A.x, y - A.y, z - A.z};
    return res;
}

vec3 vec3::operator * (vec3 A) {
    vec3 res = {x * A.x, y * A.y, z * A.z};
    return res;
}

vec3 vec3::operator * (float a) {
    vec3 res = {x * a, y * a, z * a};
    return res;
}

vec3 vec3::operator / (vec3 A) {
    vec3 res = {x / A.x, y / A.y, z / A.z};
    return res;
}

bool vec3::operator != (vec3 A) {
    if (x == A.x && y == A.y && z == A.z) {
        return false;
    } else {
        return true;
    }
}

bool vec3::operator == (vec3 A) {
    if (x == A.x && y == A.y && z == A.z) return true;
    else return false;
}

vec3::vec3() {
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(bool ISNAN) {
    if (ISNAN) x = std::numeric_limits<double>::quiet_NaN();
    else vec3();
}

vec3::vec3(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
}

vec3 vec3::cross_product(vec3 A) {
    return {y * A.z - z * A.y, z * A.x - x * A.z, x * A.y - y * A.x};
}

float vec3::dot_product(vec3 A) {
    return (x * A.x + y * A.y + z * A.z);
}

float vec3::distance_from(vec3 A) {
    return sqrt(pow(x - A.x, 2) + pow(y - A.y, 2) + pow(z - A.z, 2));
}

float vec3::magnitude() {
    return sqrt(pow(x, 2) + pow (y, 2) + pow(z, 2));
}

float vec3::angle(vec3 A) {
    return acos(dot_product(A)/(magnitude() * A.magnitude()));
}

