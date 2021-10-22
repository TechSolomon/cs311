// hdtcount.h
// Solomon Himelbloom
// 2021-09-26
// Header for Holey Domino Tilings.

#ifndef PROJ4_HDTCOUNT_H
#define PROJ4_HDTCOUNT_H

#include <vector>

// Implementation in source file
int hdtCount(int dim_x, int dim_y,
             int forbid1_x, int forbid1_y,
             int forbid2_x, int forbid2_y);

// Implementation in source file
int hdtCount_recurse(std::vector<std::vector<int>> & board,
                     int dim_x, int dim_y,
                     int squaresLeft);

#endif //PROJ4_HDTCOUNT_H
