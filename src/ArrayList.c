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
 * @Date 06/04/2018
 */

#include <ArrayList.h>
#include <string.h>


struct ArrayList_t {
    T *tab;
    size_t length;
    size_t realLength;
    size_t size;
};

ArrayList newArrayList(size_t initLength, size_t size) {
    ArrayList this = malloc(sizeof(struct ArrayList_t));
    this->length = 0;
    this->realLength = initLength;
    this->size = size;
    this->tab = malloc(sizeof(void *) * initLength);
    return this;
}

T ArrayListGet(ArrayList this, unsigned int i) {
    if (i >= this->length) {
        return NULL;
    }
    return this->tab[i];
}

void ArrayListSet(ArrayList this, unsigned int i, T value) {
    if (i >= this->length) {
        return;
    } else {
        //printf("SET :%d %p\n",i, value);
        this->tab[i] = value;
    }
}

void ArrayListAppend(ArrayList this, T value) {
    if (this->length == this->realLength) {
        this->realLength *= 2;
        this->tab = realloc(this->tab, sizeof(this->realLength));
    }
    //printf("INSERT : %p\n", value);
    this->tab[this->length] = value;
    this->length++;
}

void ArrayListRemoveValue(ArrayList this, unsigned int i) {
    for (int j = i; j < this->length - 1; j++) {
        this->tab[j] = this->tab[j + 1];
    }
    this->length--;
}


void ArrayListDelete(ArrayList this) {
    free(this->tab);
    free(this);
}

void ArrayListDisplay(ArrayList this) {
    printf("Length : %d, Real Length : %d\n", this->length, this->realLength);
    fflush(stdout);
    for (int i = 0; i < this->length; i++) {
        printf("%p\n", this->tab[i]);
        fflush(stdout);
    }
    printf("\n");
}

void ArrayListMatchLength(ArrayList this) {
    this->tab = realloc(this->tab, sizeof(T) * this->length);
    this->realLength = this->length;
}

int ArrayListGetLength(ArrayList this) {
    return this->length;
}

int ArrayListGetRealLength(ArrayList this) {
    return this->realLength;
}

int ArrayListGetIncrement(ArrayList this) {
    return this->increment;
}

int ArrayListIsEmpty(ArrayList this) {
    if (this->length == 0) {
        return 1;
    }
    return 0;
}

T *ArrayListToArray(ArrayList this) {
    T *tab = malloc(sizeof(T) * this->length);
    memcpy(tab, this->tab, (size_t) this->length);
    return tab;
}

void ArrayListForEach(ArrayList this, T (*apply)(T)) {
    int i;
    for (i = 0; i < this->length; i++) {
        this->tab[i] = apply(this->tab[i]);
    }
}

int ArrayListContains(ArrayList this, T value) {
    int i;
    for (i = 0; i < this->length; i++) {
        if (this->tab[i] == value) {
            return 1;
        }
    }
    return 0;
}

int ArrayListContainsValue(ArrayList this, T value) {
    int i;
    for (i = 0; i < this->length; i++) {
        if (memcmp(this->tab[i], value, this->size) == 0) {
            return 1;
        }
    }
    return 0;
}
