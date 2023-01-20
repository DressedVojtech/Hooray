#include "bitmap.h"
#include <vector>
#include "rgb.h"

bitmap::bitmap(int width, int height) {
    bm = std::vector<std::vector<rgb>>(height, std::vector<rgb>(width, {0, 0, 0}));
}

void bitmap::setCell(rgb color, int i, int j) {
    bm[i][j] = color;
}