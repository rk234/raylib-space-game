#include "ship.h"
#include "raylib.h"

BoundingBox create_bbox(Ship *ship) {
  BoundingBox bbox = {
      .min = {.x = ship->position.x - ship->texture->width / 2.5f,
              .y = ship->position.y - ship->texture->height / 2.0},
      .max = {.x = ship->position.x + ship->texture->width / 2.5,
              .y = ship->position.y + ship->texture->height / 2.0}};
  return bbox;
}

void draw_ship(Ship *ship) {
  Rectangle dest = {.x = ship->position.x,
                    .y = ship->position.y,
                    .width = ship->texture->width,
                    .height = ship->texture->height};

  Rectangle src = {.x = 0,
                   .y = 0,
                   .width = ship->texture->width,
                   .height = ship->texture->height};

  Vector2 origin = {.x = dest.width / 2, .y = dest.height / 2};

  DrawTexturePro(*ship->texture, src, dest, origin, ship->rotation,
                 ship->color);
}

void update_ship(Ship *ship) { ship->bbox = create_bbox(ship); }

Ship create_ship(Vector2 position, Texture2D *texture, Color color) {
  Ship ship = {.rotation = 0,
               .position = position,
               .texture = texture,
               .color = color,
               .bbox = create_bbox(&ship)};

  return ship;
}
