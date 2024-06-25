#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

typedef struct {
  float height;
  float opening_x;     // center of opening
  float opening_width; // width of opening
} Block;

Block create_block(float height, float opening_x, float openining_width);

#endif // !BLOCK_H_INCLUDED
