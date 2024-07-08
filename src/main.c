#include "data/blockList.h"
#include "entities/block/block.h"
#include "entities/ship/ship.h"
#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (750)

#define WINDOW_TITLE "Learning some C"

void draw_blocks(BlockList *list) {
  for (int i = 0; i < list->size; i++) {
    Block *block = block_list_get(list, i);
    draw_block(block);
  }
}

void update_blocks(BlockList *list, float speed, float elapsedTime) {
  for (int i = 0; i < list->size; i++) {
    Block *block = block_list_get(list, i);
    block->height += GetFrameTime() * speed;

    if (block->height > SCREEN_HEIGHT) {
      block_list_set(list, create_random_block(-100), i);
    }
  }
}

int check_collisions(Ship *ship, BlockList *list) {
  BoundingBox bboxes[2];
  for (int i = 0; i < list->size; i++) {
    get_bounding_boxes(block_list_get(list, i), &bboxes[0]);

    BoundingBox left = bboxes[0];
    BoundingBox right = bboxes[1];

    DrawBoundingBox(left, BLUE);
    DrawBoundingBox(right, BLUE);

    if (CheckCollisionBoxes(ship->bbox, left) ||
        CheckCollisionBoxes(ship->bbox, right)) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  srand(time(NULL));
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  Texture2D ship_texture = LoadTexture(
      ASSETS_PATH "ship_G.png"); // Check README.md for how this works

  Vector2 initialShipPos = {.x = (float)SCREEN_WIDTH / 2,
                            .y = SCREEN_HEIGHT - 50};
  Ship ship = create_ship(initialShipPos, &ship_texture, BLUE);

  char *debug_text = (char *)malloc(10 * sizeof(char));

  BlockList *list = create_block_list(2);
  block_list_add(list, create_random_block(800.0));
  block_list_add(list, create_random_block(400.0));
  block_list_add(list, create_random_block(200.0));

  float speed = 100;
  float elapsedTime = 0;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(GetColor(0x111111));

    Vector2 dist = Vector2Subtract(GetMousePosition(), ship.position);
    dist.y = -200;

    ship.rotation = ((-180 / PI) * atan2(dist.y, -dist.x)) + 270;
    ship.position.x += (GetMouseX() - ship.position.x) * 0.1;

    update_blocks(list, speed, elapsedTime);

    update_ship(&ship);
    draw_ship(&ship);
    if (check_collisions(&ship, list)) {
      DrawBoundingBox(ship.bbox, RED);
    } else {
      DrawBoundingBox(ship.bbox, GREEN);
    }
    draw_blocks(list);

    // DrawLineV(ship.position, GetMousePosition(), RED);
    // DrawLineV(ship.position, (struct Vector2){GetMouseX(),
    // ship.position.y},
    //           RED);
    // DrawLineV((struct Vector2){GetMouseX(), ship.position.y},
    //           (struct Vector2){GetMouseX(), GetMouseY()}, RED);

    snprintf(debug_text, 10 * sizeof(char), "%d FPS", GetFPS());

    DrawText(debug_text, 10, 10, 32, PINK);
    EndDrawing();

    elapsedTime += GetFrameTime();
  }
  free(debug_text);

  CloseWindow();

  return 0;
}
