#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

struct DoublyNode *doubly_linked_list_find_node(struct DoublyLinkedList *list,
                                                int idx);
struct DoublyNode *doubly_linked_list_create_node(struct DoublyLinkedList *list,
                                                  int value);

struct DoublyLinkedList *doubly_linked_list_create() {
  struct DoublyLinkedList *list = malloc(sizeof(struct DoublyLinkedList));
  if (list == NULL) {
    return NULL;
  }

  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void doubly_linked_list_free(struct DoublyLinkedList *list) {
  struct DoublyNode *curr = list->head;
  struct DoublyNode *next;

  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  };

  free(list);
}

void doubly_linked_list_add_first(struct DoublyLinkedList *list, int value) {
  struct DoublyNode *node = doubly_linked_list_create_node(list, value);
  if (node == NULL) {
    return;
  }

  if (list->len == 0) {
    list->tail = node;

  } else {
    node->next = list->head;
    list->head->prev = node;
  }

  list->head = node;
  ++list->len;
}

void doubly_linked_list_add_last(struct DoublyLinkedList *list, int value) {
  struct DoublyNode *node = doubly_linked_list_create_node(list, value);
  if (node == NULL) {
    return;
  }

  if (list->len == 0) {
    list->head = node;

  } else {
    node->prev = list->tail;
    list->tail->next = node;
  }

  list->tail = node;
  ++list->len;
}

void doubly_linked_list_add_at(struct DoublyLinkedList *list, int value,
                               int idx) {
  if (idx == 0) {
    doubly_linked_list_add_first(list, value);
    return;
  }

  if (idx == list->len) {
    doubly_linked_list_add_last(list, value);
    return;
  }

  struct DoublyNode *curr = doubly_linked_list_find_node(list, idx);
  if (curr == NULL) {
    return;
  }

  struct DoublyNode *node = doubly_linked_list_create_node(list, value);
  if (node == NULL) {
    return;
  }

  node->prev = curr->prev;
  node->next = curr;
  curr->prev->next = node;
  curr->prev = node;

  ++list->len;
}

int doubly_linked_list_get(struct DoublyLinkedList *list, int idx) {
  struct DoublyNode *curr = doubly_linked_list_find_node(list, idx);
  if (curr == NULL) {
    return INT_MIN;
  }

  return curr->value;
}

int doubly_linked_list_remove(struct DoublyLinkedList *list, int idx) {
  struct DoublyNode *curr = doubly_linked_list_find_node(list, idx);
  if (curr == NULL) {
    return INT_MIN;
  }

  if (list->len == 1) {
    list->head = list->tail = NULL;

  } else if (curr->prev == NULL) {
    list->head = curr->next;
    list->head->prev = NULL;

  } else if (curr->next == NULL) {
    return doubly_linked_list_remove_last(list);

  } else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  int value = curr->value;
  free(curr);
  --list->len;

  return value;
}

int doubly_linked_list_remove_last(struct DoublyLinkedList *list) {
  if (list->len == 0) {
    return INT_MIN;
  }

  struct DoublyNode *curr = list->tail;

  if (list->len == 1) {
    list->head = list->tail = NULL;

  } else {
    list->tail = list->tail->prev;
    list->tail->next = NULL;
  }

  int value = curr->value;
  free(curr);
  --list->len;

  return value;
}

struct DoublyNode *doubly_linked_list_find_node(struct DoublyLinkedList *list,
                                                int idx) {
  if (idx >= list->len) {
    return NULL;
  }

  struct DoublyNode *curr = list->head;

  for (int i = 0; i < idx; ++i) {
    curr = curr->next;
  }

  return curr;
}

struct DoublyNode *doubly_linked_list_create_node(struct DoublyLinkedList *list,
                                                  int value) {
  struct DoublyNode *node = malloc(sizeof(struct DoublyNode));
  if (node == NULL) {
    return NULL;
  }

  node->value = value;
  node->next = node->prev = NULL;
  return node;
}
