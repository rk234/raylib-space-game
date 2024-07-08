#include "block.h"
#include "raylib.h"
#include <stdlib.h>

const int BLOCK_TOP_HEIGHT = 50;
const int BLOCK_BOTTOM_HEIGHT = 10;
const int BLOCK_HEIGHT = BLOCK_TOP_HEIGHT + BLOCK_BOTTOM_HEIGHT;

Block create_block(float height, float opening_x, float openining_width) {
  Block b = {.height = height,
             .opening_x = opening_x,
             .opening_width = openining_width};

  return b;
}

Block create_random_block(float height) {
  Block b = {.height = height,
             .opening_x =
                 100 + (GetScreenWidth() - 200) * ((float)rand() / RAND_MAX),
             .opening_width = 75 + 100 * ((float)rand() / RAND_MAX)};

  return b;
}

void draw_block(Block *block) {
  DrawRectangle(0, block->height, block->opening_x - block->opening_width / 2.0,
                BLOCK_TOP_HEIGHT, WHITE);
  DrawRectangle(0, block->height + BLOCK_TOP_HEIGHT,
                block->opening_x - block->opening_width / 2.0,
                BLOCK_BOTTOM_HEIGHT, GRAY);

  DrawRectangle(block->opening_x + block->opening_width / 2.0, block->height,
                GetScreenWidth(), BLOCK_TOP_HEIGHT, WHITE);
  DrawRectangle(block->opening_x + block->opening_width / 2.0,
                block->height + BLOCK_TOP_HEIGHT, GetScreenWidth(),
                BLOCK_BOTTOM_HEIGHT, GRAY);
}

void get_bounding_boxes(Block *block, BoundingBox *bboxes) {
  BoundingBox left = {
      .min = {.x = 0, .y = block->height},
      .max = {.x = block->opening_x - block->opening_width / 2.0,
              .y = block->height + BLOCK_HEIGHT}};
  BoundingBox right = {
      .min = {.x = block->opening_x + block->opening_width / 2.0,
              .y = block->height},
      .max = {.x = GetScreenWidth(), .y = block->height + BLOCK_HEIGHT}};

  bboxes[0] = left;
  bboxes[1] = right;
}
