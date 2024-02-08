#include "light_source.h"
#include "vec3.h"

light_source::light_source() {
    position = vec3();
    intensity = 1;
}

light_source::light_source(vec3 P, float I) {
    position = P;
    intensity = I;
}