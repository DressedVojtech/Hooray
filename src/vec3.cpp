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
