#include "block.hpp"
#include "game.hpp"
#include "grid.hpp"
#include "raylib.h"
#include <array>

using namespace std;


int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(60);
    InitAudioDevice();
    auto sound_rotate = LoadSound("./assets/rotate.wav");

    Grid grid = Grid(GAME_ROWS, GAME_COLS, CELL_SIZE);
    grid.print();

    Block_L block;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        // ClearBackground({ 44, 44, 127, 255 });
        ClearBackground(BLACK);
        grid.draw();
        int key = GetKeyPressed();
        switch(key) {
          case KEY_SPACE:
            PlaySound(sound_rotate);
            block.rotate_clock();
            break;
          case KEY_LEFT:
            block.move(0, -1);
            break;              
          case KEY_RIGHT:
            block.move(0, 1);
            break;
          case KEY_DOWN:
            block.move(1, 0);              
            break;
          case KEY_UP:
            block.move(-1, 0);              
            break;
        }
        block.draw();
        EndDrawing();
    }

    // Cleanup
    UnloadSound(sound_rotate);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

