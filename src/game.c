#include"include/entry.h"

int main()
{   
    struct Apple apple;
    struct Snake snake; 
    float TimeToUpdate = 0.0f;
    Image Screenshot;
    Texture2D BlurTex;
    
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, "Snake");
    GameScreen currentScreen = MENU;
    init_snake(&snake);
    get_random_position_apple(&apple);

    while (!WindowShouldClose())
    {

        switch (currentScreen)
        {
        case MENU:
        {
            if (IsKeyPressed(KEY_ENTER)) 
            {
                currentScreen = GAMEPLAY;
            }   
        } break;

        case GAMEPLAY:
        {
            if (IsKeyPressed(KEY_P)) 
            {
                currentScreen = PAUSE;
            }
        } break;

        case PAUSE:
        {
            if (IsKeyPressed(KEY_P)) 
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        
        case END:
        {
            if (IsKeyPressed(KEY_ENTER)) 
            {
                currentScreen = MENU;
                init_snake(&snake);
                get_random_position_apple(&apple);
            }
        } break;

        default: break;
        }

        float delta = GetFrameTime();

        BeginDrawing();
            ClearBackground(WHITE);

            switch (currentScreen)
            {
                case MENU:
                {
                    DrawText("Snake Game", WIDTH / 2 - MeasureText("Snake Game", 20) / 2, HEIGHT / 2 - 10, 20, GREEN);
                    DrawText("Press ENTER to Start", WIDTH / 2 - MeasureText("Press ENTER to Start", 20) / 2, HEIGHT / 2 + 20, 20, DARKGRAY);
                } break;
                case GAMEPLAY:
                {
                    TimeToUpdate += delta;
                    movement_snake(&snake);
                    if (TimeToUpdate >= UPDATE_FRAME_RATE) {
                        TimeToUpdate = 0.0f;
                        snake_eats_apple(&apple, &snake);
                        update_snake(&snake);
                        snake_eats_snake(&snake, &currentScreen);
                    }
                    draw_apple(&apple);
                    draw_snake(&snake);
                } break;
                case PAUSE:
                {   
                    draw_apple(&apple);
                    draw_snake(&snake);
                    DrawText("Game Paused", WIDTH / 2 - MeasureText("Game Paused", 20) / 2, HEIGHT / 2 - 10, 20, RED);
                    DrawText("Press P to Resume", WIDTH / 2 - MeasureText("Press P to Resume", 20) / 2, HEIGHT / 2 + 20, 20, DARKGRAY);
                    
                    if (IsKeyPressed(KEY_D)) {
                        DebugSnake(&snake);
                    }
                } break;
                case END:
                {
                    DrawText("Game Over", WIDTH / 2 - MeasureText("Game Over", 20) / 2, HEIGHT / 2 - 10, 20, RED);
                    DrawText("Press ENTER to Restart", WIDTH / 2 - MeasureText("Press ENTER to Restart", 20) / 2, HEIGHT / 2 + 20, 20, DARKGRAY);
                } break;
            }
                      
        EndDrawing();
    }

    CloseWindow();
    return 0;
}