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

#include <LinkedList.h>

#define _first this->first
#define _current this->current
#define _last this->last
#define _length this->length
#define _beforeCurrent this->beforeCurrent

struct linkedlist_t {
    int length;
    struct linkedlist_node *first;
    struct linkedlist_node *beforeCurrent;
    struct linkedlist_node *current;
    struct linkedlist_node *end;
};

struct linkedlist_node {
    T value;
    struct linkedlist_node *next;
};

LinkedList newLinkedList() {
    LinkedList list;

    list = malloc(sizeof(struct linkedlist_t));
    list->length = 0;
    list->first = NULL;
    list->current = NULL;
    list->last = NULL;
    return list;
}

struct linkedlist_node *newNode(T value);

struct linkedlist_node *NodeAtIndex(LinkedList this,int i);

void NodeRemove(LinkedList this, struct linkedlist_node *previous, struct linkedlist_node *toRemove);

void LinkedListAppendLinkedList(LinkedList this, LinkedList l) {
    _last->next = l->first;
    _last = l->last;
    _length += l->length;
}

/* add */

void LinkedListAddLast(LinkedList this, T value) {
    struct linkedlist_node *node;

    node = newNode(value);

    if (LinkedListIsEmpty(this)) {
        _first = node;
        _last = node;
    } else {
        _last->next = node;
        _last = node;
    }
    _length++;
}

void LinkedListAddFirst(LinkedList this, T value) {
    struct linkedlist_node *node;

    node = newNode(value);

    if (LinkedListIsEmpty(this)) {
        _first = node;
        _last = node;
    } else {
        node->next = _first;
        _first = node;

        if (_current && !_beforeCurrent) {
            _beforeCurrent = _first;
        }

    }
    _length++;
}

void LinkedListAddAtIndex(LinkedList this, T value, int i) {
    struct linkedlist_node *node;
    struct linkedlist_node *nodeAtIndexMinus1;


    nodeAtIndexMinus1 = NodeAtIndex(this, i-1);

    if (!nodeAtIndexMinus1) {
        LinkedListAddFirst(this, value);
    } else if (nodeAtIndexMinus1 == _last) {
        LinkedListAddLast(this, value);
    } else {
        node = newNode(value);
        node->next = nodeAtIndexMinus1->next;
        nodeAtIndexMinus1->next = node;
        _length++;

        if (node->next == _current) {
            _beforeCurrent = node;
        }
    }
}

void LinkedListAddCurrent(LinkedList this, T value) {
    struct linkedlist_node *node;

    if (!_current) {
        LinkedListAddFirst(this, value);
    } else if(_current == _last) {
        LinkedListAddLast(this, value);
    } else {
        node = newNode(value);
        node->next = _current->next;
        _current->next = node;
        _length++;
    }
}

/* remove */

int LinkedListRemoveValue(LinkedList this, T value) {
    struct linkedlist_node *current;
    struct linkedlist_node *previous;

    current = _first;
    previous = NULL;

    while(current) {
        if (current->value == value) {

            NodeRemove(this, previous, current);

            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

int LinkedListRemoveAtIndex(LinkedList this, int i) {
    struct linkedlist_node *current;
    struct linkedlist_node *previous;

    current = _first;
    previous = NULL;

    if (i < 0) {
        return 0;
    }

    while(i--) {
        if (!current) {
            return 0;
        }

        previous = current;
        current = current->next;
    }

    NodeRemove(this, previous, current);
    return 1;
}

int LinkedListRemoveCurrent(LinkedList this) {

    if (_current) {
        NodeRemove(this, _beforeCurrent, _current);
        return 1;
    }

    return 0;
}

/* get */

T LinkedListGetAtIndex(LinkedList this, int i) {
    struct linkedlist_node *node;

    node = NodeAtIndex(this, i);

    return node ? node->value : NULL;
}

T LinkedListGetLast(LinkedList this) {
    return _last ? _last->value : NULL;
}

T LinkedListGetFirst(LinkedList this) {
    return _first ? _first->value : NULL;
}

T LinkedListGetCurrent(LinkedList this) {
    return _current ? _current->value : NULL;
}

/* iterator */

int LinkedListMoveCurrentNext(LinkedList this) {
    if (!_current) {
        _current = _first;
        return 1;
    }
    if (_current->next) {
        _beforeCurrent = _current;
        _current = _current->next;
        return 1;
    }
    return 0;
}

void LinkedListResetCurrent(LinkedList this) {
    _current = NULL;
    _beforeCurrent = NULL;
}

/* usefull */

int LinkedListSearch(LinkedList this, T value) {
    struct linkedlist_node *current;

    current = _first;

    while(current) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int LinkedListDisplay(LinkedList this) {

}

int LinkedListIsEmpty(LinkedList this) {
    return !_first;
}

void LinkedListDelete(LinkedList this) {
    struct linkedlist_node *current;
    struct linkedlist_node *tmp;

    current = _first;

    while(current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(this);
}

int LinkedListGetLength(LinkedList this) {
    return _length;
}

struct linkedlist_node* newNode(T value) {
    struct linkedlist_node *node;

    node = malloc(sizeof(struct linkedlist_node));
    node->value = value;
    node->next = NULL;

    return node;
}

struct linkedlist_node *NodeAtIndex(LinkedList this,int i) {
    struct linkedlist_node *current;

    current = _first;

    if (i < 0) {
        return NULL;
    }

    while(i--) {
        if (!current) {
            return NULL;
        }
        current = current->next;
    }

    return current;
}

void NodeRemove(LinkedList this, struct linkedlist_node *previous, struct linkedlist_node *toRemove) {

    if (_length == 1) {
        _first = NULL;
        _last = NULL;
    } else {

        if (toRemove == _first) {
            _first = toRemove->next;
        } else if (toRemove == _last) {
            _last = previous;
            _last->next = NULL;
        } else {
            previous->next = toRemove->next;
        }
    }

    if (toRemove == _current) {
        _current = previous;
    }

    _length--;
    free(toRemove);
}