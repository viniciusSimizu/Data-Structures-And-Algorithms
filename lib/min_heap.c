#include "min_heap.h"
#include <limits.h>
#include <stdlib.h>

void min_heap_heapify(struct min_heap *heap, int idx);
void min_heap_bottom_up(struct min_heap *heap, int idx);
void min_heap_swap(struct min_heap *heap, int i, int j);
int min_heap_parent(int idx);
int min_heap_left(int idx);
int min_heap_right(int idx);

struct min_heap *min_heap_build(unsigned int len, unsigned int size, int *arr) {
	if (len > size) {
		return NULL;
	};

  struct min_heap *heap = malloc(sizeof(struct min_heap));
  if (heap == NULL) {
    return NULL;
  }

  int *arr_cpy = malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		arr_cpy[i] = arr[i];
	};

  heap->size = size;
	heap->len = len;
  heap->arr = arr_cpy;

	for (int i = (len / 2) - 1; i != 0; --i) {
		min_heap_heapify(heap, i);
	};

  return heap;
}

void min_heap_push(struct min_heap *heap, int value) {
  if (heap->len == heap->size) {
    return;
  }

  int idx = heap->len;
  heap->arr[idx] = value;
  ++heap->len;

	min_heap_bottom_up(heap, idx);
}

int min_heap_pop(struct min_heap *heap) {
  if (heap->len == 0) {
    return INT_MIN;
  }

  int head = heap->arr[0];
  heap->arr[0] = heap->arr[heap->len - 1];
  --heap->len;

	min_heap_heapify(heap, 0);
  return head;
}

void min_heap_heapify(struct min_heap *heap, int idx) {
	int left = min_heap_left(idx);
	int right = min_heap_right(idx);

  while (left < heap->len) {
    if (heap->arr[idx] > heap->arr[left]) {
      min_heap_swap(heap, idx, left);
      idx = left;

    } else if (right < heap->len && heap->arr[idx] > heap->arr[right]) {
      min_heap_swap(heap, idx, right);
      idx = right;

    } else {
      break;
    }

    left = min_heap_left(idx);
    right = min_heap_right(idx);
  }
};

void min_heap_bottom_up(struct min_heap *heap, int idx) {
	int parent = min_heap_parent(idx);

	while(heap->arr[parent] > heap->arr[idx]) {
		min_heap_swap(heap, idx, parent);
		idx = parent;
		parent = min_heap_parent(idx);
	};
};

void min_heap_swap(struct min_heap *heap, int i, int j) {
  int tmp = heap->arr[i];
  heap->arr[i] = heap->arr[j];
  heap->arr[j] = tmp;
}

void min_heap_free(struct min_heap *heap) {
  free(heap->arr);
  free(heap);
}
int min_heap_parent(int idx) { return (idx - 1) / 2; }
int min_heap_left(int idx) { return idx * 2 + 1; }
int min_heap_right(int idx) { return idx * 2 + 2; }
