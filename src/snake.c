#include "include/entry.h"
#include <stdlib.h>
#include <stdio.h>
#include "raymath.h"
#include "include/apple.h"

void clamp(float *val, float minv, float maxv) {
    if (*val <= minv) { *val = minv; }
    if (*val >= maxv) { *val = maxv; }
}

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

void normal_movement(struct Snake *snake) {
    for (int i = snake->body_size - 1; i > 0; --i)
    {
        snake->body[i].x += snake->direction.x;
        snake->body[i].y += snake->direction.y;


        snake->body[i].x = snake->body[i-1].x;
        snake->body[i].y = snake->body[i-1].y;
    }
    snake->body[0].x = snake->head.x;
    snake->body[0].y = snake->head.y;

    snake->head.x += snake->direction.x;
    snake->head.y += snake->direction.y;
}

void update_snake(struct Snake *snake)  // Moving the snake
{
    // check head's out of bound movement
    if (snake->head.x <= 0 || snake->head.x >= WIDTH - SIZE || snake->head.y <= 0 || snake->head.y >- HEIGHT - SIZE) {
        snake->head.x += snake->direction.x;
        snake->head.y += snake->direction.y;

        clamp(&snake->head.x, 0, WIDTH - SIZE);
        clamp(&snake->head.y, 0, HEIGHT - SIZE);
    }
    else {
        normal_movement(snake);
    }
}

void movement_snake(struct Snake *snake)
{
    if (IsKeyPressed(KEY_UP) && snake->direction.y == 0)
    {
        snake->direction = (Vector2){0, -SIZE};
    }
    else if (IsKeyPressed(KEY_DOWN) && snake->direction.y == 0)
    {
        snake->direction = (Vector2){0, SIZE};
    }
    else if (IsKeyPressed(KEY_LEFT) && snake->direction.x == 0)
    {
        snake->direction = (Vector2){-SIZE, 0};
    }
    else if (IsKeyPressed(KEY_RIGHT) && snake->direction.x == 0)
    {
        snake->direction = (Vector2){SIZE, 0};
    }
}

void expand_snake(struct Snake *snake)
{
    snake->body = (Vector2 *) realloc(snake->body, snake->body_size + 1);
    snake->body[snake->body_size] = Vector2Add(snake->body[snake->body_size - 1], (Vector2){-1 * snake->direction.x, -1 * snake->direction.y});
    ++(snake->body_size);
}