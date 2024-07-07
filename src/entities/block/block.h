#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include "raylib.h"

typedef struct {
  float height;
  float opening_x;     // center of opening
  float opening_width; // width of opening
} Block;

Block create_block(float height, float opening_x, float openining_width);
Block create_random_block(float height);
void draw_block(Block *block);
BoundingBox *get_bounding_boxes(
    Block *block); // will always return 2 boxes (for left and right)!

#endif // !BLOCK_H_INCLUDED
