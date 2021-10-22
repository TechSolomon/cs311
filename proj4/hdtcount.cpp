// hdtcount.cpp
// Solomon Himelbloom
// 2021-09-26
// Source for Holey Domino Tilings.

#include "hdtcount.h"
#include <vector> // For vector

// checkBacklinks
// There are simple ways to check for some dead ends.
// Implement one or more and get shorter execution times.
bool checkBacklinks(std::vector<std::vector<int>> & board, int a, int b) {
    if (board[a][b] == 0) {
        return true;
    }

    else if (a <= 0 || b <= 0) {
        return false;
    }

    return false;
}

// hdtCount
// Does the bulk of work via a call to a workhorse function.
// Pre:
// - 0 <= forbid1_x < dim_x
// - 0 <= forbid1_y < dim_y, given...
// - x and y (dimensions of the board).
// Does not throw.
int hdtCount(int dim_x, int dim_y,
             int forbid1_x, int forbid1_y,
             int forbid2_x, int forbid2_y){
    std::vector<std::vector<int>> board(dim_x, std::vector<int>(dim_y, 0));

    board[forbid1_x][forbid1_y] = 1;
    board[forbid2_x][forbid2_y] = 1;

    int squaresLeft = (dim_x * dim_y) - 2;

    return hdtCount_recurse(board, dim_x, dim_y, squaresLeft);
}

// hdtCount_recurse
// Counts the number of Holey Domino Tilings
// based on a given partial solution, using recursive backtracking
// Pre:
// - Assumes non-negative squaresLeft,
// - with ints dim_x + dim_y,
// - and board of type std::vector<std::vector<int>>.
// Does not throw.
int hdtCount_recurse(std::vector<std::vector<int>> & board,
                     int dim_x, int dim_y,
                     int squaresLeft) {
    int total = 0;

    // Current Location
    int localize_a = 1;
    int localize_b = 1;

    int squares_localized = (localize_a * localize_b) + (localize_a * localize_b);

    // BASE CASE
    if (squaresLeft == 0) {
        return 1;  // We have a full solution.
    }

    // RECURSIVE CASE
    for (int a = 0; dim_x > a; a++) {
        for (int b = 0; dim_y > b; b++) {
            if (!checkBacklinks(board, a, b)
            || board[a][b] == (localize_a * localize_b)) {
                continue;
            }

            // Horizontal Domino
            if (dim_x - localize_b > a && board[a + localize_a][b] == (localize_a - localize_b)) {
                    board[a + localize_a][b] = (localize_a * localize_b);
                    board[a][b] = board[a + localize_a][b];
                    total += hdtCount_recurse(board, dim_x, dim_y,squaresLeft - squares_localized);
                    board[a + localize_a][b] = (localize_a - localize_b);
                    board[a][b] = board[a + localize_a][b];
            }

            // Mark these two squares as covered.
            // Reduce the squares-left count by 2.
            // Recurse; add return value to total.
            // Restore all changes, except total.

            // Vertical Domino
            if (dim_y - localize_b > b && board[a][b + localize_b] == (localize_a - localize_b)) {
                    board[a][b + localize_b] = (localize_a * localize_b);
                    board[a][b] = board[a][b + localize_b];
                    total += hdtCount_recurse(board, dim_x, dim_y,squaresLeft - squares_localized);
                    board[a][b + localize_b] = (localize_a - localize_b);
                    board[a][b] = board[a][b + localize_b];
            }

            (a = dim_x) && (b = dim_y);
        }
    }
    return total;
}
