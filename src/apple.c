#include "include/entry.h"
#include "raylib.h"

void get_random_position_apple(struct Apple *apple)
{
    apple->x = GetRandomValue(0, 864);
    apple->y = GetRandomValue(0, 864);
}

void draw_apple(struct Apple *apple)
{
    Rectangle rect = {(float)apple->x, (float)apple->y, SIZE, SIZE};
    Color red = {250, 56, 42, 255};
    DrawRectangleRounded(rect, 0.3f, 20, red);
}
