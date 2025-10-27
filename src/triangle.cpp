#include "triangle.h"
#include <float.h>

triangle::triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR) {
    p0 = vec3(P0);
    p1 = vec3(P1);
    p2 = vec3(P2);
    color = rgb(COLOR);
    normal();
}

triangle::triangle(vec3 P0, vec3 P1, vec3 P2) {
    p0 = vec3(P0);
    p1 = vec3(P1);
    p2 = vec3(P2);
    color = rgb();
    normal();
}

triangle& triangle::operator += (vec3 A) {
    p0 += A; p1 += A; p2 += A;
    return *this;
}

triangle& triangle::operator -= (vec3 A) {
    p0 -= A; p1 -= A; p2 -= A;
    return *this;
}

triangle triangle::operator + (vec3 A) {
    return triangle(p0 + A, p1 + A, p2 + A);
}

triangle triangle::operator - (vec3 A) {
    return triangle(p0 - A, p1 - A, p2 - A);
}

void triangle::normal() {
        vec3 A = p0 - p2;
        vec3 B = p0 - p1;
        n = A % B;
}

float triangle::intersection(line LINE) {
    const float EPS = 1e-7f;

    vec3 v0v1 = p1 - p0;
    vec3 v0v2 = p2 - p0;

    vec3 pvec = LINE.dir % v0v2;         
    float det = v0v1 * pvec;              

    if (det > -EPS && det < EPS)
        return FLT_MAX;

    float invDet = 1.0f / det;

    vec3 tvec = LINE.org - p0;
    float u = (tvec * pvec) * invDet;     
    if (u < 0.0f || u > 1.0f)
        return FLT_MAX;

    vec3 qvec = tvec % v0v1;              
    float v = (LINE.dir * qvec) * invDet; 
    if (v < 0.0f || (u + v) > 1.0f)
        return FLT_MAX;

    float t = (v0v2 * qvec) * invDet;     
    if (t <= 1e-5f)                       
        return FLT_MAX;

    return t;
}
