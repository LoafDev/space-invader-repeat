#include "include/entry.h"
#include <stdlib.h>

void draw_snake(struct Snake *snake)
{
    Color dark_green = {2, 125, 47, 255};
    for (int i = 0; i < snake->body_size; ++i)
    {
        Rectangle rect = {(float)snake->body[i].x, (float)snake->body[i].y, SIZE, SIZE};
        DrawRectangleRounded(rect, 0.3f, 20, dark_green);
    }
}

void init_snake(struct Snake *snake)
{
    // facing up
    snake->direction = (Vector2){ 0, SIZE };

    // Starting at 2 parts
    /* snake->body = (Vector2 *) calloc(2, sizeof(Vector2));
    snake->body_size = 2; */

    snake->body = (Vector2 *) calloc(3, sizeof(Vector2));
    snake->body_size = 3;


    // Two body parts in the middle of the window
    for (int i=0; i < snake->body_size; i++) {
        snake->body[i] = (Vector2){ 432, 432 + i * SIZE };
    }
}

void update_snake(struct Snake *snake)  // Moving the snake
{
    for (int i = 0; i < snake->body_size; ++i)
    {
        snake->body[i].x += snake->direction.x;
        snake->body[i].y += snake->direction.y;

        clamp(&snake->body[i].x, 0 + SIZE * i, WIDTH - SIZE * (i+1));
        clamp(&snake->body[i].y, 0 + SIZE * i, HEIGHT - SIZE * (i+1));
    }
}
