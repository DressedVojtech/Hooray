#include "rgba.h"

// Constructors

rgba::rgba() : COLOR(0,0,0), a(1) {}

rgba::rgba(float R, float G, float B, float A) : COLOR(R,G,B), a(A) {}

rgba::rgba(int R, int G, int B, int A)
: COLOR(R, G, B), a(static_cast<float>(A)) {}

rgba::rgba(int R, int G, int B, float A)
: COLOR(R, G, B), a(A) {}

rgba::rgba(rgb RGB) : COLOR(RGB), a(1) {}

rgba::rgba(rgb RGB, float A) : COLOR(RGB), a(A) {}

rgba::rgba(rgb RGB, int A) : COLOR(RGB), a(static_cast<float>(A)) {}

void rgba::clip() {
    if(COLOR.r < 0) {
        COLOR.r = 0;
    } else if (COLOR.r > 255) {
        COLOR.r = 255;
    }
    if(COLOR.g < 0) {
        COLOR.g = 0;
    } else if (COLOR.g > 255) {
        COLOR.g = 255;
    }
    if(COLOR.b < 0) {
        COLOR.b = 0;
    } else if (COLOR.b > 255) {
        COLOR.b = 255;
    }
    if (a < 0) {
        a = 0;
    } else if (a > 1) {
        a = 1;
    }
}

// Operators 

rgba rgba::operator+(rgba A) {
    const float Af = A.a;       
    const float Ab = a;        
    const float oneMinusAf = 1.0f - Af;

    const float a_out = Af + Ab * oneMinusAf;
    if (a_out == 0.0f) {
        return rgba(0.0f, 0.0f, 0.0f, 0.0f);
    }

    const float r_out = (A.COLOR.r * Af + COLOR.r * Ab * oneMinusAf) / a_out;
    const float g_out = (A.COLOR.g * Af + COLOR.g * Ab * oneMinusAf) / a_out;
    const float b_out = (A.COLOR.b * Af + COLOR.b * Ab * oneMinusAf) / a_out;

    return rgba(r_out, g_out, b_out, a_out);
}

rgba rgba::operator + (rgb A) {
    return rgba(A.r + COLOR.r, A.g + COLOR.g, A.b + COLOR.b, a);
}

rgba rgba::operator + (float A) {
    rgba B(COLOR, a + A);
    B.clip();
    return B;
}

rgba rgba::operator + (int A) {
    if (A >= 1) {
        return rgba(COLOR, 1);
    }
    else return rgba(COLOR, 0);
}

rgba rgba::operator - (rgba A) {
    const float Af = A.a;       
    const float Ab = a;         
    const float oneMinusAb = 1.0f - Ab;

    const float a_out = Ab + Af * oneMinusAb;
    if (a_out == 0.0f) {
        return rgba(0.0f, 0.0f, 0.0f, 0.0f);
    }

    const float r_out = (COLOR.r * Ab + A.COLOR.r * Af * oneMinusAb) / a_out;
    const float g_out = (COLOR.g * Ab + A.COLOR.g * Af * oneMinusAb) / a_out;
    const float b_out = (COLOR.b * Ab + A.COLOR.b * Af * oneMinusAb) / a_out;

    return rgba(r_out, g_out, b_out, a_out);
}

rgba rgba::operator - (rgb A) {
    return rgba(COLOR.r - A.r, COLOR.g - A.g, COLOR.b - A.b, a);
}

rgba rgba::operator - (float A) {
    rgba B(COLOR, a - A);
    B.clip();
    return B;
}

rgba rgba::operator - (int A) {
    if (A <= 0) {
        return rgba(COLOR, 1);
    } else {
        return rgba(COLOR, 0);
    }
}

rgba& rgba::operator += (rgba A) {
    const float Af = A.a;       
    const float Ab = a;        
    const float oneMinusAf = 1.0f - Af;

    const float a_out = Af + Ab * oneMinusAf;
    if (a_out == 0.0f) {
        COLOR.r = COLOR.g = COLOR.b = a = 0.0f;
        return *this;
    }

    COLOR.r = (A.COLOR.r * Af + COLOR.r * Ab * oneMinusAf) / a_out;
    COLOR.g = (A.COLOR.g * Af + COLOR.g * Ab * oneMinusAf) / a_out;
    COLOR.b = (A.COLOR.b * Af + COLOR.b * Ab * oneMinusAf) / a_out;
    a = a_out;

    return *this;
}

rgba& rgba::operator += (rgb A) {
    COLOR.r += A.r;
    COLOR.g += A.g;
    COLOR.b += A.b;
    clip();
    return *this;
}

rgba& rgba::operator += (float A) {
    a += A;
    clip();
    return *this;
}

rgba& rgba::operator -= (rgba A) {
    const float Af = A.a;       
    const float Ab = a;       
    const float oneMinusAb = 1.0f - Ab;

    const float a_out = Ab + Af * oneMinusAb;
    if (a_out == 0.0f) {
        COLOR.r = COLOR.g = COLOR.b = a = 0.0f;
        return *this;
    }

    COLOR.r = (COLOR.r * Ab + A.COLOR.r * Af * oneMinusAb) / a_out;
    COLOR.g = (COLOR.g * Ab + A.COLOR.g * Af * oneMinusAb) / a_out;
    COLOR.b = (COLOR.b * Ab + A.COLOR.b * Af * oneMinusAb) / a_out;
    a = a_out;

    return *this;
}

rgba& rgba::operator -= (rgb A) {
    COLOR.r -= A.r;
    COLOR.g -= A.g;
    COLOR.b -= A.b;
    clip();
    return *this;
}

rgba& rgba::operator -= (float A) {
    a -= A;
    clip();
    return *this;
}