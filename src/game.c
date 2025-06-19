#include "raylib.h"
#include"include/entry.h"

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    struct Apple apple;
    struct Snake snake; 
    bool Is_Paused = false;
    Image Screenshot;
    Texture2D BlurTex;
    float TimeToUpdate = 0.0f;
    
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, "Snake");
    GameScreen currentScreen = MENU;
    init_snake(&snake);
    get_random_position_apple(&apple);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_P)) {
            Is_Paused = !Is_Paused;
        }

        float delta = GetFrameTime();

        if (!Is_Paused) {
            TimeToUpdate += delta;
            if (TimeToUpdate >= UPDATE_FRAME_RATE) {
                TimeToUpdate = 0.0f;
                snake_eats_apple(&apple, &snake);
                update_snake(&snake);
            }
            movement_snake(&snake);
            
        } else {
            if (IsKeyPressed(KEY_D)) {
                DebugSnake(&snake);
            }
        }


        BeginDrawing();
            ClearBackground(WHITE);
            draw_snake(&snake);
            draw_apple(&apple);
            if (Is_Paused) {
                DrawText("Game Paused", WIDTH / 2 - MeasureText("Game Paused", 20) / 2, HEIGHT / 2 - 10, 20, RED);
            }
        EndDrawing();

    }

    CloseWindow();
    return 0;
}