#include "rgba.h"
#include "rgb.h"

// rgba rgba::operator + (rgb A) {
//     return {A.r + r, A.g + g, A.b + b, 255};
// }

rgba rgba::operator + (rgba A) {
    return {A.r + r, A.g + g, A.b + b, A.a + a};
}

void rgba::to_rgba(rgb A) {
    return {A.r, A.g, A.b, 255};
}

void rgba::check() {
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
    } else if (a > 255) {
        a = 255
    }
}

void rgba::dimm(float a) {
    r -= a;
    g -= a;
    b -= a;
    check();
}

void rgba::translucify(float i) {
    a -= i;
    check();
}