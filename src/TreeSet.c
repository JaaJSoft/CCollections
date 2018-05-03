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

typedef struct treenode_t {
    struct treenode_t *sonG;
    struct treenode_t *sonD;
    struct treenode_t *father;
    T value;
} *TreeNode;

struct treeset_t {
    TreeNode root;
    TreeNode current;
    size_t size; //size of element
    unsigned int numberOfElement;

    int (*compareTo)(T value1, T value2);
};

TreeSet newTreeSet(int (*compareTo)(T, T), size_t size) {
    TreeSet t = malloc(sizeof(struct treeset_t));
    t->compareTo = compareTo;
    t->current = NULL;
    t->root = NULL;
    t->size = size;
    t->numberOfElement = 0;
    return t;
}

int isNULL(TreeNode t) {
    return t == NULL;
}

TreeNode newTreeNode(TreeNode father, T value) {
    TreeNode t = malloc(sizeof(struct treenode_t));
    t->father = father;
    t->sonD = NULL;
    t->sonG = NULL;
    t->value = value;
    return t;
}

int TreeNodeAdd(TreeSet this, TreeNode father, T value) {
    int compare = this->compareTo(father->value, value);
    if (compare < 0) {
        if (isNULL(father->sonG)) {
            father->sonG = newTreeNode(father, value);
            this->numberOfElement++;
            return 1;
        }
        return TreeNodeAdd(this, father->sonG, value);
    } else if (compare > 0) {
        if (isNULL(father->sonD)) {
            father->sonD = newTreeNode(father, value);
            this->numberOfElement++;
            return 1;
        }
        return TreeNodeAdd(this, father->sonD, value);
    }
    return 0;
}


int TreeSetAdd(TreeSet this, T value) {
    if (TreeSetIsEmpty(this)) { //root case
        this->root = newTreeNode(NULL, value);
        this->numberOfElement++;
        this->current = this->root;
    } else {
        TreeNodeAdd(this, this->root, value);
    }
}

int TreeSetIsEmpty(TreeSet this) {
    return this->numberOfElement == 0;
}

void TreeSetDelete(TreeSet this) {

}









