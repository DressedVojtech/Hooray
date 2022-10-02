#include "triangle.h"
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

#define PI 3.1415926535897932384624338327595028841971

vec3 triangle::normal() {
        vec3 U = p2 - p1;
        vec3 V = p0 - p1;
        vec3 normal = U.cross_product(V);
        return normal;
}

void triangle::rotate(float angle, char axis) {
    p0.rotate(angle, axis);
    p1.rotate(angle, axis);
    p2.rotate(angle, axis);
}

triangle::vec3b triangle::intersection(ray Ray) {
    vec3 P = {-1, -1, -1};
    vec3 N = normal();
        if (N.dot_product(Ray.direction) == 0) return {{P}, 0};
    float t = - (N.dot_product(Ray.origin) + N.dot_product(p0))/N.dot_product(Ray.direction);
    P = Ray.origin + Ray.direction*t;
        if (t < 0) return {{P}, false};
        vec3 P0 = p0 - P;
        vec3 P1 = p1 - P;
        vec3 P2 = p2 - P;
        if ((P0.angle(P1) / 180 * PI) + (P1.angle(P2) / 180 * PI) + (P0.angle(P2) / 180 * PI) == 360) return {{P}, true};
    return {{P}, false};
}