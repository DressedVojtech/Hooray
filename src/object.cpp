#include "object.h"
#include <vector>
#include "vec3.h"
#include "triangle.h"

object::object() {
    position = vec3();
}

object::object(std::vector<triangle*> TRIANGLES, vec3 POSITION) {
    triangles = TRIANGLES;
    position = POSITION;
}

object::object(std::vector<triangle*> TRIANGLES) {
    triangles = TRIANGLES;
    position = vec3();
}

object::object(triangle* TRIANGLE) {
    add_triangle(TRIANGLE);
    position = vec3();
}

object::object(triangle* TRIANGLE, vec3 POSITION) {
    add_triangle(TRIANGLE);
    position = POSITION;
}

object::object(vec3 POSITION) {
    position = POSITION;
}


void object::add_triangle(triangle* TRIANGLE) {
    triangles.push_back(TRIANGLE);
}
void object::set_position(vec3 POSITION) {
    position = POSITION;
}