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

#ifndef CCOLLECTIONS_STACK_H
#define CCOLLECTIONS_STACK_H

#include <util.h>

/**
 * The stack is a list in which the first in is the last out
 */
typedef struct stack_t *Stack;

/**
 * The cell contain a value and a reference to the previous cell of the stack
 */
typedef struct cell_t *Cell;

/**
 * Create a new stack
 * @return the stack created
 */
Stack newStack();

/**
 * Create a new cell
 * @param the value of the cell
 * @return the cell created
 */
Cell newCell(T value);

/**
 * Pop the last value of the stack
 * @param the stack in which the value will be popped
 * @return the last value of the stack
 */
T StackPop(Stack this);

/**
 * Add a value into the stack by creating a new cell
 * @param the stack in which the value will be added
 * @param the value to add to the stack
 */
void StackAdd(Stack this,T value);

/**
 * Check if the stack is empty
 * @param the stack to check the state
 * @return 1 if it's empty, else 0
 */
int StackIsEmpty(Stack this);


/**
 * Display all values included in the stack
 * from the last to the first value
 * @param the stack to display
 */
void DisplayAllStack(Stack this);

/**
 * Delete the stack by deleting all cell of the stack
 * @param the stack to delete
 */
void StackDelete(Stack this);

/**
 * Delete a cell and release its memory
 * @param the cell to delete
 */
void CellDelete(Cell cell);

#endif //CCOLLECTIONS_STACK_H
