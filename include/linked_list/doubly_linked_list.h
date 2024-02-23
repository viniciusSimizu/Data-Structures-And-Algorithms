#pragma once

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

struct DoublyLinkedList createDoublyLinkedList();
void queueDoublyLinkedList(struct DoublyLinkedList *list, int value);
int unqueueDoublyLinkedList(struct DoublyLinkedList *list);

#endif
