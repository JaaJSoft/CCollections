/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

/**
 * @author Pierre Chopinet
 * @author Rémi Lecouillard
 * @Date 06/04/2018
 */

#ifndef CCOLLECTIONS_ARRAYLIST_H
#define CCOLLECTIONS_ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <util.h>

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

T *ArrayListToArray(ArrayList this);

#endif
