#ifndef APPLE_H
#define APPLE_H

#include "../include/snake.h"

struct Apple
{
    int x, y;
};

void get_random_position_apple(struct Apple *apple);
void draw_apple(struct Apple *apple);
void is_eaten(struct Apple *apple, struct Snake *snake);

#endif
