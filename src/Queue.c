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

#include "Queue.h"

#define _first this->first
#define _last this->last

typedef struct cell_t *Cell;

struct queue_t {
    struct cell_t *first;
    struct cell_t *last;
};

struct cell_t {
    struct cell_t *after;
    T value;
};

Cell newCellQueue(T value);

Queue newQueue() {
    Queue queue;
    queue = malloc(sizeof(struct queue_t));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

T QueuePop(Queue this) {
    T value;
    Cell tmp;

    if (_first) {
        value = _first->value;
        tmp = _first;
        _first = _first->after;
        free(tmp);
        return value;
    }

    return NULL;
}

void QueueAdd(Queue this, T value) {
    if (!_last) {
        _last = newCellQueue(value);
        _first = _last;
    } else {
        _last->after = newCellQueue(value);
        _last = _last->after;
    }
}

void QueueDelete(Queue this) {
    Cell current, tmp;

    current = _first;

    while(current) {
        tmp = current;
        current = current->after;
        free(tmp);
    }
    free(this);
}

int QueueIsEmpty(Queue this) {
    return _first == NULL;
}

Cell newCellQueue(T value) {
    Cell cell;
    cell = malloc(sizeof(struct cell_t));
    cell->value = value;
    cell->after = NULL;
    return  cell;
}
