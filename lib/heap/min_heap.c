#include "min_heap.h"
#include <limits.h>
#include <stdlib.h>

int min_heap_parent(int idx);
int min_heap_left(int idx);
int min_heap_right(int idx);
void min_heap_swap(struct MinHeap *heap, int i, int j);

struct MinHeap *min_heap_create(int size) {
  struct MinHeap *heap = malloc(sizeof(struct MinHeap));
  if (heap == NULL) {
    return NULL;
  }

  int *arr = malloc(sizeof(int) * size);

  heap->size = size;
  heap->arr = arr;
  heap->len = 0;
  return heap;
}

void *min_heap_free(struct MinHeap *heap) {
  free(heap->arr);
  free(heap);
}

void min_heap_add(struct MinHeap *heap, int value) {
  if (heap->len == heap->size) {
    return;
  }

  int curr = heap->len;
  int parent = min_heap_parent(curr);
  heap->arr[curr] = value;
  ++heap->len;

  while (heap->arr[parent] > heap->arr[curr]) {
    min_heap_swap(heap, curr, parent);
    curr = parent;
    parent = min_heap_parent(curr);
  }
}

int min_heap_remove(struct MinHeap *heap) {
  if (heap->len == 0) {
    return INT_MIN;
  }

  int head = heap->arr[0];
  heap->arr[0] = heap->arr[heap->len - 1];
  --heap->len;

  int curr = 0, left = 1, right = 2;
  while (left < heap->len) {
    if (heap->arr[curr] > heap->arr[left]) {
      min_heap_swap(heap, curr, left);
      curr = left;

    } else if (right < heap->len && heap->arr[curr] > heap->arr[right]) {
      min_heap_swap(heap, curr, right);
      curr = right;

    } else {
      break;
    }

    left = min_heap_left(curr);
    right = min_heap_right(curr);
  }

  return head;
}

int min_heap_parent(int idx) { return (idx - 1) / 2; }
int min_heap_left(int idx) { return idx * 2 + 1; }
int min_heap_right(int idx) { return idx * 2 + 2; }

void min_heap_swap(struct MinHeap *heap, int i, int j) {
  int tmp = heap->arr[i];
  heap->arr[i] = heap->arr[j];
  heap->arr[j] = tmp;
}
