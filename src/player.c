#include<stdlib.h>
#include<raylib.h>
#include"include/snake.h"

const float SPEED = 1000.0f;
const Vector2 SIZE = { 32, 32 };

void clamp(float min_val, float max_val, float *cur_val) {
    if (*cur_val <= min_val) { *cur_val = min_val; }
    if (*cur_val >= max_val) { *cur_val = max_val; }
}

void draw(Player *player) {
    for (int i=0; i < player->body; i++) {
        DrawRectangle(player->pos.x, player->pos.y, SIZE.x, SIZE.y, GREEN);
    }
}

void movement(Player *player, float delta) {
    if (IsKeyPressed(KEY_W)) { player->dir = Up; }
    else if (IsKeyPressed(KEY_S)) { player->dir = Down; }
    else if (IsKeyPressed(KEY_A)) { player->dir = Left; }
    else if (IsKeyPressed(KEY_D)) { player->dir = Right; }

    switch(player->dir) {
        case Left:
            player->pos.x -= SPEED * delta;
            break;
        case Right:
            player->pos.x += SPEED * delta;
            break;
        case Up:
            player->pos.y -= SPEED * delta;
            break;
        case Down:
            player->pos.y += SPEED * delta;
            break;
    }
    clamp(0, 900 - SIZE.x, &player->pos.x);
    clamp(0, 900 - SIZE.y, &player->pos.y);
}

// for testing
/* int main() {
    InitWindow(900, 900, "test");
    SetTargetFPS(60);
    Player player = { (Vector2){0,0}, Down, 1 };

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        movement(&player, delta);

        BeginDrawing();
        ClearBackground(WHITE);
        draw(&player);
        EndDrawing();
    }
    CloseWindow();
    return 0;
} */
