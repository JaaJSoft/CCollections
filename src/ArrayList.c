//
// Created by Pierre on 06/04/2018.
//

#include <include/ArrayList.h>


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
