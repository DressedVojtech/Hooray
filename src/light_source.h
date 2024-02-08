#ifndef light_source_H
#define light_source_H
#include "vec3.h"

class light_source {
    public:
        vec3 position;
        float intensity; // 0 ~ 0%, 1 ~ 100%

        light_source();
        light_source(vec3 P, float I);
};

#endif