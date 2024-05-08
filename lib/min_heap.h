#ifndef MIN_HEAD_H
#define MIN_HEAD_H

struct min_heap {
  unsigned int size;
  unsigned int len;
  int *arr;
};

struct min_heap *min_heap_build(unsigned int len, unsigned int size, int *arr);
void min_heap_free(struct min_heap *heap);
void min_heap_push(struct min_heap *heap, int value);
int min_heap_pop(struct min_heap *heap);

#endif
