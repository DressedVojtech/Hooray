#ifndef rgba_H
#define rgba_H

#include "rgb.h"

class rgba {
    public:
        float r;
        float g;
        float b;
        float a;

        rgba operator + (rgba A);
        rgba operator + (rgb A);

        void check();
        void dimm(float i);
        void to_rgba(rgb A);
};

#endif