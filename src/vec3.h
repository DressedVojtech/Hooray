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
        vec3 operator *(float a);
        vec3 operator /(vec3 A);
        void operator +=(vec3 A);
        bool operator ==(vec3 A);
        bool operator !=(vec3 A);

        vec3();
        vec3(bool ISNAN);
        vec3(float X, float Y, float Z);

        vec3 cross_product(vec3 B);
        float dot_product(vec3 B);
        float distance_from(vec3 B);
        float magnitude();
        float angle(vec3 B);
};

#endif