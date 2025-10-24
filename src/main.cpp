#include "block.hpp"
#include "game.hpp"
#include "grid.hpp"
#include "raylib.h"

int main() {

    GameStart(); // Initialize GAME

    Block_S block;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        // ClearBackground({ 44, 44, 127, 255 });
        ClearBackground(BLACK);
        grid.draw();
        int key = GetKeyPressed();
        switch (key) {
        case KEY_SPACE:
            PlaySound(sound_rotate);
            if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
                block.rotate_anti_clock();
            } else {
                block.rotate_clock();
            }
            break;
        case KEY_LEFT:
            PlaySound(sound_move);
            block.move(0, -1);
            break;
        case KEY_RIGHT:
            PlaySound(sound_move);
            block.move(0, 1);
            break;
        case KEY_DOWN:
            PlaySound(sound_move);
            block.move(1, 0);
            break;
        case KEY_UP:
            PlaySound(sound_move);
            block.move(-1, 0);
            break;
        }
        block.draw();
        EndDrawing();
    }

    GameEnd(); // Clean up GAME

    return 0;
}
