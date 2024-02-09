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
        std::vector <object*> objects;
        std::vector <triangle*> triangles;
        std::vector <light_source> light_sources;
        int screen_width;
        int screen_height;
        vec3 cam_pos;
        float distance;
        rgb void_color = {0, 0, 0};


        void populate_triangles();
        vec3 pixel_coordinates(int I, int J);
        rgb pixel(int I, int J);
        rgba shadow(int A, int B);
        bitmap render();
        bitmap render_colors();
        bitmap render_shadows();

        // Initiating a scene using functions
        void set_background(rgb COLOR);
        void set_resolution(int WIDTH, int HEIGHT);
        void set_cam(vec3 POSITION, float DISTANCE);
        void add_light_source(light_source LIGHT_SOURCE);
        void add_object(object* OBJECT);
};

#endif