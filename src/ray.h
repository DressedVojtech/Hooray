#ifndef ray_H
#define ray_H
#include "vec3.h"

class ray {
    public:
        vec3 origin;
        vec3 direction;

        ray();
        ray(vec3 O, vec3 D);
};

#endif