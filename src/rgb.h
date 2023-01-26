#ifndef rgb_H
#define rgb_H

class rgb {
    public:
        float r;
        float g;
        float b;

        rgb operator + (rgb A);

        void check();
        void dim(float a);
};

#endif