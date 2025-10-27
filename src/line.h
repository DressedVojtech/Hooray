#ifndef line_H
#define line_H
#include "vec3.h"

class line {
    public:
        vec3 org;
        vec3 dir;

        line();
        line(vec3 O, vec3 D);
        line(vec3 D);
};

#endif