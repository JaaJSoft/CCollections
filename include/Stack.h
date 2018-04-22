//
// Created by remi on 22/04/18.
//

#ifndef CCOLLECTIONS_STACK_H
#define CCOLLECTIONS_STACK_H

#include <include/util.h>

/**
 *
 */
typedef struct stack_t *Stack;

/**
 *
 * @return
 */
Stack newStack();

/**
 *
 * @param this
 * @return
 */
T StackPop(Stack this);

/**
 *
 * @param this
 * @param value
 */
void StackAdd(Stack this,T value);

/**
 *
 * @param this
 * @return
 */
int StackIsEmpty(Stack this);

/**
 *
 */
void StackDelete();

#endif //CCOLLECTIONS_STACK_H
