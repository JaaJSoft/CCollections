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
 * @Date 22/04/18
 */

#ifndef CCOLLECTIONS_PRIORITYQUEUE_H
#define CCOLLECTIONS_PRIORITYQUEUE_H

#include <util.h>

/**
 * A priority queue is like a simple queue, but with an additional priority level.
 * The value with the highest priority is served before the others. With the same
 * priority level, it works as a regular queue.
 * The highest priority can be either the min or the max value depending on the
 * implementation.
 * In this implementation, the min value is the highest priority.
 *
 */
typedef struct priorityqueue_t *PriorityQueue;

/**
 * Allocates memory for a priority queue on the heap.
 * It needs to be freed at some point by calling PriorityQueueDelete()
 * @return Pointer on the priority queue
 */
PriorityQueue newPriorityQueue();

/**
 * Pops the highest priority value.
 * @param this
 * @return
 */
T PriorityQueuePop(PriorityQueue this);

/**
 * Adds a value in the priority queue with the given priority.
 * @param this
 * @param value
 * @param priority
 */
void PriorityQueueAdd(PriorityQueue this,T value,int priority);

/**
 * Changes the priority level of a value.
 * @param this
 * @param value
 * @param newPriority
 */
void PriorityQueueChangePrio(PriorityQueue this, T value, int newPriority);

/**
 *
 * @param this
 * @return
 */
int PriorityQueueIsEmpty(PriorityQueue this);

/**
 * Free the memory.
 * @param this
 */
void PriorityQueueDelete(PriorityQueue this);

#endif //CCOLLECTIONS_PRIORITYQUEUE_H
