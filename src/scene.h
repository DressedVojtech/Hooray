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

        void ssf(); // scene safe file
        void asf(); // animations safe file
        void ssf(std::string path);
        void asf(std::string path);

    class animate {
        public:
            void rotate_object_in_scene(float angle, char axis, int index);
            void rotate_object(float angle, char axis, int index);
            void rotate_scene(float angle, char axis);
    };
};

#endif