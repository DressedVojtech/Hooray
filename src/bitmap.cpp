#include "bitmap.h"
#include <vector>

bitmap(int sizeX, int sizeY) {
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            bm[i][j]= {0, 0, 0};
        }
    }
}

void setCell(rgb color, int i, int j) {
    bm[i][j] = color;
}