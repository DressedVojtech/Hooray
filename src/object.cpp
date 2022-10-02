#include "object.h"
#include <vector>
#include "vec3.h"
#include "triangle.h"

void object::add_triangle(triangle TRIANGLE) {
    triangles.push_back(TRIANGLE);
}
void object::set_position(vec3 pos) {
    position = pos;
}