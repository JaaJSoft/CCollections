//
// Created by Pierre on 07/04/2018.
//

#include <include/LinkedList.h>


struct linkedlist_t {
    int length;
    struct linkedlist_node *begin;
    struct linkedlist_node *end;
};

struct linkedlist_node {
    T value;
    struct linkedlist_node *next;
};

LinkedList newLinkedList() {
    return NULL;
}


