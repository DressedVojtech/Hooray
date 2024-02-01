#include <string>
#include <fstream>
#include <math.h>
#include "scene.h"
#include "object.h"
#include "rgb.h"
#include "rgba.h"
#include "vec3.h"
#include "vec2.h"
#include "triangle.h"
#include "ray.h"
#include "light_source.h"
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
        vec3 intersection = triangles[i].intersection(Ray);
        vec3 null = {NULL, NULL, NULL};
        bool hit = (intersection != null);
        if (!hit);
        else if (index == -1 && hit) {
            min_t = intersection.distance_from(cam_pos);
            index = i;
        } else if (intersection.distance_from(cam_pos) < min_t && hit) {
            min_t = intersection.distance_from(cam_pos);
            index = i;
        }
    }
    if (index == -1) {
        return void_color;
    }
    rgb res = triangles[index].color;
    /* Planning to move this to post processing*/
    // ray Koranteng = {light_sources[0].position, triangles[index].intersection(Ray).P};
    // float l_min_t;
    // float l_index = -1;
    // for (int i = 0; i < triangles.size(); i++) {
    //     triangle::vec3b intersection = triangles[i].intersection(Koranteng);
    //     if (hit);
    //     else if (l_index == -1 && hit) {
    //         l_min_t = intersection.distance_from(light_sources[0].position);
    //         l_index = -1;
    //     }
    //     else if (intersection.distance_from(light_sources[0].position) < l_min_t && hit) {
    //         l_min_t = intersection.distance_from(light_sources[0].position);
    //         l_index = i;
    //     }
    // }
    // if (light_sources[0].position.distance_from(triangles[index].intersection(Ray).P) > l_min_t) {
    //     res.dimm((light_sources[0].position.distance_from(triangles[index].intersection(Ray).P))/(light_sources[0].intensity*5));
    // } else {
    //     res.dimm((light_sources[0].position.distance_from(triangles[index].intersection(Ray).P))/(light_sources[0].intensity*10));
    // }
    /* Planning to move this to post processing*/
    return res;
}

rgba scene::shadow(int a, int b) {
    ray Ray = {cam_pos, pixel_coordinates(a, b)};
    float min_t;
    int index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        vec3 intersection = triangles[i].intersection(Ray);
        vec3 null = {NULL, NULL, NULL};
        bool hit = (intersection != null);
        if (!hit);
        else if (index == -1 && hit) {
            min_t = intersection.distance_from(cam_pos);
            index = i;
        } else if (intersection.distance_from(cam_pos) < min_t && hit) {
            min_t = intersection.distance_from(cam_pos);
            index = i;
        }
    }
    vec3 P = triangles[index].intersection(Ray);
    ray Koranteng = {light_sources[0].position, P};
    float l_min_t;
    float l_index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        vec3 intersection = triangles[i].intersection(Koranteng);
        vec3 null = {NULL, NULL, NULL};
        bool hit = (intersection != null);
        if (!hit);
        else if (l_index == -1 && hit) {
            l_min_t = intersection.distance_from(light_sources[0].position);
            l_index = -1;
        }
        else if (intersection.distance_from(light_sources[0].position) < l_min_t && hit) {
            l_min_t = intersection.distance_from(light_sources[0].position);
            l_index = i;
        }
    }
    if (l_min_t < light_sources[0].position.distance_from(P)) {
        rgba A = {0, 0, 0, (light_sources[0].position.distance_from(triangles[index].intersection(Ray).P))/(light_sources[0].intensity*5) * 255};
        A.check();
        return A;
    } else {
        rgba A = {0, 0, 0, (light_sources[0].position.distance_from(triangles[index].intersection(Ray).P))/(light_sources[0].intensity*10) * 255};
        A.check();
        return A;
    }

    
}

bitmap scene::render_shadows() {
    populate_triangles();
    bitmap shadows(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            shadows.setCell(shadow(i, j).to_rgba(), i, j);
        }
    }
    return shadows;
}

bitmap scene::render() {
    populate_triangles();
    bitmap image(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            image.setCell(pixel(i, j).to_rgba(), i, j);
        }
    }
    return image; 
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
