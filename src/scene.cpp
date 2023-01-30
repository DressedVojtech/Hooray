#include <string>
#include <fstream>
#include <math.h>
#include "scene.h"
#include "object.h"
#include "rgb.h"
#include "vec3.h"
#include "vec2.h"
#include "triangle.h"
#include "ray.h"
#include "light_source.h"
#include "rgba.h"
#include "bitmap.h"
#define black {0, 0, 0}

void scene::populate_triangles() {
    triangles.clear();
    for (int i = 0; i < objects.size(); i++) {
        for (int j = 0; j < objects[i].triangles.size(); j++) {
            triangle Triangle;
            Triangle = objects[i].triangles[j];
            Triangle.p0 = Triangle.p0 + objects[i].position;
            Triangle.p1 = Triangle.p1 + objects[i].position;
            Triangle.p2 = Triangle.p2 + objects[i].position;
            triangles.push_back(Triangle);
        }
    }
}

vec3 scene::pixel_coordinates(int i, int j) {
    vec3 pixel = {(cam_pos.x - (screen_width/2) + j), (cam_pos.y + distance), (cam_pos.z + (screen_height/2) - i)};
    return pixel;
}

rgb scene::pixel(int a, int b) {
    ray Ray = {cam_pos, pixel_coordinates(a, b)};
    float min_t;
    int index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        triangle::vec3b intersection = triangles[i].intersection(Ray);
        if (intersection.hit == false);
        else if (index == -1 && intersection.hit == true) {
            min_t = intersection.P.distance_from(cam_pos);
            index = i;
        } else if (intersection.P.distance_from(cam_pos) < min_t && intersection.hit == true) {
            min_t = intersection.P.distance_from(cam_pos);
            index = i;
        }
    }
    if (index == -1) {
        return void_color;
    }
    // ray l_Ray = {light_sources[0].position, triangles[index].intersection(Ray).P};
    rgb res = triangles[index].color;
    res.dim((light_sources[0].position.distance_from(triangles[index].intersection(Ray).P))/(light_sources[0].intensity*10));
    // rgb fog_level = {fog.r / a, fog.g / a, fog.b / a};
    // res = res + fog_level;
    return res;
}

void scene::render() {
    populate_triangles();
    image.init(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            image.setCell(pixel(i, j), i, j);
        }
    }
}

void readSafeFiles() {

}

void scene::set_background(rgb color) {
    void_color = color;
}

void scene::set_resolution(int width, int height) {
    screen_height = height;
    screen_width = width;
}

void scene::set_cam(vec3 position, float Distance) {
    cam_pos = position;
    distance = Distance;
}

void scene::add_light_source(l_s light_source) {
    light_sources.push_back(light_source);
}

void scene::set_fog(rgba Fog) {
    fog = Fog;
}

void scene::add_object(object Object) {
    objects.push_back(Object);
}
