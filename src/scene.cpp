#include <string>
#include <fstream>
#include "scene.h"
#include "object.h"
#include "rgb.h"
#include "vec3.h"
#include "vec2.h"
#include "triangle.h"
#include "ray.h"
#include "light_source.h"

void scene::populate_triangles() {
    triangles.clear();
    for (int i = 0; i < objects.size(); i++) {
        for (int j = 0; j < objects[i].triangles.size(); j++) {
            triangle Triangle;
            Triangle = objects[i].triangles[j] + objects[i].position;
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
    float min_t = 4294967295;
    int index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        triangle::vec3b intersection_point = triangles[i].intersection(Ray);
        if (intersection_point.P.distance_from(cam_pos) < min_t && intersection_point.hit == true) {
            min_t = triangles[i].intersection(Ray).P.distance_from(cam_pos);
            index = i;
        }
    }
    if (index == -1) {
        return void_color;
    } else {
        return triangles[index].color; //Let's just ignore textures all together for now
    }
}

void scene::render() {
    populate_triangles();
    std::cout << "P3\n" << screen_width << " " << screen_height << "\n255\n\n";
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            rgb pixel_color = pixel(i, j);
            std::cout << pixel_color.r << " " << pixel_color.g << " " << pixel_color.b << std::endl;
        }
    }
}

void scene::ssf() {
    std::string path;
    std::cout << "input the path to the .ssf file, you wish to render" << std::endl;
    std::cin >> path;


}

void scene::ssf(std::string path) {

}

void scene::asf() {
    std::string path;
    std::cout << "input the path to the .ssf file, you wish to render" << std::endl;
    std::cin >> path;

}

void scene::asf(std::string path) {
    
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

void scene::add_object(object Object) {
    objects.push_back(Object);
}



// void scene::animate::rotate_scene(float angle, char axis) {
//     for (int i = 0; i < triangles.size(); i++) {
//         triangles[i].p0.rotate(angle, axis);
//         triangles[i].p1.rotate(angle, axis);
//         triangles[i].p2.rotate(angle, axis);
//     }
// }

// void scene::animate::rotate_object(float angle, char axis, int index) {
//     for (int i = 0; i < objects[index].trianlges.size(); i++) {
//         objects[index].triangles[i].p0.rotate(angle, axis);
//         objects[index].triangles[i].p1.rotate(angle, axis);
//         objects[index].triangles[i].p2.rotate(angle, axis);
//     }
//     scene::populate_triangles();
// }