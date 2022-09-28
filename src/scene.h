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
        void render();

        // Reading the safe files
        void ssf(); // scene safe file
        void asf(); // animations safe file
        void ssf(std::string path);
        void asf(std::string path);

        // Initiating a scene using functions
        void set_background(rgb color);
        void set_resolution(int width, int height);
        void set_cam(vec3 position, float Distance);
        void add_light_source(l_s light_source);
        void add_object(object Object);

    class animate {
        public:
            void rotate_object_in_scene(float angle, char axis, int index);
            void rotate_object(float angle, char axis, int index);
            void rotate_scene(float angle, char axis);
    };
};

#endif