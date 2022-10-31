#include "rgb.h"

rgb rgb::operator + (rgb A) {
    return {A.r + r, A.g + g, A.b + b};
}


void rgb::check() {
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
}

void rgb::dimm(float a) {
    r -= a;
    g -= a;
    b -= a;
    check();
}