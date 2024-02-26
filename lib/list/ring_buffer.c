#include <limits.h>
#include <stdlib.h>

#include "ring_buffer.h"

int ring_buffer_end_idx(struct RingBuffer *buff);
int ring_buffer_prev_idx(struct RingBuffer *buff, unsigned int idx);
int ring_buffer_next_idx(struct RingBuffer *buff, unsigned int idx);

struct RingBuffer *ring_buffer_create(unsigned int size) {
  if (size < 0) {
    return NULL;
  }

  struct RingBuffer *buff = malloc(sizeof(struct RingBuffer));
  int *arr = malloc(sizeof(int) * size);

  if (buff == NULL || arr == NULL) {
    free(buff);
    free(arr);
    return NULL;
  }

  buff->arr = arr;
  buff->len = 0;
  buff->size = size;
  buff->start = 0;

  return buff;
}

void ring_buffer_free(struct RingBuffer *buff) {
  free(buff->arr);
  free(buff);
}

void ring_buffer_add_first(struct RingBuffer *buff, int value) {
  if (buff->len == buff->size) {
    return;
  }

  int prev = ring_buffer_prev_idx(buff, buff->start);

  buff->arr[prev] = value;
  buff->start = prev;
  ++buff->len;
}

void ring_buffer_add_last(struct RingBuffer *buff, int value) {
  if (buff->len == buff->size) {
    return;
  }

  int end = ring_buffer_end_idx(buff);
  int next = ring_buffer_next_idx(buff, end);

  buff->arr[next] = value;
  ++buff->len;
}

int ring_buffer_remove_first(struct RingBuffer *buff) {
  if (buff->len == 0) {
    return INT_MIN;
  }
  int v = buff->arr[buff->start];

  buff->start = ring_buffer_next_idx(buff, buff->start);
  --buff->len;

  return v;
}

int ring_buffer_remove_last(struct RingBuffer *buff) {
  if (buff->len == 0) {
    return INT_MIN;
  }

  int end = ring_buffer_end_idx(buff);
  --buff->len;

  return buff->arr[end];
}

int ring_buffer_get(struct RingBuffer *buff, int idx) {
  if (idx < 0 || idx >= buff->len) {
    return INT_MIN;
  }

  int buffIdx = (buff->start + idx) % buff->size;

  return buff->arr[buffIdx];
}

int ring_buffer_end_idx(struct RingBuffer *buff) {
  return (buff->start + buff->len - 1) % buff->size;
}

int ring_buffer_prev_idx(struct RingBuffer *buff, int idx) {
  return buff->size - ((buff->size - idx) % buff->size) - 1;
}

int ring_buffer_next_idx(struct RingBuffer *buff, int idx) {
  return (idx + 1) % buff->size;
}
