#ifndef scene_H
#define scene_H
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include "object.h"
#include "rgba.h"
#include "vec3.h"
#include "triangle.h"
#include "line.h"
//#include "light_source.h"
#include "bitmap.h"


class scene {
    public:
        std::vector <object*> objects;
        //std::vector <light_source> light_sources;
        int screen_width;
        int screen_height;
        vec3 cam_pos;
        float distance;
        rgb bg_color = {0, 0, 0};

        std::vector<bitmap> bm;

        scene(rgb BACKGROUND, int WIDTH, int HEIGHT, vec3 CAM_POS, float FOCAL_LENGTH, /*light_source LIGHT_SOURCE,*/ std::vector<object*> OBJECTS);
        scene(rgb BACKGROUND, int WIDTH, int HEIGHT, vec3 CAM_POS, float FOCAL_LENGTH /*light_source LIGHT_SOURCE,*/);
        scene(std::vector<object*> OBJECTS);

        void render();
};

#endif