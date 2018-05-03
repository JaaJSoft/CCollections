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
 * @Date 03/05/18
 */

#ifndef CCOLLECTIONS_QUEUE_H
#define CCOLLECTIONS_QUEUE_H

#include "util.h"

/**
 *
 */
typedef struct queue_t *Queue;

/**
 *
 * @return
 */
Queue newQueue();

/**
 *
 * @param this
 * @return
 */
T QueuePop(Queue this);

/**
 *
 * @param this
 * @param value
 */
void QueueAdd(Queue this, T value);

/**
 *
 * @param this
 */
void QueueDelete(Queue this);

/**
 *
 * @param this
 * @return
 */
int QueueIsEmpty(Queue this);

#endif //CCOLLECTIONS_QUEUE_H
