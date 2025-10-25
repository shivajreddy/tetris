#include "block.hpp"
#include "game.hpp"
#include "raylib.h"

int main() {

    Game_Load_Assets();
    auto block = get_random_block();
    block.insert_into_game(0, 3); // Initial position (centered horizontally)

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        draw_cells();

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
        draw_cells();
        EndDrawing();
    }

    Game_UnLoad_Assets();

    return 0;
}
