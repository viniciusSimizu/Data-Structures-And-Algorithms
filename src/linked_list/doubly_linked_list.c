#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list/doubly_linked_list.h"

struct DoublyLinkedList createDoublyLinkedList();

void addFirstDoublyLinkedList(struct DoublyLinkedList *list, int value);
void addLastDoublyLinkedList(struct DoublyLinkedList *list, int value);
void addAtDoublyLinkedList(struct DoublyLinkedList *list, int value, int idx);

int getDoublyLinkedList(struct DoublyLinkedList *list, int idx);

int removeDoublyLinkedList(struct DoublyLinkedList *list, int idx);
int removeLastDoublyLinkedList(struct DoublyLinkedList *list);
int removeAtDoublyLinkedList(struct DoublyLinkedList *list, int idx);

struct DoublyNode *findNodeDoublyLinkedList(struct DoublyLinkedList *list,
                                            int idx);
struct DoublyNode *createNodeDoublyLinkedList(struct DoublyLinkedList *list,
                                              int value);

struct DoublyLinkedList createDoublyLinkedList() {
  struct DoublyLinkedList list = {0, NULL, NULL};
  return list;
}

void freeNodesDoublyLinkedList(struct DoublyLinkedList *list) {
  struct DoublyNode *curr = list->head;

  while (curr != NULL) {
    struct DoublyNode *next = curr->next;
    free(curr);
    curr = next;
  };
}

void addFirstDoublyLinkedList(struct DoublyLinkedList *list, int value) {
  struct DoublyNode *node = createNodeDoublyLinkedList(list, value);
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

void addLastDoublyLinkedList(struct DoublyLinkedList *list, int value) {
  struct DoublyNode *node = createNodeDoublyLinkedList(list, value);
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

void addAtDoublyLinkedList(struct DoublyLinkedList *list, int value, int idx) {
  if (idx == 0) {
    addFirstDoublyLinkedList(list, value);
    return;
  }

  if (idx == list->len) {
    addLastDoublyLinkedList(list, value);
    return;
  }

  struct DoublyNode *curr = findNodeDoublyLinkedList(list, idx);
  if (curr == NULL) {
    return;
  }

  struct DoublyNode *node = createNodeDoublyLinkedList(list, value);
  if (node == NULL) {
    return;
  }

  node->prev = curr->prev;
  node->next = curr;
  curr->prev->next = node;
  curr->prev = node;

  ++list->len;
}

int getDoublyLinkedList(struct DoublyLinkedList *list, int idx) {
  struct DoublyNode *curr = findNodeDoublyLinkedList(list, idx);
  if (curr == NULL) {
    return INT_MIN;
  }

  return curr->value;
}

int removeDoublyLinkedList(struct DoublyLinkedList *list, int idx) {
  struct DoublyNode *curr = findNodeDoublyLinkedList(list, idx);
  if (curr == NULL) {
    return INT_MIN;
  }

  if (list->len == 1) {
    list->head = list->tail = NULL;

  } else if (curr->prev == NULL) {
    list->head = curr->next;
    list->head->prev = NULL;

  } else if (curr->next == NULL) {
    return removeLastDoublyLinkedList(list);

  } else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  int value = curr->value;
  free(curr);
  --list->len;

  return value;
}

int removeLastDoublyLinkedList(struct DoublyLinkedList *list) {
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

struct DoublyNode *findNodeDoublyLinkedList(struct DoublyLinkedList *list,
                                            int idx) {
  if (idx < 0 || idx >= list->len) {
    return NULL;
  }

  struct DoublyNode *curr = list->head;

  for (int i = 0; i < idx; ++i) {
    curr = curr->next;
  }

  return curr;
}

struct DoublyNode *createNodeDoublyLinkedList(struct DoublyLinkedList *list,
                                              int value) {
  struct DoublyNode *node = malloc(sizeof(struct DoublyNode));
  if (node == NULL) {
    return NULL;
  }

  node->value = value;
	node->next = node->prev = NULL;
  return node;
}
