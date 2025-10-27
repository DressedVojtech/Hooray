#include "bitmap.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "rgba.h"
#include <png.h>
#include <cstdio>
#include <cstdlib>

bitmap::bitmap(int sizeX, int sizeY) {
    bm = std::vector<std::vector<rgba>>(sizeY, std::vector<rgba>(sizeX, rgba()));
    width = sizeX;
    height = sizeY;
}

void bitmap::setCell(rgba color, int i, int j) {
    if ((i > height-1) || (j > width)) {
        std::cout << "Out of bounds of bitmap" << std::endl;
        return;
    }
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
    std::cout << "Export finished" << std::endl;
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
            file << bm[i][j].COLOR.r;
            file << " ";
            file << bm[i][j].COLOR.g;
            file << " ";
            file << bm[i][j].COLOR.b;
            file << " ";
        }
        file << "\n";
    }
    file.close();
}

void bitmap::export_as_png(std::string file_name) {
    FILE* fp = fopen(file_name.c_str(), "wb");
    if (!fp) {
        std::cerr << "Failed to open file for writing: " << file_name << std::endl;
        return;
    }

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png_ptr) {
        std::cerr << "Failed to create PNG write struct." << std::endl;
        fclose(fp);
        return;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        std::cerr << "Failed to create PNG info struct." << std::endl;
        png_destroy_write_struct(&png_ptr, nullptr);
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        std::cerr << "Error during PNG creation." << std::endl;
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return;
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(
        png_ptr,
        info_ptr,
        width,
        height,
        8, // bit depth
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png_ptr, info_ptr);

    png_bytep row = (png_bytep)malloc(4 * width * sizeof(png_byte));
    if (!row) {
        std::cerr << "Failed to allocate row buffer." << std::endl;
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return;
    }

    // Helpers (no std::clamp)
    auto clamp255 = [](float v) -> float {
        if (v < 0.0f) v = 0.0f;
        if (v > 255.0f) v = 255.0f;
        return v;
    };
    auto clamp01 = [](float v) -> float {
        if (v < 0.0f) v = 0.0f;
        if (v > 1.0f)  v = 1.0f;
        return v;
    };
    auto to_byte = [](float v) -> png_byte {
        // Round to nearest
        return static_cast<png_byte>(v + 0.5f);
    };

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = x * 4;

            float r = bm[y][x].COLOR.r;
            float g = bm[y][x].COLOR.g;
            float b = bm[y][x].COLOR.b;

            // Heuristic: if values look normalized (<= 1), scale to 0–255
            if (r <= 1.0f && g <= 1.0f && b <= 1.0f) {
                r *= 255.0f; g *= 255.0f; b *= 255.0f;
            }

            r = clamp255(r);
            g = clamp255(g);
            b = clamp255(b);

            float a = clamp01(bm[y][x].a); // alpha expected 0–1

            row[idx + 0] = to_byte(r);
            row[idx + 1] = to_byte(g);
            row[idx + 2] = to_byte(b);
            row[idx + 3] = to_byte(a * 255.0f);
        }
        png_write_row(png_ptr, row);
    }

    free(row);
    png_write_end(png_ptr, nullptr);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}
