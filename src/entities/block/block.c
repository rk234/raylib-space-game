#include "block.h"
#include "raylib.h"
#include <stdlib.h>

const int BLOCK_HEIGHT = 50;

Block create_block(float height, float opening_x, float openining_width) {
  Block b = {.height = height,
             .opening_x = opening_x,
             .opening_width = openining_width};

  return b;
}

Block create_random_block(float height) {
  Block b = {.height = height,
             .opening_x =
                 50 + (GetScreenWidth() - 100) * ((float)rand() / RAND_MAX),
             .opening_width = 75 + 200 * ((float)rand() / RAND_MAX)};

  return b;
}

void draw_block(Block *block) {
  DrawRectangle(0, block->height, block->opening_x - block->opening_width / 2.0,
                BLOCK_HEIGHT, WHITE);
  DrawRectangle(0, block->height + BLOCK_HEIGHT,
                block->opening_x - block->opening_width / 2.0, 10, GRAY);

  DrawRectangle(block->opening_x + block->opening_width / 2.0, block->height,
                GetScreenWidth(), BLOCK_HEIGHT, WHITE);
  DrawRectangle(block->opening_x + block->opening_width / 2.0,
                block->height + BLOCK_HEIGHT, GetScreenWidth(), 10, GRAY);
}
