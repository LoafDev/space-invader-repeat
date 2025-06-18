#include "include/apple.h"
#include "raylib.h"

void get_random_position(struct Apple *apple)
{
    apple->x = GetRandomValue(0, 864);
    apple->y = GetRandomValue(0, 864);
}

void draw(struct Apple *apple)
{
    Rectangle rect = {(float)apple->x, (float)apple->y, 36.0f, 36.0f};
    Color red = {250, 56, 42, 255};
    DrawRectangleRounded(rect, 0.3, 20, red);
}
