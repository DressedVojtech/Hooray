#include "scene.h"
#include <vector>
#include <iostream>
#include <math.h>

// vojtik kosinka je vrchni programator, ale smazal, ze je vrchnim programatorem, takze uz neni

int main() {
    scene scene1;
    // scene1.ssf();
    // sceen1.asf();
    scene1.set_resolution(256, 256);
    scene1.set_cam({0, 0, 0}, 10.0);
    scene1.set_background({0, 0, 0});
    scene1.add_light_source({{0, 0, 0}});
    object Object;
    Object.add_triangle({{0, 0, 0}, {20, 0, 0}, {20, 0, 20}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 255}, "..."});
    Object.set_position({0, 20, 0});
    scene1.add_object(Object);
    scene1.render();
}