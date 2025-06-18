#include "include/snake.h"
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
    Vector2 direction = { 0, -SIZE };

    // Starting at 2 parts
    snake->body = (Vector2 *) calloc(2, sizeof(Vector2));
    snake->body_size = 2;

    // Two body parts in the middle of the window
    Vector2 vec1 = {432, 432};
    Vector2 vec2 = {432, 468};
    snake->body[0] = vec1;
    snake->body[1] = vec2;
}

void update_snake(struct Snake *snake)  // Moving the snake
{
    for (int i = 0; i < snake->body_size; ++i)
    {
        snake->body[i].x += snake->direction.x;
        snake->body[i].y += snake->direction.y;
    }
}
