#include "block.hpp"
#include "game.hpp"
#include "raylib.h"

int main() {

    Game_Load_Assets();
    Block block;

    // Game Clock
    double game_start_time = 0.0;
    const double interval = 0.5;

    block = get_random_block();
    block.insert_into_game(0, 3); // Initial position (centered horizontally)

    // Main game loop
    while (!WindowShouldClose()) {
        double currentTime = GetTime();

        // For Every Interval
        if (currentTime - game_start_time >= interval) {
            // printf("Message at %.2f seconds\n", currentTime);
            game_start_time = currentTime;
            block.move(1, 0);

            // block hit bottom or another block
            // if (block.) {
            // create new block
            // }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        draw_cells();
        handle_keyboard(block);

        /*
        if (check_old_block(block)) {
            printf("HIT BOTTOM\n");
        }
         */

        EndDrawing();
    }

    Game_UnLoad_Assets();

    return 0;
}
