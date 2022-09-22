#ifndef vec3_H
#define vec3_H
#include <iostream>
#include <math.h>


class vec3 {
    public:
        float x;
        float y;
        float z;

        vec3 operator +(vec3 A);
        vec3 operator -(vec3 A);
        vec3 operator *(vec3 A);
        vec3 operator /(vec3 A);

        void rotate(float angle, char axis);
        vec3 cross_product(vec3 A, vec3 B);
        float dot_product(vec3 A, vec3 B);
        float distance_of_two_points(vec3 A, vec3 B);
};

#endif