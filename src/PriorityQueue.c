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
 * @Date 25/04/18
 */

#include "PriorityQueue.h"

#define HEAP_SIZE 30
#define INCREMENT 30

#define _heap this->heap
#define _index this->indexForNextElement
#define _size this->size

struct cell_t {
    int priority;
    T value;
};

struct priorityqueue_t {
    struct cell_t *heap;
    int indexForNextElement;
    int size;
};

void percolateUp(PriorityQueue this, int index);

int hasToMoveUp(PriorityQueue this, int index, int *father);

void percolateDown(PriorityQueue this, int index);

int hasToMoveDown(PriorityQueue this, int index, int *sonMin);

void swap(struct cell_t *a, struct cell_t *b);

PriorityQueue newPriorityQueue() {
    PriorityQueue queue = malloc(sizeof(struct priorityqueue_t));
    queue->heap = calloc(sizeof(struct cell_t), HEAP_SIZE);
    queue->indexForNextElement = 1;
    queue->size = HEAP_SIZE;
    return queue;
}


T PriorityQueuePop(PriorityQueue this) {
    T res = _heap[1].value;
    swap(&_heap[1], &_heap[--_index]);
    percolateDown(this, 1);
    return res;
}

void PriorityQueueAdd(PriorityQueue this, T value, int priority) {
    if (_index >= _size) {
        _heap = realloc(_heap, sizeof(struct cell_t) * (_size += INCREMENT));
    }
    _heap[_index].priority = priority;
    _heap[_index].value = value;
    percolateUp(this, _index);
    _index++;
}


void PriorityQueueChangePrio(PriorityQueue this, T value, int newPriority) {
    int index;

    index = 1;

    /* Searches for the value */
    /* Only works with the same pointer */
    /* TODO use a function pointer to have a generic search */
    while (_heap[index].value != value && index < _index) {
        index++;
    }

    if (_heap[index].value == value) {

        if (_heap[index].priority < newPriority) {
            _heap[index].priority = newPriority;
            percolateUp(this, index);

        } else if (_heap[index].priority > newPriority) {
            _heap[index].priority = newPriority;
            percolateDown(this, index);

        }
    }

}


int PriorityQueueIsEmpty(PriorityQueue this) {
    return _index == 1;
}


void PriorityQueueDelete(PriorityQueue this) {
    free(_heap);
    free(this);
}

void percolateUp(PriorityQueue this, int index) {
    int father;
    while (hasToMoveUp(this, index, &father)) {
        swap(&_heap[index], &_heap[father]);
        index = father;
    }
}

int inline hasToMoveUp(PriorityQueue this, int index, int *father) {
    *father = index >> 1;
    return index != 1 && _heap[index].priority > _heap[*father].priority;
}

void percolateDown(PriorityQueue this, int index) {
    int sonMin;
    while (hasToMoveDown(this, index, &sonMin)) {
        swap(&_heap[index], &_heap[sonMin]);
        index = sonMin;
    }
}

int hasToMoveDown(PriorityQueue this, int index, int *sonMin) {
    int otherSon;

    *sonMin = index << 1;
    otherSon = *sonMin + 1;

    if (*sonMin >= _index) {
        return 0;
    }

    if (_heap[index].priority > _heap[*sonMin].priority) {

        if (otherSon < index && _heap[otherSon].priority < _heap[*sonMin].priority) {
            *sonMin = otherSon;
        }

        return 1;
    }

    return 0;
}


void inline swap(struct cell_t *a, struct cell_t *b) {
    struct cell_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
