#include "bitmap.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "rgba.h"
#include <png.h>

bitmap::bitmap(int sizeX, int sizeY) {
    bm = std::vector<std::vector<rgba>>(sizeY, std::vector<rgba>(sizeX, {0, 0, 0, 0}));
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
    FILE *fp = fopen(file_name.c_str(), "wb");
    if (!fp) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        std::cerr << "Error: Unable to create PNG write structure." << std::endl;
        fclose(fp);
        return;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        std::cerr << "Error: Unable to create PNG info structure." << std::endl;
        png_destroy_write_struct(&png, nullptr);
        fclose(fp);
        return;
    }

    png_init_io(png, fp);

    png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);

    std::vector<png_bytep> row_pointers;
    for (int i = 0; i < height; ++i) {
        row_pointers.push_back(reinterpret_cast<png_bytep>(const_cast<rgba*>(&bm[i][0])));
    }

    png_set_rows(png, info, &row_pointers[0]);
    png_write_png(png, info, PNG_TRANSFORM_IDENTITY, nullptr);

    png_destroy_write_struct(&png, &info);
    fclose(fp);

    std::cout << "PNG file saved: " << file_name << std::endl;
}
