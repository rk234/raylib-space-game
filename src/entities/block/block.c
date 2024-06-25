#include "block.h"

Block create_block(float height, float opening_x, float openining_width) {
  Block b = {.height = height,
             .opening_x = opening_x,
             .opening_width = openining_width};

  return b;
}
