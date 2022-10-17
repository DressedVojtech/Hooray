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
    scene1.set_cam({0, 0, 0}, 256.0);
    scene1.set_background({30, 40, 30});
    scene1.add_light_source({{0, 0, 0}});
    object Object;
    triangle Triangle = {{0, 0, 0}, {200, 0, 0}, {200, 0, 200}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 255}, "..."};
    Object.add_triangle(Triangle);
    Object.set_position({0, 1, 0});
    scene1.add_object(Object);
    scene1.render();
}