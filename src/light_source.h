#ifndef light_source_H
#define light_source_H
#include "vec3.h"

class l_s {
    public:
        vec3 position;
        float intensity; // 0 ~ 0%, 1 ~ 100%
};

#endif