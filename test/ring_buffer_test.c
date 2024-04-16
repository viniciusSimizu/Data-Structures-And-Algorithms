#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#include "ring_buffer.h"

void ring_buffer_create_tests();
void ring_buffer_add_first_tests();
void ring_buffer_add_last_tests();
void ring_buffer_remove_first_tests();
void ring_buffer_remove_last_tests();
void ring_buffer_get_tests();

int main() {
  ring_buffer_create_tests();
  ring_buffer_add_first_tests();
  ring_buffer_add_last_tests();
  ring_buffer_remove_first_tests();
  ring_buffer_remove_last_tests();
  ring_buffer_get_tests();

  return 0;
}

void ring_buffer_create_tests() {
  struct RingBuffer *buff = ring_buffer_create(3);

  assert(buff != NULL);
  assert(buff->start == 0);
  assert(buff->len == 0);
  assert(buff->size == 3);
  assert(buff->arr != NULL);
  assert(sizeof(buff->arr) * buff->size == sizeof(int) * 3);

  ring_buffer_free(buff);

  buff = ring_buffer_create(0);
  assert(buff != NULL);
  assert(buff->size == 0);
  assert(buff->arr != NULL);
  assert(sizeof(buff->arr) * buff->size == 0);

  ring_buffer_free(buff);

  buff = ring_buffer_create(-1);
  assert(buff == NULL);
}

void ring_buffer_add_first_tests() {
  struct RingBuffer *buff = ring_buffer_create(2);

  ring_buffer_add_first(buff, 1);
  int v = ring_buffer_get(buff, 0);
  assert(v == 1);
  assert(buff->len == 1);

  ring_buffer_add_first(buff, 2);
  v = ring_buffer_get(buff, 0);
  assert(v == 2);
  assert(buff->len == 2);

  ring_buffer_add_first(buff, 3);
  v = ring_buffer_get(buff, 0);
  assert(v == 2);
  assert(buff->len == 2);

  ring_buffer_free(buff);
}

void ring_buffer_add_last_tests() {
  struct RingBuffer *buff = ring_buffer_create(2);

  ring_buffer_add_last(buff, 1);
  int v = ring_buffer_get(buff, 0);
  assert(v == 1);
  assert(buff->len == 1);

  ring_buffer_add_last(buff, 2);
  v = ring_buffer_get(buff, 1);
  assert(v == 2);
  assert(buff->len == 2);

  ring_buffer_add_last(buff, 3);
  v = ring_buffer_get(buff, 1);
  assert(v == 2);
  assert(buff->len == 2);

  ring_buffer_free(buff);
}

void ring_buffer_remove_first_tests() {
  struct RingBuffer *buff = ring_buffer_create(3);
  ring_buffer_add_last(buff, 1);
  ring_buffer_add_last(buff, 2);
  ring_buffer_add_last(buff, 3);

  int v = ring_buffer_remove_first(buff);
  assert(v == 1);
  assert(buff->len == 2);

  v = ring_buffer_remove_first(buff);
  assert(v == 2);
  assert(buff->len == 1);

  v = ring_buffer_remove_first(buff);
  assert(v == 3);
  assert(buff->len == 0);

  v = ring_buffer_remove_first(buff);
  assert(v == INT_MIN);
  assert(buff->len == 0);

  ring_buffer_free(buff);
}

void ring_buffer_remove_last_tests() {
  struct RingBuffer *buff = ring_buffer_create(3);
  ring_buffer_add_first(buff, 1);
  ring_buffer_add_first(buff, 2);
  ring_buffer_add_first(buff, 3);

  int v = ring_buffer_remove_last(buff);
  assert(v == 1);
  assert(buff->len == 2);

  v = ring_buffer_remove_last(buff);
  assert(v == 2);
  assert(buff->len == 1);

  v = ring_buffer_remove_last(buff);
  assert(v == 3);
  assert(buff->len == 0);

  v = ring_buffer_remove_last(buff);
  assert(v == INT_MIN);
  assert(buff->len == 0);

  ring_buffer_free(buff);
}

void ring_buffer_get_tests() {
  struct RingBuffer *buff = ring_buffer_create(5);

  ring_buffer_add_last(buff, 3);
  ring_buffer_add_first(buff, 2);
  ring_buffer_add_last(buff, 4);
  ring_buffer_add_first(buff, 1);

  int v = ring_buffer_get(buff, 0);
  assert(v == 1);
  v = ring_buffer_get(buff, 1);
  assert(v == 2);
  v = ring_buffer_get(buff, 2);
  assert(v == 3);
  v = ring_buffer_get(buff, 3);
  assert(v == 4);
  v = ring_buffer_get(buff, 4);
  assert(v == INT_MIN);

  ring_buffer_remove_last(buff);

  v = ring_buffer_get(buff, 0);
  assert(v == 1);
  v = ring_buffer_get(buff, 1);
  assert(v == 2);
  v = ring_buffer_get(buff, 2);
  assert(v == 3);
  v = ring_buffer_get(buff, 3);
  assert(v == INT_MIN);

  ring_buffer_remove_first(buff);

  v = ring_buffer_get(buff, 0);
  assert(v == 2);
  v = ring_buffer_get(buff, 1);
  assert(v == 3);
  v = ring_buffer_get(buff, 2);
  assert(v == INT_MIN);

  v = ring_buffer_get(buff, -1);
  assert(v == INT_MIN);

  ring_buffer_free(buff);
}
