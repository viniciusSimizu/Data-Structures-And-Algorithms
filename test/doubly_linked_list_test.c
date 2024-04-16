#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

void doubly_linked_list_create_tests();
void doubly_linked_list_add_first_tests();
void doubly_linked_list_add_last_tests();
void doubly_linked_list_add_at_tests();
void doubly_linked_list_remove_tests();
void doubly_linked_list_remove_last_tests();
void doubly_linked_list_get_tests();

int main() {
  doubly_linked_list_create_tests();
  doubly_linked_list_add_first_tests();
  doubly_linked_list_add_last_tests();
  doubly_linked_list_add_at_tests();
  doubly_linked_list_remove_tests();
  doubly_linked_list_remove_last_tests();
  doubly_linked_list_get_tests();

  return 0;
}

void doubly_linked_list_create_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();
  assert(list->len == 0);
  assert(list->head == NULL);
  assert(list->tail == NULL);

  doubly_linked_list_free(list);
}

void doubly_linked_list_add_first_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_first(list, 1);
  assert(list->len == 1);
  assert(list->head->value == 1);
  assert(list->tail->value == 1);

  doubly_linked_list_add_first(list, 2);
  assert(list->len == 2);
  assert(list->head->value == 2);
  assert(list->tail->value == 1);

  doubly_linked_list_free(list);
}

void doubly_linked_list_add_last_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_last(list, 1);
  assert(list->len == 1);
  assert(list->head->value == 1);
  assert(list->tail->value == 1);

  doubly_linked_list_add_last(list, 2);
  assert(list->len == 2);
  assert(list->head->value == 1);
  assert(list->tail->value == 2);

  doubly_linked_list_free(list);
}

void doubly_linked_list_add_at_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_at(list, 1, 0);
  assert(list->len == 1);
  assert(list->head->value == 1);
  assert(list->tail->value == 1);

  doubly_linked_list_add_at(list, 2, 0);
  assert(list->len == 2);
  assert(list->head->value == 2);
  assert(list->tail->value == 1);

  doubly_linked_list_add_at(list, 3, list->len);
  assert(list->len == 3);
  assert(list->head->value == 2);
  assert(list->tail->value == 3);

  doubly_linked_list_add_at(list, 4, list->len - 1);
  assert(list->len == 4);
  assert(list->head->value == 2);
  assert(list->tail->value == 3);
  assert(list->tail->prev->value == 4);

  doubly_linked_list_add_at(list, 4, list->len + 1);
  assert(list->len == 4);

  doubly_linked_list_free(list);
}

void doubly_linked_list_remove_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_last(list, 1);
  doubly_linked_list_add_last(list, 2);
  doubly_linked_list_add_last(list, 3);
  doubly_linked_list_add_last(list, 4);

  int v = doubly_linked_list_remove(list, 2);
  assert(list->len == 3);
  assert(v == 3);
  assert(list->head->next->next->value == 4);
  assert(list->tail->prev->value == 2);

  v = doubly_linked_list_remove(list, 0);
  assert(list->len == 2);
  assert(v == 1);
  assert(list->head->value == 2);

  v = doubly_linked_list_remove(list, list->len - 1);
  assert(list->len == 1);
  assert(v == 4);
  assert(list->head->value == list->tail->value);

  v = doubly_linked_list_remove(list, list->len + 1);
  assert(list->len == 1);
  assert(v == INT_MIN);

  v = doubly_linked_list_remove(list, 0);
  assert(list->len == 0);
  assert(v == 2);
  assert(list->head == NULL);
  assert(list->tail == NULL);

  doubly_linked_list_free(list);
}

void doubly_linked_list_remove_last_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_last(list, 1);
  doubly_linked_list_add_last(list, 2);
  doubly_linked_list_add_last(list, 3);

  int v = doubly_linked_list_remove_last(list);
  assert(list->len == 2);
  assert(v == 3);
  assert(list->tail->value == 2);

  v = doubly_linked_list_remove_last(list);
  assert(list->len == 1);
  assert(v == 2);
  assert(list->tail->value == 1);
  assert(list->head->value == list->tail->value);

  v = doubly_linked_list_remove_last(list);
  assert(list->len == 0);
  assert(v == 1);
  assert(list->head == NULL);
  assert(list->tail == NULL);

  v = doubly_linked_list_remove_last(list);
  assert(list->len == 0);
  assert(v == INT_MIN);

  doubly_linked_list_free(list);
}

void doubly_linked_list_get_tests() {
  struct DoublyLinkedList *list = doubly_linked_list_create();

  doubly_linked_list_add_last(list, 1);
  doubly_linked_list_add_last(list, 2);
  doubly_linked_list_add_last(list, 3);

  int v = doubly_linked_list_get(list, 0);
  assert(v == 1);

  v = doubly_linked_list_get(list, 2);
  assert(v == 3);

  v = doubly_linked_list_get(list, 1);
  assert(v == 2);

  v = doubly_linked_list_get(list, -1);
  assert(v == INT_MIN);

  doubly_linked_list_free(list);
}
