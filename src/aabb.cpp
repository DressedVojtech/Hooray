#include "aabb.h"

AABB::AABB() {
    min = vec3( FLT_MAX,  FLT_MAX,  FLT_MAX);
    max = vec3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
}

void AABB::expand(const vec3& p) {
    min.x = std::min(min.x, p.x);
    min.y = std::min(min.y, p.y);
    min.z = std::min(min.z, p.z);
    max.x = std::max(max.x, p.x);
    max.y = std::max(max.y, p.y);
    max.z = std::max(max.z, p.z);
}

void AABB::merge(const AABB& other) {
    expand(other.min);
    expand(other.max);
}

bool AABB::hit(line RAY, float tMin, float tMax) const {
    // const float EPS = 1e-8f;

    // auto comp = [](const vec3& v, int i)->float {
    //     return (i == 0 ? v.x : (i == 1 ? v.y : v.z));
    // };

    // for (int i = 0; i < 3; ++i) {
    //     float o   = comp(RAY.org, i);
    //     float d   = comp(RAY.dir, i);
    //     float mn  = comp(min, i);
    //     float mx  = comp(max, i);

    //     if (fabsf(d) < EPS) {
    //         if (o < mn || o > mx) return false;
    //         continue;
    //     }

    //     float invD = 1.0f / d;
    //     float t0 = (mn - o) * invD;
    //     float t1 = (mx - o) * invD;
    //     if (t0 > t1) std::swap(t0, t1);

    //     if (t0 > tMin) tMin = t0;
    //     if (t1 < tMax) tMax = t1;

    //     if (tMax < tMin) return false;
    // }
    return true;
}

