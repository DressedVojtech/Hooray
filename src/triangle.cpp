#include "triangle.h"
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

#define π 3.1415926535897932384624338327595028841971

bool approxEquals(float A, float B, float C) {
    return abs(A - B) < C;
}

void triangle::operator += (vec3 A) {
    p0 += A;
    p1 += A;
    p2 += A;
}
triangle::triangle() {
    p0 = vec3();
    p1 = vec3();
    p2 = vec3();
    color = rgb();
}

triangle::triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR, std::string TEXTURE, vec2 VT0, vec2 VT1, vec2 VT2) {
    p0 = P0;
    p1 = P1;
    p2 = P2;
    color = COLOR;
    texture = TEXTURE;
    vt0 = VT0;
    vt1 = VT1;
    vt2 = VT2;
    normal();
}

triangle::triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR) {
    p0 = P0;
    p1 = P1;
    p2 = P2;
    color = COLOR;
}


void triangle::normal(vec3 NORMAL) {
    n = NORMAL;
}

void triangle::normal() {
        vec3 A = p0 - p2;
        vec3 B = p0 - p1;
        n = A.cross_product(B);
}

vec3 triangle::intersection(ray RAY) {
    vec3 P;
    normal();
    if (n.dot_product(RAY.direction) == 0) return vec3(true);
    float t =  - (n.dot_product(RAY.origin) - n.dot_product(p0)) / n.dot_product(RAY.direction);
    P = RAY.origin + RAY.direction*t;
    if (t < 0) return vec3(true);
    vec3 P0 = p0 - P;
    vec3 P1 = p1 - P;
    vec3 P2 = p2 - P;
    if (approxEquals((P0.angle(P1)) + (P1.angle(P2)) + (P0.angle(P2)), 2 * π, 0.1)) return {P};
    return vec3(true);
}
