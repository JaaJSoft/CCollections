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

/**
 * A linked list is a linear collection, in which each element points to the next one.
 * This implementation features an iterator represented by the key word 'current'.
 * Using this iterator is the most efficient way to browse the list in most cases.
 */
typedef struct linkedlist_t *LinkedList;

/**
 * Creates a new LinkedList
 * @return An instance of a new empty LinkedList
 */
LinkedList newLinkedList();

/**
 * Appends the second LinkedList at the end of the first one.
 * @param this
 * @param l the appended LinkedList
 */
void LinkedListAppendLinkedList(LinkedList this, LinkedList l);

/**
 * Adds an element at the end of the list.
 * @param this
 * @param value
 */
void LinkedListAddLast(LinkedList this, T value);

/**
 * Adds an element at the beginning of the list.
 * @param this
 * @param value
 */
void LinkedListAddFirst(LinkedList this, T value);

/**
 * Adds an element at the given index.
 * If such index is greater than the size of the list, adds it at the beginning.
 * @param this
 * @param value
 * @param i
 */
void LinkedListAddAtIndex(LinkedList this, T value, int i);

/**
 * Adds an element after the current element.
 * If current is not set, adds it at the beginning.
 * @param this
 * @param value
 */
void LinkedListAddCurrent(LinkedList this, T value);

/**
 * Removes the given value of the list.
 * @param this
 * @param value
 * @return 0 if such value is not in the list, or has not been found, therefor not removed. 1 if it has been removed.
 */
int LinkedListRemoveValue(LinkedList this, T value);

/**
 * Removes the value at the given index.
 * @param this
 * @param i
 * @return 0 if the index is not correct, greater than the size of the list, or minor to 0. 1 if it has been removed.
 */
int LinkedListRemoveAtIndex(LinkedList this, int i);

/**
 * Removes the current value.
 * The current value is set on the previous one.
 * @param this
 * @return 0 if current is not set, therefor can't be remove. 1 if it has been removed.
 */
int LinkedListRemoveCurrent(LinkedList this);

/**
 *
 * @param this
 * @param i
 * @return the element at the given index, or NULL if the index is incorrect.
 */
T LinkedListGetAtIndex(LinkedList this, int i);

/**
 *
 * @param this
 * @return the last element, or NULL if the list is empty.
 */
T LinkedListGetLast(LinkedList this);

/**
 *
 * @param this
 * @return the first element, or NULL if the list is empty.
 */
T LinkedListGetFirst(LinkedList this);

/**
 *
 * @param this
 * @return the current element, or NULL if current is not set.
 */
T LinkedListGetCurrent(LinkedList this);

/**
 * Moves current to next element in the list.
 * Sets it at the first element if it is not set.
 * @param this
 * @return 1 if it has been moved. 0 if current is at the end of the list, or the list is empty.
 */
int LinkedListMoveCurrentNext(LinkedList this);

/**
 * Resets the current element. That is to say, put current as not set.
 * @param this
 */
void LinkedListResetCurrent(LinkedList this);

/**
 * Seeks for the value in the list.
 * @param this
 * @param value
 * @return 1 if it is in the list. 0 if it is not.
 */
int LinkedListSearch(LinkedList this, T value);

/**
 *
 * @param this
 * @return
 */
int LinkedListDisplay(LinkedList this);

/**
 *
 * @param this
 * @return 0 if not empty, something else if empty.
 */
int LinkedListIsEmpty(LinkedList this);

/**
 * Deletes the LinkedList by freeing the memory.
 * The list can't be use afterward.
 * @param this
 */
void LinkedListDelete(LinkedList this);

/**
 *
 * @param this
 * @return the number of elements in the list.
 */
int LinkedListGetLength(LinkedList this);

#endif //CCOLLECTIONS_LINKEDLIST_H
