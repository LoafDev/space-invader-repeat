#include "raylib.h"
#include "include/apple.h" 

int main()
{
    InitWindow(900, 900, "Snake");
    SetTargetFPS(60);

    Color green = {0, 255, 166, 255};
    struct Apple apple;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(green);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
