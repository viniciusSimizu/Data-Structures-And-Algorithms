#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DoublyNode {
  int value;
  struct DoublyNode *next;
  struct DoublyNode *prev;
};

struct DoublyLinkedList {
  int len;
  struct DoublyNode *head;
  struct DoublyNode *tail;
};

struct DoublyLinkedList *doubly_linked_list_create();
void doubly_linked_list_free(struct DoublyLinkedList *list);
void doubly_linked_list_add_first(struct DoublyLinkedList *list, int value);
void doubly_linked_list_add_last(struct DoublyLinkedList *list, int value);
void doubly_linked_list_add_at(struct DoublyLinkedList *list, int value,
                               int idx);
int doubly_linked_list_get(struct DoublyLinkedList *list, int idx);
int doubly_linked_list_remove(struct DoublyLinkedList *list, int idx);
int doubly_linked_list_remove_last(struct DoublyLinkedList *list);

#endif
