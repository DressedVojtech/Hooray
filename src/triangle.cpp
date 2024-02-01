#include "triangle.h"
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

#define π 3.1415926535897932384624338327595028841971

bool approxEquals(float a, float b, float c) {
    return abs(a - b) < c;
}

void triangle::normal(vec3 Normal) {
    n = Normal;
}

void triangle::normal() {
        vec3 A = p0 - p2;
        vec3 B = p0 - p1;
        n = A.cross_product(B);
}

void triangle::rotate(float angle, char axis) {
    p0.rotate(angle, axis);
    p1.rotate(angle, axis);
    p2.rotate(angle, axis);
}

vec3 triangle::intersection(ray Ray) {
    vec3 P;
    normal();
    if (n.dot_product(Ray.direction) == 0) return {NULL, NULL, NULL};
    float t =  - (n.dot_product(Ray.origin) - n.dot_product(p0)) / n.dot_product(Ray.direction);
    P = Ray.origin + Ray.direction*t;
    if (t < 0) return {NULL, NULL, NULL};
    vec3 P0 = p0 - P;
    vec3 P1 = p1 - P;
    vec3 P2 = p2 - P;
    if (approxEquals((P0.angle(P1)) + (P1.angle(P2)) + (P0.angle(P2)), 2 * π, 0.1)) return {P};
    return {NULL, NULL, NULL};
}
