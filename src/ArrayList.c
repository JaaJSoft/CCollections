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


struct ArrayList_t {
    T *tab;
    int length;
    int realLength;
    int increment;
};

ArrayList newArrayList(int initLength, int increment) {
    ArrayList this = malloc(sizeof(struct ArrayList_t));
    this->increment = increment;
    this->length = 0;
    this->realLength = initLength;
    this->tab = malloc(sizeof(void *) * initLength);
    return this;
}

T ArrayListGet(ArrayList this, int i) {
    if (i >= this->length) {
        return NULL;
    }
    return this->tab[i];
}

void ArrayListSet(ArrayList this, int i, T value) {
    if (i >= this->length) {
        return;
    } else {
        //printf("SET :%d %p\n",i, value);
        this->tab[i] = value;
    }
}

int ArrayListAppend(ArrayList this, T value) {
    if (this->length == this->realLength) {
        this->realLength += this->increment;
        this->tab = realloc(this->tab, sizeof(this->realLength));
    }
    //printf("INSERT : %p\n", value);
    this->tab[this->length] = value;
    this->length++;
    return 0;
}

void ArrayListRemoveValue(ArrayList this, int i) {
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
    if(this->length==0){
        return 1;
    }
    return 0;
}
