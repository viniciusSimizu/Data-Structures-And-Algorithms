#include "linked_list/doubly_linked_list.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void createDoublyLinkedListTest();

void addFirstTests();
void addLastTests();
void addAtTests();

void removeTests();
void removeLastTests();

void getTests();

int main() {
  createDoublyLinkedListTest();
  addFirstTests();
  addLastTests();
  addAtTests();
  removeTests();
  removeLastTests();
  getTests();
}

void createDoublyLinkedListTest() {
  struct DoublyLinkedList list = createDoublyLinkedList();
  assert(list.len == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  freeNodesDoublyLinkedList(&list);
}

void addFirstTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addFirstDoublyLinkedList(&list, 1);
  assert(list.len == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);

  addFirstDoublyLinkedList(&list, 2);
  assert(list.len == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);

  freeNodesDoublyLinkedList(&list);
}

void addLastTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addLastDoublyLinkedList(&list, 1);
  assert(list.len == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);

  addLastDoublyLinkedList(&list, 2);
  assert(list.len == 2);
  assert(list.head->value == 1);
  assert(list.tail->value == 2);

  freeNodesDoublyLinkedList(&list);
}

void addAtTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addAtDoublyLinkedList(&list, 1, 0);
  assert(list.len == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);

  addAtDoublyLinkedList(&list, 2, 0);
  assert(list.len == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);

  addAtDoublyLinkedList(&list, 3, list.len);
  assert(list.len == 3);
  assert(list.head->value == 2);
  assert(list.tail->value == 3);

  addAtDoublyLinkedList(&list, 4, list.len - 1);
  assert(list.len == 4);
  assert(list.head->value == 2);
  assert(list.tail->value == 3);
  assert(list.tail->prev->value == 4);

  addAtDoublyLinkedList(&list, 4, list.len + 1);
  assert(list.len == 4);

  freeNodesDoublyLinkedList(&list);
}

void removeTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addLastDoublyLinkedList(&list, 1);
  addLastDoublyLinkedList(&list, 2);
  addLastDoublyLinkedList(&list, 3);
  addLastDoublyLinkedList(&list, 4);

  int v = removeDoublyLinkedList(&list, 2);
  assert(list.len == 3);
  assert(v == 3);
  assert(list.head->next->next->value == 4);
  assert(list.tail->prev->value == 2);

  v = removeDoublyLinkedList(&list, 0);
  assert(list.len == 2);
  assert(v == 1);
  assert(list.head->value == 2);

  v = removeDoublyLinkedList(&list, list.len - 1);
  assert(list.len == 1);
  assert(v == 4);
  assert(list.head->value == list.tail->value);

  v = removeDoublyLinkedList(&list, list.len + 1);
  assert(list.len == 1);
  assert(v == INT_MIN);

  v = removeDoublyLinkedList(&list, 0);
  assert(list.len == 0);
  assert(v == 2);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  freeNodesDoublyLinkedList(&list);
}

void removeLastTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addLastDoublyLinkedList(&list, 1);
  addLastDoublyLinkedList(&list, 2);
  addLastDoublyLinkedList(&list, 3);

  int v = removeLastDoublyLinkedList(&list);
  assert(list.len == 2);
  assert(v == 3);
  assert(list.tail->value == 2);

  v = removeLastDoublyLinkedList(&list);
  assert(list.len == 1);
  assert(v == 2);
  assert(list.tail->value == 1);
  assert(list.head->value == list.tail->value);

  v = removeLastDoublyLinkedList(&list);
  assert(list.len == 0);
  assert(v == 1);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  v = removeLastDoublyLinkedList(&list);
  assert(list.len == 0);
  assert(v == INT_MIN);

  freeNodesDoublyLinkedList(&list);
}

void getTests() {
  struct DoublyLinkedList list = createDoublyLinkedList();

  addLastDoublyLinkedList(&list, 1);
  addLastDoublyLinkedList(&list, 2);
  addLastDoublyLinkedList(&list, 3);

  int v = getDoublyLinkedList(&list, 0);
  assert(v == 1);

  v = getDoublyLinkedList(&list, 2);
  assert(v == 3);

  v = getDoublyLinkedList(&list, 1);
  assert(v == 2);

  v = getDoublyLinkedList(&list, -1);
  assert(v == INT_MIN);

  freeNodesDoublyLinkedList(&list);
}
