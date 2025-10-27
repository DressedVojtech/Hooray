#ifndef rgba_H
#define rgba_H

#include "rgb.h"

class rgba {
    public:
        rgb COLOR;
        float a;

        rgba();
        rgba(float R, float G, float B, float A);
        rgba(int R, int G, int B, int A);
        rgba(int R, int G, int B, float A);
        rgba(rgb RGB);
        rgba(rgb RGB, float A);
        rgba(rgb RGB, int A);

        void clip();

        // plus
        rgba operator + (rgba A);
        rgba operator + (rgb A);
        rgba operator + (float A);
        rgba operator + (int A);

        // minus
        rgba operator - (rgba A);
        rgba operator - (rgb A);
        rgba operator - (float A);
        rgba operator - (int A);

        rgba& operator += (rgba A);
        rgba& operator += (rgb A);
        rgba& operator += (float A);

        rgba& operator -= (rgba A);
        rgba& operator -= (rgb A);
        rgba& operator -= (float A);
};

#endif