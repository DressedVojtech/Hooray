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

    void operator += (vec3 A);

    triangle();
    triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR, std::string TEXTURE, vec2 VT0, vec2 VT1, vec2 VT2);
    triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR);

    void normal(vec3 NORMAL);
    void normal();
    vec3 intersection(ray RAY);
};

#endif