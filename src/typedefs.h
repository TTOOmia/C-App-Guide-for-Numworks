#pragma once

typedef struct Vector2 {
    uint16_t x, y;
} Vector2;

typedef struct Player {
    Vector2 pos;
    uint16_t xspd, yspd;
} Player;
