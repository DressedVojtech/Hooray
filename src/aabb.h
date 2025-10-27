#ifndef AABB_H
#define AABB_H

#include "vec3.h"
#include <cfloat>   // for FLT_MAX
#include <algorithm>
#include "line.h"

class AABB {
public:
    vec3 min;
    vec3 max;

    AABB();
    void expand(const vec3& p);
    void merge(const AABB& other);
    bool hit(line RAY, float tMin, float tMax) const;
};

#endif
