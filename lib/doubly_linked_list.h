#pragma once

struct DoublyNode {
  int value;
  struct DoublyNode *next;
  struct DoublyNode *prev;
};

struct DoublyLinkedList {
  unsigned int len;
  struct DoublyNode *head;
  struct DoublyNode *tail;
};

struct DoublyLinkedList *doubly_linked_list_create();
void doubly_linked_list_free(struct DoublyLinkedList *list);
void doubly_linked_list_add_first(struct DoublyLinkedList *list, int value);
void doubly_linked_list_add_last(struct DoublyLinkedList *list, int value);
void doubly_linked_list_add_at(struct DoublyLinkedList *list, int value,
                               unsigned int idx);
int doubly_linked_list_get(struct DoublyLinkedList *list, unsigned int idx);
int doubly_linked_list_remove(struct DoublyLinkedList *list, unsigned int idx);
int doubly_linked_list_remove_last(struct DoublyLinkedList *list);
