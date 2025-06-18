#ifndef APPLE_H

#define APPLE_H

struct Apple
{
    int x, y;
};

void get_random_position_apple(struct Apple *apple);
void draw_apple(struct Apple *apple);

#endif
