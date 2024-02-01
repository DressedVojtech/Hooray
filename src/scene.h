#ifndef scene_H
#define scene_H
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include "object.h"
#include "rgb.h"
#include "vec3.h"
#include "vec2.h"
#include "triangle.h"
#include "ray.h"
#include "light_source.h"
#include "bitmap.h"

class scene {
    public:
        rgb void_color = {30, 30, 30};
        std::vector <object> objects;
        std::vector <triangle> triangles;
        std::vector <l_s> light_sources;
        int screen_width;
        int screen_height;
        vec3 cam_pos;
        float distance;


        void populate_triangles();
        vec3 pixel_coordinates(int i, int j);
        rgb pixel(int i, int j);
        rgba shadow(int a, int b);
        bitmap render();
        bitmap render_shadows();
        // Initiating a scene using functions
        void set_background(rgb color);
        void set_resolution(int width, int height);
        void set_cam(vec3 position, float Distance);
        void add_light_source(l_s light_source);
        void add_object(object Object);
};

#endif