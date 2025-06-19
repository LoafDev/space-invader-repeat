#include "include/entry.h"
#include <stdlib.h>
#include <stdio.h>

void draw_snake(struct Snake *snake)
{
    Color dark_green = {2, 125, 47, 255};
    
    DrawRectangleRounded((Rectangle){snake->head.x, snake->head.y, SIZE, SIZE},
                         0.3f, 
                         20, 
                         dark_green);

    for (int i = 0; i < snake->body_size; ++i)
    {
        Rectangle rect = {(float)snake->body[i].x,
                          (float)snake->body[i].y, 
                          SIZE, 
                          SIZE};
        DrawRectangleRounded(rect,
                             0.3f,
                             20, 
                             dark_green);
    }
}

void init_snake(struct Snake *snake)
{
    // facing up
    snake -> direction = (Vector2){ 0, -SIZE };

    // Starting at 2 parts
    snake->body = (Vector2 *) calloc(2, sizeof(Vector2));
    snake->body_size = 2;

    // Two body parts in the middle of the window
    
    snake->head = (Vector2){WIDTH / 2 - SIZE / 2, HEIGHT / 2 - SIZE / 2};
    for (int i=0; i < snake->body_size; i++) {
        snake->body[i] = (Vector2){ snake->head.x, snake->head.y + i * SIZE };
    }
}

void update_snake(struct Snake *snake)  // Moving the snake
{
    for (int i = snake->body_size - 1; i > 0; --i)
    {
        snake->body[i].x += snake->direction.x;
        snake->body[i].y += snake->direction.y;


        snake->body[i].x = snake->body[i-1].x;
        snake->body[i].y = snake->body[i-1].y;
    }
    snake->body[0].x = snake->head.x;
    snake->body[0].y = snake->head.y;

    if (snake->head.x + snake->direction.x < 0 ||
        snake->head.x + snake->direction.x >= WIDTH ||
        snake->head.y + snake->direction.y < 0 ||
        snake->head.y + snake->direction.y >= HEIGHT)
    {
        if (snake->head.x + snake->direction.x < 0)
            snake->head.x = WIDTH - SIZE;
        else if (snake->head.x + snake->direction.x >= WIDTH)
            snake->head.x = 0;
        else
            snake->head.x += snake->direction.x;

        if (snake->head.y + snake->direction.y < 0)
            snake->head.y = HEIGHT - SIZE;
        else if (snake->head.y + snake->direction.y >= HEIGHT)
            snake->head.y = 0;
        else
            snake->head.y += snake->direction.y;
    }
    else
    {
        snake->head.x += snake->direction.x;
        snake->head.y += snake->direction.y;
    }
}

bool movement_snake(struct Snake *snake)
{
    if (IsKeyPressed(KEY_UP) && snake->direction.y == 0)
    {
        snake->direction = (Vector2){0, -SIZE};
        return true;
    }
    else if (IsKeyPressed(KEY_DOWN) && snake->direction.y == 0)
    {
        snake->direction = (Vector2){0, SIZE};
        return true;
    }
    else if (IsKeyPressed(KEY_LEFT) && snake->direction.x == 0)
    {
        snake->direction = (Vector2){-SIZE, 0};
        return true;
    }
    else if (IsKeyPressed(KEY_RIGHT) && snake->direction.x == 0)
    {
        snake->direction = (Vector2){SIZE, 0};
        return true;
    }
    return false;
}

void DebugSnake(struct Snake *snake)
{
    printf("Snake head position: (%.2f, %.2f)\n", snake->head.x, snake->head.y);
    printf("Snake direction: (%.2f, %.2f)\n", snake->direction.x, snake->direction.y);
    printf("Snake body size: %d\n", snake->body_size);
    for (int i = 0; i < snake->body_size; ++i)
    {
        printf("Body part %d position: (%.2f, %.2f)\n", i, snake->body[i].x, snake->body[i].y);
    }
    printf(" ");
}