#ifndef SHIP_H_INLCUDED
#define SHIP_H_INLCUDED

#include "raylib.h"

typedef struct {
  Vector2 position;
  float rotation;
  Texture2D *texture;
  Color color;
  BoundingBox bbox;
} Ship;

void draw_ship(Ship *ship);
void update_ship(Ship *ship);
Ship create_ship(Vector2 position, Texture2D *texture, Color color);

#endif // !SHIP_H_kj
