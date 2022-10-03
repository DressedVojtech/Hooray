#ifndef triangle_H
#define triangle_H
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

#define PI 3.1415926535897932384624338327595028841971

class triangle {
    public:
    vec3 p0;
    vec3 p1;
    vec3 p2;
    vec2 vt0;
    vec2 vt1;
    vec2 vt2;
    rgb color;
    std::string texture;

    struct vec3b {
        vec3 P;
        bool hit;
    };

    vec3 normal();
    vec3b intersection(ray Ray);
    void rotate(float angle, char axis);
    triangle operator + (vec3 A);
};

#endif