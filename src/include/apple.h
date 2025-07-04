#ifndef APPLE_H
#define APPLE_H

#include "../include/snake.h"

struct Apple
{
    float x, y;
};

void get_random_position_apple(struct Apple *apple);
void draw_apple(struct Apple *apple);
void snake_eats_apple(struct Apple *apple, struct Snake *snake, int *current_score);

#endif
