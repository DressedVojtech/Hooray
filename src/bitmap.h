#ifndef bitmap_H
#define bitmap_H
#include <vector>
#include <string>
#include "rgba.h"

class bitmap {
    public:
        std::vector <std::vector <rgba>> bm;
        int width;
        int height;
        bitmap(int sizeX, int sizeY);
        void setCell(rgba color, int i, int j);
        void export_as(std::string file_name);
        void export_as_ppm(std::string file_name);
        void export_as_png(std::string file_name);
};

#endif