#ifndef triangle_H
#define triangle_H
#include "vec3.h"
#include "rgb.h"
#include "line.h"

class triangle {
    public:
        vec3 p0;
        vec3 p1;
        vec3 p2;
        rgb color;
        
        // normal vector
        vec3 n;

        triangle& operator += (vec3 A);
        triangle& operator -= (vec3 A);
        triangle operator + (vec3 A);
        triangle operator - (vec3 A);

        triangle(vec3 P0, vec3 P1, vec3 P2, rgb COLOR);
        triangle(vec3 P0, vec3 P1, vec3 P2);

        void normal();
        float intersection(line LINE);
};

#endif