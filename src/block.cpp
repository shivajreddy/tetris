#include "block.hpp"
#include "colors.hpp"
#include "game.hpp"
#include "raylib.h"
#include <random>
#include <stdio.h>

void Block::insert_into_game(int pos_r, int pos_c) {
    origin_r = pos_r;
    origin_c = pos_c;
    for (size_t r = 0; r < block_data.size(); r++) {
        for (size_t c = 0; c < block_data[0].size(); c++) {
            if (block_data[r][c]) {     // Check if this block cell is filled
                int game_r = pos_r + r; // Game grid row
                int game_c = pos_c + c; // Game grid col

                // Bounds check
                if (game_r >= 0 && game_r < GAME_ROWS && game_c >= 0 &&
                    game_c < GAME_COLS) {
                    data[game_r][game_c] = color;
                }
            }
        }
    }
}

void Block::move(int rows, int cols) {
    // Clear old position FIRST
    for (size_t r = 0; r < block_data.size(); r++) {
        for (size_t c = 0; c < block_data[0].size(); c++) {
            if (block_data[r][c]) {
                int game_r = origin_r + r;
                int game_c = origin_c + c;
                if (game_r >= 0 && game_r < GAME_ROWS && game_c >= 0 &&
                    game_c < GAME_COLS) {
                    data[game_r][game_c] = dark_gray;
                }
            }
        }
    }

    // Calculate new position
    int new_r = origin_r + rows;
    int new_c = origin_c + cols;

    // Check collision at new position
    if (!clash_detection(*this, new_r, new_c)) {
        PlaySound(sound_move);
        origin_r = new_r;
        origin_c = new_c;
    }
    // If collision, origin_r and origin_c stay at old values

    // Insert at final position (either new or old)
    insert_into_game(origin_r, origin_c);
}

void Block::rotate_clock() {
    // Clear old position
    for (size_t r = 0; r < block_data.size(); r++) {
        for (size_t c = 0; c < block_data[0].size(); c++) {
            if (block_data[r][c]) {
                int game_r = origin_r + r;
                int game_c = origin_c + c;
                if (game_r >= 0 && game_r < GAME_ROWS && game_c >= 0 &&
                    game_c < GAME_COLS) {
                    data[game_r][game_c] = dark_gray;
                }
            }
        }
    }

    // Rotate
    std::array<std::array<bool, 3>, 3> temp = {};
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            temp[c][2 - r] = block_data[r][c];
        }
    }

    // Check if rotation causes collision
    std::array<std::array<bool, 3>, 3> old_data = block_data;
    block_data = temp;

    if (clash_detection(*this, origin_r, origin_c)) {
        // Revert rotation if it would cause collision
        block_data = old_data;
    }

    // Re-insert at current position
    insert_into_game(origin_r, origin_c);
}

void Block::rotate_anti_clock() {
    // Clear old position
    for (size_t r = 0; r < block_data.size(); r++) {
        for (size_t c = 0; c < block_data[0].size(); c++) {
            if (block_data[r][c]) {
                int game_r = origin_r + r;
                int game_c = origin_c + c;
                if (game_r >= 0 && game_r < GAME_ROWS && game_c >= 0 &&
                    game_c < GAME_COLS) {
                    data[game_r][game_c] = dark_gray;
                }
            }
        }
    }

    // Rotate
    std::array<std::array<bool, 3>, 3> temp = {};
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            temp[2 - c][r] = block_data[r][c];
        }
    }

    // Check if rotation causes collision
    std::array<std::array<bool, 3>, 3> old_data = block_data;
    block_data = temp;

    if (clash_detection(*this, origin_r, origin_c)) {
        // Revert rotation if it would cause collision
        block_data = old_data;
    }

    // Re-insert at current position
    insert_into_game(origin_r, origin_c);
}

Block get_random_block() {
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(0, TOTAL_BLOCKS - 1); // range [0, n]
    size_t random_idx = dist(gen);
    printf("random_idx: %zd\n", random_idx);
    return ALL_BLOCKS[random_idx];
}

/* Instantiate all Blocks */
Block_L::Block_L() {
    id = 1;
    color = blue;
    block_data = { { { 1, 0, 0 }, { 1, 1, 1 }, { 0, 0, 0 } } };
};

Block_J::Block_J() {
    id = 2;
    color = red;
    block_data = { { { 0, 0, 0 }, { 1, 1, 1 }, { 0, 0, 1 } } };
};

Block_I::Block_I() {
    id = 3;
    color = yellow;
    block_data = { { { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 } } };
};

Block_O::Block_O() {
    id = 4;
    color = yellow;
    block_data = { { { 1, 1, 0 }, { 1, 1, 0 }, { 1, 1, 0 } } };
};

Block_S::Block_S() {
    id = 5;
    color = purple;
    block_data = { { { 0, 1, 1 }, { 1, 1, 0 }, { 0, 0, 0 } } };
};

Block_T::Block_T() {
    id = 6;
    color = orange;
    block_data = { { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } } };
};

Block_Z::Block_Z() {
    id = 7;
    color = green;
    block_data = { { { 1, 1, 0 }, { 0, 1, 1 }, { 0, 0, 0 } } };
}
