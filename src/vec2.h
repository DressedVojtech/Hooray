#ifndef vec2_H
#define vec2_H
#include <math.h>

class vec2 {
    public:
        float x;
        float y;

        vec2 operator +(vec2 A);
        vec2 operator -(vec2 A);
        vec2 operator *(vec2 A);
        vec2 operator /(vec2 A);

        vec2();
        vec2(float X, float Y);
};

#endif