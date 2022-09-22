#ifndef vec2_H
#define vec2_H

class vec2 {
    public:
        float x;
        float y;

        vec2 operator +(vec2 A);
        vec2 operator -(vec2 A);
        vec2 operator *(vec2 A);
        vec2 operator /(vec2 A);

        void rotate(float angle);
};

#endif