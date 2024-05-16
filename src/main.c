#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (750)

#define WINDOW_TITLE "Learning some C"

typedef struct {
  Vector2 position;
  float rotation;
  Texture2D *texture;
  Color color;
} Ship;

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

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  Texture2D ship_texture = LoadTexture(
      ASSETS_PATH "ship_G.png"); // Check README.md for how this works

  Ship ship = {
      .rotation = 0,
      .position = {.x = (float)SCREEN_WIDTH / 2, .y = SCREEN_HEIGHT - 50},
      .texture = &ship_texture,
      .color = BLUE};

  char *debug_text = (char *)malloc(10 * sizeof(char));

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(GetColor(0x111111));

    Vector2 dist = Vector2Subtract(GetMousePosition(), ship.position);
    dist.y = -200;

    ship.rotation = ((-180 / PI) * atan2(dist.y, -dist.x)) + 270;
    ship.position.x += (GetMouseX() - ship.position.x) * 0.1;

    draw_ship(&ship);

    DrawLineV(ship.position, GetMousePosition(), RED);
    DrawLineV(ship.position, (struct Vector2){GetMouseX(), ship.position.y},
              RED);
    DrawLineV((struct Vector2){GetMouseX(), ship.position.y},
              (struct Vector2){GetMouseX(), GetMouseY()}, RED);

    snprintf(debug_text, 10 * sizeof(char), "%d FPS", GetFPS());

    DrawText(debug_text, 10, 10, 32, PINK);
    EndDrawing();
  }
  free(debug_text);

  CloseWindow();

  return 0;
}
