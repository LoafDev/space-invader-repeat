#ifndef APPLE_H

#define APPLE_H

struct Apple
{
    int x, y;
};

void get_random_position(struct Apple *apple);
void draw(struct Apple *apple);

#endif