#ifndef rgb_H
#define rgb_H

#include <stdexcept>

class rgb {
    public:
        float r;
        float g;
        float b;

        rgb();
        rgb(float R, float G, float B);
        rgb(int R, int G, int B);
        rgb(const rgb&);

        void clip();
        
        // plus
        rgb operator + (rgb A);
        rgb operator + (float A);
        rgb operator + (int A);

        // minus
        rgb operator - (rgb A);
        rgb operator - (float A);
        rgb operator - (int A);

        rgb& operator += (rgb A);
        rgb& operator += (float A);
        rgb& operator += (int A);

        rgb& operator -= (rgb A);
        rgb& operator -= (float A);
        rgb& operator -= (int A);
};

#endif