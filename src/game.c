#include"include/entry.h"
#include <stdio.h>

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

    int current_score = 0;
    int high_score; 
    
    FILE *high_score_ptr = fopen("high_score.txt", "r+");
    fscanf(high_score_ptr, "%d", &high_score);
    
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
                    DrawText(TextFormat("Best Score:  %d", high_score), 15, 15, 30, BLACK);
                    DrawText("Snake Game", WIDTH / 2 - MeasureText("Snake Game", 30) / 2, HEIGHT / 2 - 10, 30, GREEN);
                    DrawText("Press ENTER to Start", WIDTH / 2 - MeasureText("Press ENTER to Start", 30) / 2, HEIGHT / 2 + 20, 30, DARKGRAY);
                } break;
                case GAMEPLAY:
                {
                    TimeToUpdate += delta;
                    movement_snake(&snake);
                    if (TimeToUpdate >= UPDATE_FRAME_RATE) {
                        TimeToUpdate = 0.0f;
                        snake_eats_apple(&apple, &snake, &current_score);
                        update_snake(&snake);
                        snake_eats_snake(&snake, &currentScreen);

                        //printf("%d\n", current_score);
                        if (current_score > high_score)
                        {
                            rewind(high_score_ptr);
                            fprintf(high_score_ptr, "%d", current_score);
                            high_score = current_score;
                        }
                    }
                    draw_apple(&apple);
                    draw_snake(&snake);
                    DrawText(TextFormat("Current Score:  %d", current_score), 15, 15, 30, BLACK);
                } break;
                case PAUSE:
                {   
                    draw_apple(&apple);
                    draw_snake(&snake);
                    DrawText("Game Paused", WIDTH / 2 - MeasureText("Game Paused", 30) / 2, HEIGHT / 2 - 10, 30, RED);
                    DrawText("Press P to Resume", WIDTH / 2 - MeasureText("Press P to Resume", 30) / 2, HEIGHT / 2 + 20, 30, DARKGRAY);
                    
                    if (IsKeyPressed(KEY_D)) {
                        DebugSnake(&snake);
                    }
                } break;
                case END:
                {
                    DrawText("Game Over", WIDTH / 2 - MeasureText("Game Over", 30) / 2, HEIGHT / 2 - 10, 30, RED);
                    DrawText("Press ENTER to Restart", WIDTH / 2 - MeasureText("Press ENTER to Restart", 30) / 2, HEIGHT / 2 + 20, 30, DARKGRAY);
                } break;
            }
                      
        EndDrawing();
    }

    CloseWindow();
    return 0;
}