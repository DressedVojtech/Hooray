#include "object.h"
#include <vector>
#include "vec3.h"
#include "triangle.h"

void object::add_triangle(triangle Triangle) {
    triangles.push_back(Triangle);
}
void object::set_position(vec3 pos) {
    position = pos;
}