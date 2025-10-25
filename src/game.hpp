#pragma once
#include "raylib.h"
#include <array>
#include "block.hpp"

// Game App Variables
constexpr int SCREEN_WIDTH = 300;
constexpr int SCREEN_HEIGHT = 600;

// Game Grid Variables
constexpr int GAME_ROWS = 20;
constexpr int GAME_COLS = 10;
constexpr int CELL_SIZE = 30;

// Game State
extern std::array<std::array<Color, GAME_COLS>, GAME_ROWS> data;

// Game Sound Variables
extern Sound sound_rotate;
extern Sound sound_move;

extern void Game_Load_Assets();
extern void Game_UnLoad_Assets();

extern void draw_cells();
// extern bool clash_detection(int r, int c);
extern bool clash_detection(const Block& block, int origin_r, int origin_c);
