#include "ray.h"
#include "vec3.h"

ray::ray() {
    origin = vec3();
    direction = vec3();
}

ray::ray(vec3 O, vec3 D) {
    origin = O;
    direction = D;
}