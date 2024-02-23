#include "linked_list/doubly_linked_list.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct DoublyLinkedList list = createDoublyLinkedList();
  assert(list.len == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  queueDoublyLinkedList(&list, 1);
  assert(list.len == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->prev == NULL);
  assert(list.head->next == NULL);
  assert(list.tail->prev == NULL);
  assert(list.tail->next == NULL);

  queueDoublyLinkedList(&list, 2);
  assert(list.len == 2);
  assert(list.head->value == 1);
  assert(list.tail->value == 2);
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  assert(list.head->next == list.tail);
  assert(list.tail->prev == list.head);

  queueDoublyLinkedList(&list, 3);
  assert(list.len == 3);
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  assert(list.head == list.tail->prev->prev);
  assert(list.head->next == list.tail->prev);
  assert(list.head->next->next == list.tail);

  int curr = unqueueDoublyLinkedList(&list);
  assert(curr == 1);
  assert(list.len == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 3);
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  assert(list.head->next == list.tail);
  assert(list.tail->prev == list.head);

  curr = unqueueDoublyLinkedList(&list);
  assert(curr == 2);
  assert(list.len == 1);
  assert(list.head->value == 3);
  assert(list.tail->value == 3);
  assert(list.head->prev == NULL);
  assert(list.head->next == NULL);
  assert(list.tail->prev == NULL);
  assert(list.tail->next == NULL);

  curr = unqueueDoublyLinkedList(&list);
  assert(curr == 3);
  assert(list.len == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  curr = unqueueDoublyLinkedList(&list);
  assert(curr == INT_MIN);
}
