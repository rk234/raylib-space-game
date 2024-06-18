#ifndef SHIP_H_INLCUDED
#define SHIP_H_INLCUDED

#include "raylib.h"

typedef struct {
  Vector2 position;
  float rotation;
  Texture2D *texture;
  Color color;
} Ship;

void draw_ship(Ship *ship);

#endif // !SHIP_H_kj
