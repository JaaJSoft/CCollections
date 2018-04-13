//
// Created by Pierre on 06/04/2018.
//

#ifndef CCOLLECTIONS_ARRAYLIST_H
#define CCOLLECTIONS_ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <include/util.h>

typedef struct ArrayList_t *ArrayList;

ArrayList newArrayList(int initLength, int increment);

T ArrayListGet(ArrayList this, int i);

void ArrayListSet(ArrayList this, int i, T value);

int ArrayListAppend(ArrayList this, T value);

int ArrayListContains(ArrayList this, T value);

void ArrayListRemoveValue(ArrayList this, int i);

void ArrayListDelete(ArrayList this);

void ArrayListDisplay(ArrayList this);

void ArrayListMatchLength(ArrayList this);

int ArrayListGetLength(ArrayList this);

int ArrayListGetRealLength(ArrayList this);

int ArrayListGetIncrement(ArrayList this);

void ArrayListForEach(ArrayList this, T (*apply)(T value));

int ArrayListIsEmpty(ArrayList this);

T *ArrayListTArrayo(ArrayList this);

#endif
