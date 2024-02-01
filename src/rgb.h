#ifndef rgb_H
#define rgb_H
#include "rgba.h"

class rgb {
    public:
        float r;
        float g;
        float b;

        rgb operator + (rgb A);

        void check();
        void dimm(float a);
};

#endif