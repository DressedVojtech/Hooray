#ifndef vec3_H
#define vec3_H
#include <iostream>
#include <math.h>


class vec3 {
    public:
        float x;
        float y;
        float z;

        vec3();
        vec3(float X, float Y, float Z);
        vec3(int X, int Y, int Z);
        vec3(const vec3&);

        vec3  operator + (vec3 A);
        vec3  operator + (float A);
        vec3  operator - (vec3 A);
        vec3  operator - (float A);
        float operator * (vec3 A); // dot
        vec3  operator % (vec3 A); // cross
        vec3  operator * (float a);
        vec3  operator / (float A);

        vec3& operator += (vec3 A);
        vec3& operator -= (vec3 A);
        bool operator == (vec3 A);
        bool operator != (vec3 A);

        float distance(vec3 B);
        float magnitude();
};

#endif