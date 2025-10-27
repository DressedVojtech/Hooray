#include "line.h"

line::line() {
    org = vec3();
    dir = vec3();
}

line::line(vec3 O, vec3 D) {
    org = vec3(O);
    dir = vec3(D);
}

line::line(vec3 D) {
    org = vec3();
    dir = vec3(D);
}