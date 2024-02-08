#include "scene.h"
#include "rgb.h"
#include <vector>
#include <iostream>
#include <math.h>

// vojtik kosinka je vrchni programator, ale smazal, ze je vrchnim programatorem, takze uz neni

int main() {
    scene scene1;
    scene1.set_resolution(1920, 1200);
    scene1.set_cam(vec3(0, 0, 0), 600);
    scene1.set_background(rgb(0.0f, 0.0f, 0.0f));
    scene1.add_light_source(light_source(vec3(0, 200, 0), 0.9));
    object Object = object(vec3(-500, -200, -500));
    rgb color = rgb(255.0f, 0.0f, 200.0f);
    float size = 1000;
    // Bottom
    triangle Triangle0 = triangle(vec3(0, 0, 0), vec3(size, 0, 0), vec3(size, size, 0), color); Object.add_triangle(Triangle0);
    triangle Triangle1 =triangle(vec3(0, 0, 0), vec3(0, size, 0), vec3(size, size, 0), color); Object.add_triangle(Triangle1);
    // Front
    triangle Triangle2 = triangle(vec3(0, 0, 0), vec3(0, 0, size), vec3(size, 0, size), color); Object.add_triangle(Triangle2);
    triangle Triangle3 = triangle(vec3(0, 0, 0), vec3(size, 0, 0), vec3(size, 0, size), color); Object.add_triangle(Triangle3);
    // Left
    triangle Triangle4 = triangle(vec3(0, 0, 0), vec3(0, 0, size), vec3(0, size, size), color); Object.add_triangle(Triangle4);
    triangle Triangle5 = triangle(vec3(0, 0, 0), vec3(0, size, 0), vec3(0, size, size), color); Object.add_triangle(Triangle5);
    // Back
    triangle Triangle6 = triangle(vec3(size, 0, 0), vec3(size, size, 0), vec3(size, size, size), color); Object.add_triangle(Triangle6);
    triangle Triangle7 = triangle(vec3(size, 0, 0), vec3(size, 0, size), vec3(size, size, size), color); Object.add_triangle(Triangle7);
    // Right
    triangle Triangle8 = triangle(vec3(size, size, 0), vec3(size, size, size), vec3(0, size, size), color); Object.add_triangle(Triangle8);
    triangle Triangle9 = triangle(vec3(size, size, 0), vec3(0, size, 0), vec3(0, size, size), color); Object.add_triangle(Triangle9);
    // Top
    triangle Triangle10 = triangle(vec3(size, 0, size), vec3(size, size, size), vec3(0, size, size), color); Object.add_triangle(Triangle10);
    triangle Triangle11 = triangle(vec3(size, 0, size), vec3(0, 0, size), vec3(0, size, size), color); Object.add_triangle(Triangle11);
    scene1.add_object(Object);

    object obj = object(vec3(-500, 600, -500));
    rgb barva = rgb(40.0f, 255.0f, 255.0f);
    triangle troj0 = triangle(vec3(200, 0, 200), vec3(500, 0, 1000), vec3(1000, 0, 500), barva);
    obj.add_triangle(troj0);
    scene1.add_object(obj);

    bitmap a = scene1.render();
    // bitmap b = scene1.render_shadows();
    a.export_as("image.ppm");
    // b.export_as("shadows.png");
}