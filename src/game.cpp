#include "game.hpp"
#include "block.hpp"
#include "colors.hpp"
#include "raylib.h"

// Game State Variables
Sound sound_rotate;
Sound sound_move;

// Game Start
void Game_Load_Assets() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(SCREEN_FPS);
    InitAudioDevice();
    sound_rotate = LoadSound("./assets/rotate.wav");
    sound_move = LoadSound("./assets/move.wav");
};

// Game End
void Game_UnLoad_Assets() {
    // Cleanup
    UnloadSound(sound_rotate);
    UnloadSound(sound_move);
    CloseAudioDevice();
    CloseWindow();
};

std::array<std::array<Color, GAME_COLS>, GAME_ROWS> data = []() {
    std::array<std::array<Color, GAME_COLS>, GAME_ROWS> res = {};
    for (auto& row : res)
        for (auto& cell : row) cell = EMPTY_COLOR;
    return res;
}();

std::array<Block, TOTAL_BLOCKS> ALL_BLOCKS = { Block_L(), Block_J(), Block_I(),
                                               Block_O(), Block_S(), Block_T(),
                                               Block_Z() };

// Draws all the game cells(colors)
void draw_cells() {
    for (int r = 0; r < GAME_ROWS; r++) {
        for (int c = 0; c < GAME_COLS; c++) {
            Color color = data[r][c];
            DrawRectangle(c * CELL_SIZE + 1, r * CELL_SIZE + 1, CELL_SIZE - 1,
                          CELL_SIZE - 1, color);
        }
    }
};

// Collision detection for a block at given position
bool clash_detection(const Block& block, int origin_r, int origin_c) {
    for (size_t r = 0; r < block.block_data.size(); r++) {
        for (size_t c = 0; c < block.block_data[0].size(); c++) {
            if (block.block_data[r][c]) { // If this cell of the block is filled
                int game_r = origin_r + r;
                int game_c = origin_c + c;

                // Check bounds
                if (game_r < 0 || game_r >= GAME_ROWS || game_c < 0 ||
                    game_c >= GAME_COLS) {
                    return true; // Out of bounds = clash
                }

                // Check if grid cell is occupied (not dark_gray)
                if (data[game_r][game_c] != dark_gray) {
                    return true; // Occupied = clash
                }
            }
        }
    }
    return false; // No clash
}
