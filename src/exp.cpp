#include "exp.h"
#include "bitmap.h"
#include <fstream>
#include <string>

void exp::ppm(bitmap bm, std::string path) {
    std::ofstream image(path);
    image << "P3\n" << bm.bm.size() << " " << bm.bm[0].size() << "\n255\n";
    for (int i = 0; i < bm.bm.size(); i++) {
        for (int j = 0; j < bm.bm[i].size(); j++) {
            image << bm.bm[i][j].r << " " << bm.bm[i][j].g << " " << bm.bm[i][j].b << "\n";
        }
        image << "\n";
    }
}