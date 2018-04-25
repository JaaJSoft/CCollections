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
 * @Date 07/04/2018
 */

#ifndef CCOLLECTIONS_LINKEDLIST_H
#define CCOLLECTIONS_LINKEDLIST_H

#include <util.h>

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
