#ifndef rgb_H
#define rgb_H

class rgb {
    public:
        float r;
        float g;
        float b;

        rgb operator + (rgb A);

        rgb();
        rgb(float R, float G, float B);
        rgb(int R, int G, int B);

        void check();
        void dimm(float a);
};

#endif