#include "raylib.h"
#include"include/entry.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(4);

    Color green = {0, 255, 166, 255};
    struct Apple apple;
    struct Snake snake; init_snake(&snake);

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        update_snake(&snake);

        BeginDrawing();
            ClearBackground(green);
            draw_snake(&snake);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
