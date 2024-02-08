#ifndef object_H
#define object_H
#include <vector>
#include "vec3.h"
#include "triangle.h"

class object {
    public:
        std::vector <triangle> triangles;
        vec3 position;

        object();
        object(std::vector<triangle> TRIANGLES, vec3 POSITION);
        object(triangle TRIANGLE, vec3 POSITION);
        object(triangle TRIANGLE);
        object(std::vector<triangle> TRIANGLES);
        object(vec3 POSITION);

        void add_triangle(triangle TRIANGLE);
        void set_position(vec3 POSITION);
};

#endif