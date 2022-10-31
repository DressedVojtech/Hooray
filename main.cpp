#include "scene.h"
#include <vector>
#include <iostream>
#include <math.h>

// vojtik kosinka je vrchni programator, ale smazal, ze je vrchnim programatorem, takze uz neni

int main() {
    scene scene1;
    // scene1.ssf();
    // sceen1.asf();
    scene1.set_resolution(1366, 768);
    scene1.set_cam({0, 0, 0}, 200.0);
    scene1.set_background({0, 0, 0});
    scene1.add_light_source({{-200, 400, -200}, 0.375});
    scene1.set_fog({255, 0, 0, 0.9});
    object Object;
    // Bottom - Red
    triangle Triangle0 = {{0, 0, 0}, {400, 0, 0}, {400, 400, 0}, {0, 0}, {0, 0}, {0, 0}, {255, 0, 0}, "..."}; Object.add_triangle(Triangle0);
    triangle Triangle1 = {{0, 0, 0}, {0, 400, 0}, {400, 400, 0}, {0, 0}, {0, 0}, {0, 0}, {255, 0, 0}, "..."}; Object.add_triangle(Triangle1);
    // Front - Green
    triangle Triangle2 = {{0, 0, 0}, {0, 0, 400}, {400, 0, 400}, {0, 0}, {0, 0}, {0, 0}, {0, 255, 0}, "..."}; Object.add_triangle(Triangle2);
    triangle Triangle3 = {{0, 0, 0}, {400, 0, 0}, {400, 0, 400}, {0, 0}, {0, 0}, {0, 0}, {0, 255, 0}, "..."}; Object.add_triangle(Triangle3);
    // Left - Blue
    triangle Triangle4 = {{0, 0, 0}, {0, 0, 400}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {0, 0, 255}, "..."}; Object.add_triangle(Triangle4);
    triangle Triangle5 = {{0, 0, 0}, {0, 400, 0}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {0, 0, 255}, "..."}; Object.add_triangle(Triangle5);
    // Back - Yellow
    triangle Triangle6 = {{400, 0, 0}, {400, 400, 0}, {400, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 0}, "..."}; Object.add_triangle(Triangle6);
    triangle Triangle7 = {{400, 0, 0}, {400, 0, 400}, {400, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 0}, "..."}; Object.add_triangle(Triangle7);
    // Right - Magenta
    triangle Triangle8 = {{400, 400, 0}, {400, 400, 400}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 0, 255}, "..."}; Object.add_triangle(Triangle8);
    triangle Triangle9 = {{400, 400, 0}, {0, 400, 0}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 0, 255}, "..."}; Object.add_triangle(Triangle9);
    // Top - White
    triangle Triangle10 = {{400, 0, 400}, {400, 400, 400}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 255}, "..."}; Object.add_triangle(Triangle10);
    triangle Triangle11 = {{400, 0, 400}, {0, 0, 400}, {0, 400, 400}, {0, 0}, {0, 0}, {0, 0}, {255, 255, 255}, "..."}; Object.add_triangle(Triangle11);
    Object.set_position({-700, 400, -600});
    scene1.add_object(Object);
    // move object
    scene1.render();
}