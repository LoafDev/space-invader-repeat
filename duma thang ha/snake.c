#include "include/snake.h"
#include <stdlib.h>

void draw_snake(struct Snake *snake, int *body_size)    // Print out the snake
{
    Color dark_green = {2, 125, 47, 255};
    for (int i = 0; i < *body_size; ++i)
    {
        Rectangle rect = {(float)snake->body[i].x, (float)snake->body[i].y, 36.0f, 36.0f};
        DrawRectangleRounded(rect, 0.3f, 20, dark_green);
    }
}

void init_snake(struct Snake *snake, int *body_size, Vector2 *direction)
{   
    // Facing up
    direction->x = 0;
    direction->y = -36;

    // Starting at 2 parts
    snake->body = (Vector2 *) calloc(2, sizeof(Vector2));
    *body_size = 2;

    // Two body parts in the middle of the window
    Vector2 vec1 = {432, 432};
    Vector2 vec2 = {432, 468};
    snake->body[0] = vec1;
    snake->body[1] = vec2;
}

void update_snake(struct Snake *snake, int *body_size, Vector2 *direction)  // Moving the snake
{
    for (int i = 0; i < *body_size; ++i)
    {
        snake->body[i].x += direction->x;
        snake->body[i].y += direction->y;
    }
}