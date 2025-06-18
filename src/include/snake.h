#ifndef SNAKE_H
#define SNAKE_H

#include<raylib.h>

typedef enum {
    Left,
    Right,
    Up,
    Down
} Direction;

typedef struct {
    Vector2 pos;
    Direction dir;
    int body;
} Player;

void draw_snake(Player *player);
void movement_snake(Player *player, float delta);

#endif
