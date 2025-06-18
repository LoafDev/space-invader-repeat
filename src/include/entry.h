#ifndef ENTRY_H
#define ENTRY_H

#include"apple.h"
#include"snake.h"

static const float SIZE = 36.0f;
static const int HEIGHT = 900;
static const int WIDTH = 900;
static const float UPDATE_FRAME_RATE = 0.2f;


void clamp(float *val, float minv, float maxv);

#endif
