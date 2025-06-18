#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"

struct Snake
{
    Vector2 direction;
    Vector2 *body;

    int body_size;
};

void init_snake(struct Snake *snake, int *body_size, Vector2 *direction);
void draw_snake(struct Snake *snake, int *body_size);
void update_snake(struct Snake *snake, int *body_size, Vector2 *direction);

#endif