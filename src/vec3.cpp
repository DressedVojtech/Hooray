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

vec3 vec3::operator / (vec3 A) {
    vec3 res = {x / A.x, y / A.y, z / A.z};
    return res;
}

void vec3::rotate(float angle, char axis) {
    if(axis == x) {
        y = (pow(y, 2) + pow(z, 2)) * cos(atan(y/z) + angle);
        z = (pow(y, 2) + pow(z, 2)) * sin(atan(y/z) + angle);
    } else if (axis == y) {
        x = (pow(x, 2) + pow(z, 2)) * cos(atan(x/z) + angle);
        z = (pow(x, 2) + pow(z, 2)) * sin(atan(x/z) + angle);
    } else if (asix == z) {
        x = (pow(x, 2) + pow(y, 2)) * sin(atan(x/y) + angle);
        y = (pow(x, 2) + pow(y, 2)) * cos(atan(x/y) + angle);
    }
}
vec3 vec3::cross_product(vec3 A, vec3 B) {
    vec3 product = {A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x};
    return product;
}
float vec3::dot_product(vec3 A, vec3 B) {
    return (A.x * B.x + A.y * B.y + A.z * B.z);
}
float vec3::distance_of_two_points(vec3 A, vec3 B) {
    return sqrt(pow(point.x - point2.x, 2) + pow(point.y - point2.y, 2) + pow(point.z - point2.z, 2));
}
