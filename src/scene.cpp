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

vec3 scene::pixel_coordinates(int I, int J) {
    vec3 pixel = vec3((cam_pos.x - (screen_width/2) + J), (cam_pos.y + distance), (cam_pos.z + (screen_height/2) - I));
    return pixel;
}

rgb scene::pixel(int A, int B) {
    ray Ray = {cam_pos, pixel_coordinates(A, B)};
    float min_t;
    int index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        vec3 intersection = triangles[i].intersection(Ray);
        bool hit = !isnan(intersection.x);
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
    return res;
}

rgba scene::shadow(int A, int B) {
    ray Ray = ray(cam_pos, pixel_coordinates(A, B));
    float min_t;
    int index = -1;
    for (int i = 0; i < triangles.size(); i++) {
        vec3 intersection = triangles[i].intersection(Ray);
        vec3 null = !isnan(intersection.x);
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
        vec3 null = !isnan(intersection.x);
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
        rgba a = rgba(0, 0, 0, 0.3);
        a.clip();
        return a;
    } else {
        rgba a = rgba(0, 0, 0, 0.6);
        a.clip();
        return a;
    }

    
}

bitmap scene::render_shadows() {
    populate_triangles();
    bitmap shadows(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            shadows.setCell(shadow(i, j), i, j);
        }
    }
    return shadows;
}

bitmap scene::render_colors() {
    populate_triangles();
    bitmap colors(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            colors.setCell(pixel(i, j), i, j);
        }
    }
    return colors;
}

bitmap scene::render() {
    populate_triangles();
    bitmap image(screen_width, screen_height);
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j++) {
            rgba A = rgba(pixel(i, j));
            rgba B = shadow(i, j);
            image.setCell(A + B, i, j);
        }
    }
    return image; 
}

void scene::set_background(rgb COLOR) {
    void_color = COLOR;
}

void scene::set_resolution(int WIDTH, int HEIGHT) {
    screen_width = WIDTH;
    screen_height = HEIGHT;
}

void scene::set_cam(vec3 POSITION, float DISTANCE) {
    cam_pos = POSITION;
    distance = DISTANCE;
}

void scene::add_light_source(light_source LIGHT_SOURCE) {
    light_sources.push_back(LIGHT_SOURCE);
}

void scene::add_object(object OBJECT) {
    objects.push_back(OBJECT);
}
