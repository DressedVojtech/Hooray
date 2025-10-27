#include "rgb.h"

rgb::rgb(const rgb&) = default;

rgb::rgb() {
    r = 0;
    g = 0;
    b = 0;
}

rgb::rgb(float R, float G, float B) {
    r = R;
    g = G;
    b = B;
}

rgb::rgb(int R, int G, int B)
    :rgb(static_cast<float>(R), static_cast<float>(G), static_cast<float>(B)){}

void rgb::clip() {
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

rgb rgb::operator + (rgb A) {
    rgb B(A.r + r, A.g + g, A.b + b);
    B.clip();
    return B;
}

rgb rgb::operator + (float A) {
    rgb B(A + r, A + g, A + b);
    B.clip();
    return B;
}

rgb rgb::operator + (int A) {
    rgb B(r + static_cast<float>(A), g + static_cast<float>(A), b + static_cast<float>(A));
    B.clip();
    return B;
}

rgb rgb::operator - (rgb A) {
    rgb B(r - A.r, g - A.g, b - A.b);
    B.clip();
    return B;
}

rgb rgb::operator - (float A) {
    rgb B(r - A, g - A, b - A);
    B.clip();
    return B;
}

rgb rgb::operator - (int A) {
    rgb B(r - static_cast<float>(A), g - static_cast<float>(A), b - static_cast<float>(A));
    B.clip();
    return B;
}

rgb& rgb::operator += (rgb A) {
    r += A.r; g += A.g; b += A.b;
    clip();
    return *this;
}

rgb& rgb::operator += (float A) {
    r += A; g += A; b += A;
    clip();
    return *this;
}

rgb& rgb::operator += (int A) {
    r += static_cast<float>(A); g += static_cast<float>(A); b += static_cast<float>(A);
    clip();
    return *this;
}

rgb& rgb::operator -= (rgb A) {
    r -= A.r; g -= A.g; b -= A.b;
    clip();
    return *this;
}

rgb& rgb::operator -= (float A) {
    r -= A; g -= A; b -= A;
    clip();
    return *this;
}

rgb& rgb::operator -= (int A) {
    r -= static_cast<float>(A); g -= static_cast<float>(A); b -= static_cast<float>(A);
    clip();
    return *this;
}

