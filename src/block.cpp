#include "block.hpp"
#include "colors.hpp"
#include "game.hpp"

void Block::draw() {
    // given the shape, and starting cell it draws the shape there
    // int start_r = offset_x, start_c = offset_y;
    int cell_size = CELL_SIZE - 1;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (cells[r][c]) {
                int R = (row + r) * CELL_SIZE + 1;
                int C = (col + c) * CELL_SIZE + 1;
                DrawRectangle(C, R, cell_size, cell_size, color);
            }
        }
    }
};

void Block::move(int rows, int cols) {
    row += rows;
    col += cols;
};

void Block::rotate_clock() {
    /* rotate 90 clockwise */
    /*
      00 01 02        20 10 00
      10 11 12        21 11 01
      20 21 22        22 12 02
     */
    bool temp[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            temp[c][2 - r] = cells[r][c];
        }
    }
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++) cells[r][c] = temp[r][c];
};

void Block::rotate_anti_clock() {};

Block_L::Block_L() {
    id = 1;
    color = blue;
    cells = { { { 1, 0, 0 }, { 1, 1, 1 }, { 0, 0, 0 } } };
};

Block_J::Block_J() {
    id = 2;
    color = red;
    cells = { { { 0, 0, 0 }, { 1, 1, 1 }, { 0, 0, 1 } } };
};

Block_I::Block_I() {
    id = 3;
    color = yellow;
    cells = { { { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 } } };
};

Block_S::Block_S() {
    id = 4;
    color = purple;
    cells = { { { 0, 1, 1 }, { 1, 1, 0 }, { 0, 0, 0 } } };
};

Block_T::Block_T() {
    id = 5;
    color = orange;
    cells = { { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } } };
};

Block_Z::Block_Z() {
    id = 6;
    color = dark_gray;
    cells = { { { 1, 1, 0 }, { 0, 1, 1 }, { 0, 0, 0 } } };
};
