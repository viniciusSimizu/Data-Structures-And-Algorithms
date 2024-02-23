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
void freeNodesDoublyLinkedList(struct DoublyLinkedList *list);

void addFirstDoublyLinkedList(struct DoublyLinkedList *list, int value);
void addLastDoublyLinkedList(struct DoublyLinkedList *list, int value);
void addAtDoublyLinkedList(struct DoublyLinkedList *list, int value, int idx);
int getDoublyLinkedList(struct DoublyLinkedList *list, int idx);
int removeDoublyLinkedList(struct DoublyLinkedList *list, int idx);
int removeLastDoublyLinkedList(struct DoublyLinkedList *list);

#endif
