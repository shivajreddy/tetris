#include "game.hpp"
#include "raylib.h"
#include "grid.hpp"
#include "colors.hpp"

// Game
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 600;

// Grid
extern const int GAME_ROWS = 20;
extern const int GAME_COLS = 10;
const int CELL_SIZE = 30;


// Game State Variables
Grid grid = Grid(GAME_ROWS, GAME_COLS, CELL_SIZE);
Sound sound_rotate;
Sound sound_move;

// Game Start
void GameStart() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(60);
    InitAudioDevice();
    sound_rotate = LoadSound("./assets/rotate.wav");
    sound_move = LoadSound("./assets/move.wav");
};

// Game End
void GameEnd() {
    // Cleanup
    UnloadSound(sound_rotate);
    UnloadSound(sound_move);
    CloseAudioDevice();
    CloseWindow();
};
