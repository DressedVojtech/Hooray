#include "triangle.h"
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

const float PI = 3.1415926535897932384624338327595028841971;

bool approxEquals(float a, float b, float c) {
    return abs(a - b) < c;
}

vec3 triangle::normal() {
        vec3 A = p0 - p2;
        vec3 B = p0 - p1;
        vec3 normal = A.cross_product(B);
        return normal;
}

void triangle::rotate(float angle, char axis) {
    p0.rotate(angle, axis);
    p1.rotate(angle, axis);
    p2.rotate(angle, axis);
}

triangle::vec3b triangle::intersection(ray Ray) {
    vec3 P;
    vec3 N = normal();
    if (N.dot_product(Ray.direction) == 0) return {{P}, false};
    float t =  - (N.dot_product(Ray.origin) + N.dot_product(p0))/N.dot_product(Ray.direction);
    P = Ray.origin + Ray.direction*t;
    if (t < 0) return {{P}, false};
    vec3 P0 = p0 - P;
    vec3 P1 = p1 - P;
    vec3 P2 = p2 - P;
    if (approxEquals((P0.angle(P1)) + (P1.angle(P2)) + (P0.angle(P2)), 2 * PI, 0.1)) return {{P}, true};
    return {{P}, false};
}

triangle triangle::operator + (vec3 A) {
    triangle TRIANGLE;
    TRIANGLE.p0 = p0 + A;
    TRIANGLE.p1 = p1 + A;
    TRIANGLE.p2 = p2 + A;
    return TRIANGLE;
}