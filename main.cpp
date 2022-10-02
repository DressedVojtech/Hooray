#include "src/scene.h"
#include <vector>
#include <iostream>
#include <math.h>

int main() {
    scene scene1;
    // scene1.ssf();
    // sceen1.asf();
    scene1.set_resolution(256, 256);
    vec3 position = {0, 0, 0};
    scene1.set_cam(position, 10.0);
    rgb color = {30, 30, 30};
    scene1.set_background(color);
    l_s light_source;
    light_source.position = {0, 0, 0};
    scene1.add_light_source(light_source);
    object Object;
    triangle Triangle;
    Triangle.p0 = {0, 0, 0};
    Triangle.p1 = {0, 5, 0};
    Triangle.p2 = {0, 0, 5};
    Triangle.vt0 = {0, 0};
    Triangle.vt1 = {0, 0};
    Triangle.vt2 = {0, 0};
    Triangle.color = {255, 255, 0};
    Triangle.texture = "Ahoj";
    Object.add_triangle(Triangle);
    Object.set_position({0, 5, 0});
    scene1.add_object(Object);
    scene1.render();
}