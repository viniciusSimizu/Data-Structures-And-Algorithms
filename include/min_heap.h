#ifndef MIN_HEAP_H
#define MIN_HEAP_H

struct MinHeap {
  unsigned int size;
  unsigned int len;
  int *arr;
};

struct MinHeap *min_heap_create(unsigned int size);
void *min_heap_free(struct MinHeap *heap);
void min_heap_add(struct MinHeap *heap, int value);
int min_heap_remove(struct MinHeap *heap);

#endif
