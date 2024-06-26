#include "blockList.h"
#include <stdlib.h>
#include <string.h>

BlockList *create_block_list(size_t capacity) {
  BlockList *list = (BlockList *)malloc(sizeof(BlockList));

  list->capacity = capacity;
  list->size = 0;
  list->blocks = (Block *)malloc(sizeof(Block) * capacity);

  return list;
}

void block_list_add(BlockList *list, Block block) {
  if (list->size < list->capacity) {
    list->blocks[list->size] = block;
    list->size += 1;
  } else {
    block_list_resize(list, list->capacity * 2);
    block_list_add(list, block);
  }
}

Block *block_list_get(BlockList *list, size_t index) {
  return &list->blocks[index];
}

Block *block_list_set(BlockList *list, Block newBlock, size_t index) {
  Block *old = block_list_get(list, index);
  list->blocks[index] = newBlock;
  return old;
}

void block_list_resize(BlockList *list, size_t newCapacity) {
  printf("curr capacity: %zu, new cap: %zu\n", sizeof(Block) * list->capacity,
         sizeof(Block) * newCapacity);
  list->blocks = (Block *)realloc(list->blocks, sizeof(Block) * newCapacity);
  list->capacity = newCapacity;
}

void destroy_block_list(BlockList *list) {
  free(list->blocks);
  free(list);
}
