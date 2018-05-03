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
 * @Date 21/04/2018
 */

#ifndef CCOLLECTIONS_TREESET_H
#define CCOLLECTIONS_TREESET_H

#include <util.h>

typedef struct treeset_t *TreeSet;

TreeSet newTreeSet(int (*compareTo)(T value1, T value2), size_t size);

/**
 *
 * @param this
 * @param value
 * @return
 */
int TreeSetAdd(TreeSet this, T value);

int TreeSetRemove(TreeSet this, unsigned int i);

int TreeSetRemoveValue(TreeSet this, T value);

int TreeSetContains(TreeSet this, T value);

int TreeSetContainsValue(TreeSet this, T value);

int TreeSetIsEmpty(TreeSet this);

void TreeSetDisplay(TreeSet this);

void TreeSetPrint(TreeSet this, void (*printT)(T value));

T *TreeSetToArray(TreeSet this);

void TreeSetForEach(TreeSet this, T (*apply)(T value));

void TreeSetDelete(TreeSet this);

#endif //CCOLLECTIONS_TREESET_H
