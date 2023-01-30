#ifndef bitmap_H
#define bitmap_H
#include <vector>
#include "rgb.h"

class bitmap {
    public:
        std::vector <std::vector <rgb>> bm;
        void init(int sizeX, int sizeY);
        void setCell(rgb color, int i, int j);
};

#endif