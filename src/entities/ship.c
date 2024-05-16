// #include "raylib.h"
//
// typedef struct {
//   Vector2 position;
//   float rotation;
//   Texture2D *texture;
//   Color color;
// } Ship;
//
// void draw_ship(Ship *ship) {
//   Rectangle dest = {.x = ship->position.x,
//                     .y = ship->position.y,
//                     .width = ship->texture->width,
//                     .height = ship->texture->height};
//
//   Rectangle src = {.x = 0,
//                    .y = 0,
//                    .width = ship->texture->width,
//                    .height = ship->texture->height};
//
//   Vector2 origin = {.x = dest.width / 2, .y = dest.height / 2};
//
//   DrawTexturePro(*ship->texture, src, dest, origin, ship->rotation,
//                  ship->color);
// }
