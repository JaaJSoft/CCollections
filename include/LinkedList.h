//
// Created by Pierre on 07/04/2018.
//

#ifndef CCOLLECTIONS_LINKEDLIST_H
#define CCOLLECTIONS_LINKEDLIST_H

#include <include/util.h>

typedef struct linkedlist_t *LinkedList;

LinkedList newLinkedList();

void LinkedListAppend(LinkedList this, T value);

int LinkedListSearch(LinkedList this, T value);

int LinkedListRemove(LinkedList this, T value);

int LinkedListDisplay(LinkedList this);



#endif //CCOLLECTIONS_LINKEDLIST_H
