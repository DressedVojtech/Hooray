#ifndef triangle_H
#define triangle_H
#include "vec2.h"
#include "vec3.h"
#include "rgb.h"
#include "ray.h"
#include <string>

class triangle {
    public:
    vec3 p0;
    vec3 p1;
    vec3 p2;
    rgb color;
    std::string texture;
    vec2 vt0;
    vec2 vt1;
    vec2 vt2;
    vec3 n; //normal vector

    void normal(vec3 Normal);
    void normal();
    vec3 intersection(ray Ray);
    void rotate(float angle, char axis);
    triangle operator + (vec3 A);
};

#endif