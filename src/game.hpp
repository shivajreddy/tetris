#pragma once
#include "block.hpp"
#include "raylib.h"
#include <array>

// Game Constant Variables
constexpr int SCREEN_WIDTH = 300;
constexpr int SCREEN_HEIGHT = 600;
constexpr int SCREEN_FPS = 60;
constexpr int GAME_ROWS = 20;
constexpr int GAME_COLS = 10;
constexpr int CELL_SIZE = 30;

// Game State
constexpr int TOTAL_BLOCKS = 7;
extern std::array<std::array<Color, GAME_COLS>, GAME_ROWS> data;
extern std::array<Block, TOTAL_BLOCKS> ALL_BLOCKS;

// Game Sound Variables
extern Sound sound_rotate;
extern Sound sound_move;

extern void Game_Load_Assets();
extern void Game_UnLoad_Assets();

extern void draw_cells();
extern bool clash_detection(const Block& block, int origin_r, int origin_c);
