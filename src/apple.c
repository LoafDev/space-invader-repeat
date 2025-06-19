#include "include/entry.h"
#include "include/snake.h"
#include "raylib.h"

void get_random_position_apple(struct Apple *apple)
{
    float pos[] = {0, 36, 72, 108, 144, 180, 216, 252, 288, 324, 360, 396, 432, 468, 504, 540, 576, 612, 648, 684, 720, 756, 792, 828, 864};
    apple->x = pos[GetRandomValue(0, 24)];
    apple->y = pos[GetRandomValue(0, 24)];
}

void draw_apple(struct Apple *apple)
{
    Rectangle rect = {(float)apple->x, (float)apple->y, SIZE, SIZE};
    Color red = {250, 56, 42, 255};
    DrawRectangleRounded(rect, 0.3f, 20, red);
}

void snake_eats_apple(struct Apple *apple, struct Snake *snake)
{
    if (CheckCollisionPointRec(snake->head, (Rectangle){apple->x, apple->y, SIZE, SIZE}))
    {
        get_random_position_apple(apple);
        expand_snake(snake);
    }
}

