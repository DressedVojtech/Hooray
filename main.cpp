#include "scene.h"
#include "rgb.h"
#include <vector>
#include <iostream>
#include <math.h>

// vojtik kosinka je vrchni programator, ale smazal, ze je vrchnim programatorem, takze uz neni

int main() {
    scene scene1;
    scene1.set_resolution(1920, 1200);
    scene1.set_cam({0, 0, 0}, 600);
    scene1.set_background({0, 0, 0});
    scene1.add_light_source({{0, 200, 0}, 0.9});
    object Object;
    rgb color = {255, 0, 200};
    float size = 1000;
    // Bottom
    triangle Triangle0 = {{0, 0, 0}, {size, 0, 0}, {size, size, 0}, color}; Object.add_triangle(Triangle0);
    triangle Triangle1 = {{0, 0, 0}, {0, size, 0}, {size, size, 0}, color}; Object.add_triangle(Triangle1);
    // Front
    triangle Triangle2 = {{0, 0, 0}, {0, 0, size}, {size, 0, size}, color}; Object.add_triangle(Triangle2);
    triangle Triangle3 = {{0, 0, 0}, {size, 0, 0}, {size, 0, size}, color}; Object.add_triangle(Triangle3);
    // Left
    triangle Triangle4 = {{0, 0, 0}, {0, 0, size}, {0, size, size}, color}; Object.add_triangle(Triangle4);
    triangle Triangle5 = {{0, 0, 0}, {0, size, 0}, {0, size, size}, color}; Object.add_triangle(Triangle5);
    // Back
    triangle Triangle6 = {{size, 0, 0}, {size, size, 0}, {size, size, size}, color}; Object.add_triangle(Triangle6);
    triangle Triangle7 = {{size, 0, 0}, {size, 0, size}, {size, size, size}, color}; Object.add_triangle(Triangle7);
    // Right
    triangle Triangle8 = {{size, size, 0}, {size, size, size}, {0, size, size}, color}; Object.add_triangle(Triangle8);
    triangle Triangle9 = {{size, size, 0}, {0, size, 0}, {0, size, size}, color}; Object.add_triangle(Triangle9);
    // Top
    triangle Triangle10 = {{size, 0, size}, {size, size, size}, {0, size, size}, color}; Object.add_triangle(Triangle10);
    triangle Triangle11 = {{size, 0, size}, {0, 0, size}, {0, size, size}, color}; Object.add_triangle(Triangle11);
    Object.set_position({-500, -200, -500});
    scene1.add_object(Object);

    object obj;
    rgb bar = {40, 255, 255};
    triangle troj0 = {{200, 0, 200}, {500, 0, 1000}, {1000, 0, 500}, bar}; obj.add_triangle(troj0);
    obj.set_position({-500, 600, -500});
    scene1.add_object(obj);

    bitmap a = scene1.render();
    bitmap b = scene1.render_shadows();
    a.export_as("image.ppm");
    b.export_as("shadows.png");
}