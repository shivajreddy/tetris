#include "grid.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

using namespace std;

vector<Color> get_colors();

Grid::Grid(int r, int c, int cellsize) {
    rows = r;
    cols = c;
    cell_size = cellsize;
    init();
    colors = get_colors();
};

void Grid::init() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) grid[r][c] = 0;
    }
};

void Grid::print() {
    cout << "Printing Grid\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) cout << grid[r][c] << " ";
        cout << endl;
    }
};

void Grid::draw() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int cell_val = grid[r][c];
            DrawRectangle(c * cell_size + 1, r * cell_size + 1, cell_size - 1, cell_size - 1, colors[cell_val]);
        }
    }
};

vector<Color> get_colors() {
    Color dark_gray = { 26, 31, 40, 255 };
    Color green = { 47, 230, 23, 255 };
    Color red = { 232, 18, 18, 255 };
    Color orange = { 226, 116, 17, 255 };
    Color yellow = { 237, 234, 4, 255 };
    Color purple = { 166, 0, 247, 255 };
    Color cyan = { 21, 204, 209, 255 };
    Color blue = { 13, 64, 216, 255 };
    return { dark_gray, green, red, orange, yellow, purple, cyan, blue };
};
