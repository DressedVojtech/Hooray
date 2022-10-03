#include "src/scene.h"
#include <vector>
#include <iostream>
#include <math.h>

int main() {
    scene scene1;
    // scene1.ssf();
    // sceen1.asf();
    scene1.set_resolution(1024, 1024);
    scene1.set_cam({0, 0, 0}, 10.0);
    scene1.set_background({30, 30, 30});
    scene1.add_light_source({{0, 0, 0}});
    object Object;
    Object.add_triangle({{0, 0, 0}, {20, 0, 0}, {20, 0, 20}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 255}, "..."});
    Object.set_position({0, 20, 0});
    scene1.add_object(Object);
    scene1.render();
}