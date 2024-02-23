#include <limits.h>
#include <stdlib.h>

#include "linked_list/doubly_linked_list.h"

struct DoublyLinkedList createDoublyLinkedList();
void queueDoublyLinkedList(struct DoublyLinkedList *list, int value);
int unqueueDoublyLinkedList(struct DoublyLinkedList *list);

struct DoublyLinkedList createDoublyLinkedList() {
  struct DoublyLinkedList list = {0, NULL, NULL};
  return list;
}

void queueDoublyLinkedList(struct DoublyLinkedList *list, int value) {
  struct DoublyNode *node = malloc(sizeof(struct DoublyNode));
  if (node == NULL) {
    return;
  }

  node->value = value;

  if (list->len == 0) {
    list->head = node;

  } else {
    node->prev = list->tail;
    list->tail->next = node;
  }

  list->tail = node;
  ++list->len;
};

int unqueueDoublyLinkedList(struct DoublyLinkedList *list) {
  if (list->len == 0) {
    return INT_MIN;
  }

  struct DoublyNode *curr = list->head;
  int value = curr->value;

  if (list->len == 1) {
    list->head = list->tail = NULL;

  } else {
    list->head = curr->next;
    curr->next->prev = NULL;
  }

  free(curr);
  --list->len;

  return value;
};
