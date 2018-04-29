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
 * @Date 28/04/2018
 */

#include <TreeSet.h>

struct treeset_t {
    struct treeset_t root;
    struct treeset_t current;
    size_t size; //size of element
    unsigned int numberOfElement;

    int (*compareTo)(T this, T value);
};

typedef struct treenode_t {
    struct treenode_t sonG;
    struct treenode_t sonD;
    struct treenode_t father;
    T value;
} *TreeNode;