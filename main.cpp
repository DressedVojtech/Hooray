// main.cpp – načtení .obj a vykreslení

#include <vector>
#include "scene.h"
#include "object.h"
#include "triangle.h"
#include "vec3.h"
#include "rgb.h"
#include "rgba.h"
#include "obj_loader.h"

int main() {
    const int   WIDTH  = 1920;
    const int   HEIGHT = 1080;
    const rgb   BG(0, 0, 0);
    const vec3  CAM(0.0f, 0.0f, 0.0f);
    const float FOCAL  = 10.0f;

    // Načti objekt (např. "teapot.obj" / "bunny.obj" / "cube.obj")
    // scale uprav podle modelu – některé OBJ jsou obrovské/malé.
    object* obj = load_obj("../teapot.obj", rgb(255, 255, 2555), /*scale*/ 10.0f, /*position*/ vec3(0.0f, 22.0f, 0.0f));

    std::vector<object*> objects{ obj };

    scene sc(BG, WIDTH, HEIGHT, CAM, FOCAL, objects);
    sc.render();
    sc.bm.back().export_as("image1.png");

    // Úklid
    for (object* o : objects) {
        for (triangle* t : o->triangles) delete t;
        delete o;
    }
    return 0;
}
