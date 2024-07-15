#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "raylib.h"

typedef enum screen { MAIN_MENU = 0, GAME = 1, GAME_OVER = 2 } Screen;

typedef struct {
  int score;
  Screen screen;
  Texture2D *shipTexture;
} GameState;

#endif
