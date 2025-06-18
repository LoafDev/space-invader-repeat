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

void draw(Player *player);
void movement(Player *player, float delta);

#endif
