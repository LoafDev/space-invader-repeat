#include "raylib.h"
#include"include/entry.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;
Color green = {0, 255, 166, 255};
struct Apple apple;
struct Snake snake; 
float TimeToUpdate = 0.0f;
bool Is_Paused = false;
Image Screenshot;
Texture2D BlurTex;

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    //--------------------------------------------------------------------------------------
    // Initialize all 
    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, "Snake");
    GameScreen currentScreen = LOGO;

    init_snake(&snake);

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
                get_random_position_apple(&apple);
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