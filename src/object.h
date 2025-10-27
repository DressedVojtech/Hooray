#ifndef object_H
#define object_H
#include <vector>
#include "triangle.h"
#include "aabb.h"

class object {
    public:
        std::vector <triangle*> triangles;
        vec3 position;
        AABB bounds;

        object(std::vector<triangle*> TRIANGLES, vec3 POSITION);
        object(triangle* TRIANGLE, vec3 POSITION);
        object(triangle* TRIANGLE);
        object(std::vector<triangle*> TRIANGLES);
        object();

        void add_triangle(triangle* TRIANGLE);
        void set_position(vec3 POSITION);

        void rebuild_bounds();
};

#endif