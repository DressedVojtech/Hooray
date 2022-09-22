#include "triangle.h"
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

#define PI 3.1415926535897932384624338327595028841971

void triangle::rotate(float angle, char axis) {
    p0.rotate(angle, axis);
    p1.rotate(angle, axis);
    p2.rotate(angle, axis);
}

vec3b triangle::intersection(ray Ray) {
    vec3 P = {-1, -1, -1};
        if (dot_product(N, Ray.direction) == 0) return {{P}, 0};
    float t = - (dot_product(normal(), Ray.origin) + dot_product(N, p0))/dot_product(N, Ray.direction);
    P = Ray.origin + t*Ray.direction;
        if (t < 0) return {{P}, false};
        if ((angle(p0 - P, p1 - P) / 180 * PI) + (angle(p1 - P, p2 - P) / 180 * PI) + (angle(p0 - P, p2 - P) / 180 * PI) == 360) return {{P}, true};
    return {{P}, false};
}