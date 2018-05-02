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

int main() {

    T val;
    Stack stack = newStack();

    StackAdd(stack, 5);
    StackAdd(stack, 'a');
    StackAdd(stack, 'p');
    StackAdd(stack, 4);

    printf("Test 1 (expected : 0x04, 0x70, 0x61, 0x05) : \n");
    DisplayAllStack(stack);
    printf("\n");

    val = StackPop(stack);
    printf("pop value : %p\n", val);
    val = StackPop(stack);
    printf("pop value : %p\n", val);
    val = StackPop(stack);
    printf("pop value : %p\n", val);

    printf("Test 2 (expected : 0x05) : \n");
    DisplayAllStack(stack);
    printf("\n");

    StackDelete(stack);
    printf("Test 3 (expected : Empty) : \n");
    DisplayAllStack(stack);
    printf("\n");

    StackAdd(stack, 'p');
    StackAdd(stack, 4);

    printf("Test 4 (expected : Empty) : \n");
    DisplayAllStack(stack);
    printf("\n");

    return EXIT_SUCCESS;

}
