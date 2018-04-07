//
// Created by Pierre on 06/04/2018.
//

#include "Array.h"


struct array_t {
    void **tab;
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
        a->tab[i] = value;
    }
}

int ArrayAppend(Array a, T value) {
    if (a->length == a->realLength) {
        a->realLength += a->increment;
        a->tab = realloc(a->tab, sizeof(a->realLength));
        a->tab[a->length] = value;
        a->length++;
    }
    a->tab[a->length] = value;
    a->length++;
    return 0;
}

void ArrayRemoveValue(Array a, T value) {
    for (int i = 0; i < a->length; i++) {
        if (a->tab[i] == value) {
            a->tab[i] = 0;
            for (int j = i; j < a->length - 1; j++) {
                a->tab[j] = a->tab[j + 1];
            }
            a->length--;
        }
    }
}

void ArrayRemoveOneValue(Array a, T value) {
    for (int i = 0; i < a->length; i++) {
        if (a->tab[i] == value) {
            a->tab[i] = 0;
            for (int j = i; j < a->length - 1; j++) {
                a->tab[j] = a->tab[j + 1];
            }
            a->length--;
            return;
        }
    }
}

void ArrayDelete(Array a) {

}

void ArrayDisplay(Array a) {
    for (int i = 0; i < a->length; i++) {
        printf("%d ", *((int *) (a->tab[i])));
    }
    printf("\n");
}
