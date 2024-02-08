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

        rgba();
        rgba(float R, float G, float B, float A);
        rgba(rgb RGB);

        void clip();
        void dimm(float D);
        void translucify(float T);
};

#endif