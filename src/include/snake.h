#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include "apple.h"
#include "gamestate.h"

struct Snake
{
    Vector2 direction;
    Vector2 *body;
    Vector2 head;
    int body_size;
};

void init_snake(struct Snake *snake);
void draw_snake(struct Snake *snake);
void update_snake(struct Snake *snake);
void movement_snake(struct Snake *snake);
void DebugSnake(struct Snake *snake);
void expand_snake(struct Snake *snake);
void snake_eats_snake(struct Snake *snake, GameScreen *current_screen);

#endif
