#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 400;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKPURPLE);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}
