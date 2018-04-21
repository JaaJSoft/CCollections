//
// Created by Pierre on 21/04/2018.
//

#ifndef CCOLLECTIONS_TREESET_H
#define CCOLLECTIONS_TREESET_H

#include "util.h"

typedef struct treeset_t *TreeSet;

TreeSet newTreeSet();

void TreeSetAppend(TreeSet this, T value);

int TreeSetRemoveValue(TreeSet this, T value);

void TreeSetDisplay(TreeSet this);

T* TreeSetToArray(TreeSet this);

void TreeSetDelete(TreeSet this);

#endif //CCOLLECTIONS_TREESET_H
