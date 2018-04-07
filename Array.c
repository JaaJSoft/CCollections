//
// Created by Pierre on 06/04/2018.
//

#include "Array.h"


struct array_t {
    T * tab;
    int length;
    int realLength;
    int increment;
};

Array newArray(int initLength, int increment) {
    Array a = malloc(sizeof(struct array_t));
    a->increment = increment;
    a->length = 0;
    a->realLength = initLength;
    a->tab = malloc(sizeof(void *) * initLength);
    return a;
}

T ArrayGet(Array a, int i) {
    if (i >= a->length) {
        return NULL;
    }
    return a->tab[i];
}

void ArraySet(Array a, int i, T value) {
    if (i >= a->length) {
        return;
    } else {
        //printf("SET :%d %p\n",i, value);
        a->tab[i] = value;
    }
}

int ArrayAppend(Array a, T value) {
    if (a->length == a->realLength) {
        a->realLength += a->increment;
        a->tab = realloc(a->tab, sizeof(a->realLength));
    }
    //printf("INSERT : %p\n", value);
    a->tab[a->length] = value;
    a->length++;
    return 0;
}

void ArrayRemoveValue(Array a, int i) {
    for (int j = i; j < a->length - 1; j++) {
        a->tab[j] = a->tab[j + 1];
    }
    a->length--;
}


void ArrayDelete(Array a) {
   free(a->tab);
   free(a);
}

void ArrayDisplay(Array a) {
    printf("Length : %d, Real Length : %d\n",a->length,a->realLength);
    fflush(stdout);
    for (int i = 0; i < a->length; i++) {
        printf("%p\n", a->tab[i]);
        fflush(stdout);
    }
    printf("\n");
}
