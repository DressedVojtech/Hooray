#ifndef object_H
#define object_H
#include <vector>
#include "vec3.h"
#include "triangle.h"

class object {
    public:
        std::vector <triangle> triangles;
        vec3 position;

        void add_triangle(triangle TRIANGLE);
        void set_position(vec3 pos);
        void rotate(float angle, char axis);
};

#endif