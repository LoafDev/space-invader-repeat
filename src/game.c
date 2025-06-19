#include "raylib.h"
#include"include/entry.h"

void clamp(float *val, float minv, float maxv) {
    if (*val <= minv) { *val = minv; }
    if (*val >= maxv) { *val = maxv; }
}

int main()
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(60);

    Color green = {0, 255, 166, 255};
    struct Apple apple;
    struct Snake snake; 
    float TimeToUpdate = 0.0f;

    init_snake(&snake);

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();
        TimeToUpdate += delta;


        if (TimeToUpdate >= UPDATE_FRAME_RATE) {
            TimeToUpdate = 0.0f;
            get_random_position_apple(&apple);
            update_snake(&snake);
        }
        movement_snake(&snake);

        BeginDrawing();
            ClearBackground(WHITE);
            draw_snake(&snake);
            draw_apple(&apple);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}