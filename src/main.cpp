#include "raylib.h"
#include <iostream>
#include "grid.h"

using namespace std;

int main() {
    const int SCREEN_WIDTH = 300;
    const int SCREEN_HEIGHT = 600;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid(20, 10, 30);    
    grid.print();

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({44, 44, 127, 255});
	grid.draw();
        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}
