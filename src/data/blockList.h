#ifndef BLOCK_LIST_H
#define BLOCK_LIST_H

#include "../entities/block/block.h"
#include <stdio.h>

typedef struct {
  size_t size;
  size_t capacity;
  Block *blocks;
} BlockList;

BlockList *create_block_list(size_t capacity);
void block_list_add(BlockList *list, Block block);
Block *block_list_get(BlockList *list, size_t index);
void block_list_resize(BlockList *list, size_t newCapacity);
Block *block_list_set(BlockList *list, Block newBlock,
                      size_t index); // sets the elemenet at the index to new
                                     // block, returns pointer to old block
void destroy_block_list(BlockList *list);

#endif
