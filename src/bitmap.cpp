#include "bitmap.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "rgba.h"
#include <png.h>

bitmap::bitmap(int sizeX, int sizeY) {
    bm = std::vector<std::vector<rgba>>(sizeY, std::vector<rgba>(sizeX, rgba()));
    width = sizeX;
    height = sizeY;
}

void bitmap::setCell(rgba color, int i, int j) {
    bm[i][j] = color;
}

void bitmap::export_as(std::string file_name) {
    char delimiter = '.';
    size_t found = file_name.find_last_of(delimiter);
    std::string format;
    if (found != std::string::npos) {
        format = file_name.substr(found);
    } else {
        std::cout << "Please don't forget to specify the file format. (eg. image.ppm, image.png etc.)" << std::endl;
        return;
    }

    if (format == ".ppm") {
        export_as_ppm(file_name);
    } else if (format == ".png") {
        export_as_png(file_name);
    } else {
        std::cout << "Unsupported file format." << std::endl;
    }
}

void bitmap::export_as_ppm(std::string file_name) {
    std::ofstream file;
    file.open(file_name);
    file << "P3\n";
    file << width;
    file << " ";
    file << height;
    file << "\n255\n\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            file << bm[i][j].r;
            file << " ";
            file << bm[i][j].g;
            file << " ";
            file << bm[i][j].b;
            file << " ";
        }
        file << "\n";
    }
    file.close();
}

void bitmap::export_as_png(std::string file_name) {
}
