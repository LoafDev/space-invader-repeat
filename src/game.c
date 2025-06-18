#include "raylib.h"
#include"include/entry.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(60);

    Color green = {0, 255, 166, 255};
    struct Apple apple;
    struct Snake snake; init_snake(&snake);
    float UpdateFrameRate = 0.2f;
    float TimeToUpdate = 0.0f;

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();
        TimeToUpdate += delta;

        if (TimeToUpdate >= UpdateFrameRate) {
            TimeToUpdate = 0.0f;
            update_snake(&snake);
        }
        movement_snake(&snake);
        BeginDrawing();
            ClearBackground(WHITE);
            draw_snake(&snake);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
