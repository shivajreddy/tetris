#pragma once
#include "raylib.h"
#include "grid.hpp"

// Game
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// Grid
extern const int GAME_ROWS;
extern const int GAME_COLS;
extern const int CELL_SIZE;

// Game State Variables
extern Grid grid;
extern Sound sound_rotate;
extern Sound sound_move;

void GameStart();
void GameEnd();
