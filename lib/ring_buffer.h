#pragma once

struct RingBuffer {
  unsigned int len;
  unsigned int size;
  unsigned int start;
  int *arr;
};

struct RingBuffer *ring_buffer_create(unsigned int size);
void ring_buffer_free(struct RingBuffer *buff);
void ring_buffer_add_first(struct RingBuffer *buff, int value);
void ring_buffer_add_last(struct RingBuffer *buff, int value);
int ring_buffer_remove_first(struct RingBuffer *buff);
int ring_buffer_remove_last(struct RingBuffer *buff);
int ring_buffer_get(struct RingBuffer *buff, unsigned int idx);
