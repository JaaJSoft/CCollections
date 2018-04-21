//
// Created by Pierre on 07/04/2018.
//

#ifndef CCOLLECTIONS_LINKEDLIST_H
#define CCOLLECTIONS_LINKEDLIST_H

#include <include/util.h>

typedef struct linkedlist_t *LinkedList;

LinkedList newLinkedList();

void LinkedListAppend(LinkedList this, T value);

void LinkedListAppendLinkedList(LinkedList this, LinkedList l);

void LinkedListAdd(LinkedList this, T value, int i);

T LinkedListGet(LinkedList this, int i);

T LinkedListNext(LinkedList this);

void LinkedListCurrentToBegin(LinkedList this);

int LinkedListSearch(LinkedList this, T value);

int LinkedListRemoveValue(LinkedList this, T value);

int LinkedListRemove(LinkedList this, int i);

int LinkedListDisplay(LinkedList this);

int LinkedListIsEmpty(LinkedList this);

void LinkedListDelete(LinkedList this);

int LinkedListGetLength(LinkedList this);

#endif //CCOLLECTIONS_LINKEDLIST_H
