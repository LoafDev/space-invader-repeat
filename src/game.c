#include "raylib.h"
#include"include/entry.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(4);

    Color green = {0, 255, 166, 255};
    struct Apple apple;
    Player player = { (Vector2){ 0,0 }, 0, Down };

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        movement_snake(&player, delta);

        BeginDrawing();
            ClearBackground(green);
            draw_snake(&player);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
