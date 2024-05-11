#ifndef RING_BUFFER_H
#define RING_BUFFER_H

struct RingBuffer {
  int len;
  int size;
  int start;
  int *arr;
};

struct RingBuffer *ring_buffer_create(int size);
void ring_buffer_free(struct RingBuffer *buff);
void ring_buffer_add_first(struct RingBuffer *buff, int value);
void ring_buffer_add_last(struct RingBuffer *buff, int value);
int ring_buffer_remove_first(struct RingBuffer *buff);
int ring_buffer_remove_last(struct RingBuffer *buff);
int ring_buffer_get(struct RingBuffer *buff, int idx);

#endif
