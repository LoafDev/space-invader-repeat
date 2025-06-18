#include "include/apple.h"
#include "raylib.h"

void get_random_position(struct Apple *apple)
{
    apple->x = GetRandomValue(0, 875);
    apple->y = GetRandomValue(0, 875);
}

void draw(struct Apple *apple)
{
    get_random_position(apple);
    Rectangle rect = {(float)apple->x, (float)apple->y, 25.0f, 25.0f};
    Color red = {250, 56, 42, 255};
    DrawRectangleRounded(rect, 0.3, 20, red);
}
