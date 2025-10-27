#include "object.h"

static inline void expand_with_tri_world(AABB& box, const triangle* t, const vec3& pos)
{
    if (!t) return;

    auto add = [&](const vec3& a, const vec3& b) -> vec3 {
        return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    };

    box.expand(add(t->p0, pos));
    box.expand(add(t->p1, pos));
    box.expand(add(t->p2, pos));
}

object::object() {
    position = vec3(0,0,0);
    bounds = AABB();
    triangles.clear();
}

object::object(std::vector<triangle*> TRIANGLES, vec3 POSITION) {
    triangles = TRIANGLES;
    position = POSITION;
    rebuild_bounds();
}

object::object(std::vector<triangle*> TRIANGLES) {
    triangles = TRIANGLES;
    position = vec3();
    rebuild_bounds();
}

object::object(triangle* TRIANGLE) {
    add_triangle(TRIANGLE);
    position = vec3();
    rebuild_bounds();
}

object::object(triangle* TRIANGLE, vec3 POSITION) {
    add_triangle(TRIANGLE);
    position = POSITION;
    rebuild_bounds();
}

void object::add_triangle(triangle* TRIANGLE) {
    triangles.push_back(TRIANGLE);
    rebuild_bounds();
}
void object::set_position(vec3 POSITION) {
    position = POSITION;
    rebuild_bounds();
}

void object::rebuild_bounds()
{
    bounds = AABB();
    if (triangles.empty()) {
        bounds.expand(position);
        return;
    }

    for (const triangle* t : triangles) {
        expand_with_tri_world(bounds, t, position);
    }
}
