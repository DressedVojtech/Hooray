#include "rgba.h"
#include "rgb.h"

rgba rgba::operator + (rgb A) {
    return rgba(A.r + r, A.g + g, A.b + b, 1);
}

rgba rgba::operator+(rgba A) {
    float alphaBlend = 1.0 - (1.0 - a) * (1.0 - A.a);
    float rResult = (r * a + A.r * A.a * (1.0 - a)) / alphaBlend;
    float gResult = (g * a + A.g * A.a * (1.0 - a)) / alphaBlend;
    float bResult = (b * a + A.b * A.a * (1.0 - a)) / alphaBlend;
    return rgba(rResult, gResult, bResult, alphaBlend);
}

rgba::rgba() {
    r = 0;
    g = 0;
    b = 0;
    a = 1;
}

rgba::rgba(float R, float G, float B, float A) {
    r = R;
    g = G;
    b = B;
    a = A;
}

rgba::rgba(rgb RGB) {
    r = RGB.r;
    g = RGB.g;
    b = RGB.b;
    a = 1;
}

void rgba::clip() {
    if(r < 0) {
        r = 0;
    } else if (r > 255) {
        r = 255;
    }
    if(g < 0) {
        g = 0;
    } else if (g > 255) {
        g = 255;
    }
    if(b < 0) {
        b = 0;
    } else if (b > 255) {
        b = 255;
    }
    if (a < 0) {
        a = 0;
    } else if (a > 1) {
        a = 1;
    }
}

void rgba::dimm(float D) {
    r -= D;
    g -= D;
    b -= D;
    clip();
}

void rgba::translucify(float T) {
    a -= T;
    clip();
}