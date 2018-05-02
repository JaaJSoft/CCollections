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
 * @author Julien Chevron
 * @Date 30/04/18
 */

#include <Stack.h>

struct stack_t{
    struct cell_t* top;
};

struct cell_t {
    struct cell_t* previous;
    T value;
};


Stack newStack(){
    Stack this = (struct stack_t*) malloc(sizeof(struct stack_t));
    return this;
}


Cell newCell(T value){
    Cell cell = (struct cell_t*) malloc(sizeof(struct cell_t));
    cell->value = value;
    cell->previous = NULL;
    return cell;
}


T StackPop(Stack this){
    T tempValue;
    Cell tempCell;
    if(StackIsEmpty(this)){
        return NULL;
    }else{
        tempValue = this->top->value;
        tempCell = this->top->previous;
        CellDelete(this->top);
        this->top = tempCell;
        return tempValue;
    }
}


void StackAdd(Stack this,T value){
    Cell cell = newCell(value);
    Cell tmp = this->top;
    this->top = cell;
    this->top->previous = tmp;
}


int StackIsEmpty(Stack this){
    return (this->top == NULL);
}



void DisplayAllStack(Stack this){
    Cell temp = this->top;
    int count = 0;
    if(StackIsEmpty(this)){
        printf("Stack is empty\n");
    }else{
        while(temp != NULL){
            printf("%p\n", temp->value);
            temp = temp->previous;
            count++;
        }
        printf("Total value(s) : %d\n", count);
    }

}


void StackDelete(Stack this){
    while(!StackIsEmpty(this)){
        StackPop(this);
    }
    this = NULL;
}


void CellDelete(Cell cell){
    free(cell);
    cell = NULL;
}



