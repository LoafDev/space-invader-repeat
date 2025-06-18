#include "raylib.h"
#include"include/entry.h"

void clamp(float *val, float minv, float maxv) {
    if (*val <= minv) { *val = minv; }
    if (*val >= maxv) { *val = maxv; }
}

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
        get_random_position_apple(&apple);

        BeginDrawing();
            ClearBackground(green);
            draw_snake(&snake);
            draw_apple(&apple);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
