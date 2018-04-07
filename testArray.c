//
// Created by Pierre on 06/04/2018.
//

#include "Array.h"

int main() {

    Array a = newArray(2, 1);
    int b = 0, c = 5, d = 42;

    ArrayAppend(a, &b);
    ArrayAppend(a, &c);
    ArrayAppend(a, &c);
    ArrayAppend(a, &b);
    ArraySet(a, 2, &d);
    ArrayDisplay(a);
    ArrayRemoveValue(a,&b);
    ArrayDisplay(a);

    ArrayAppend(a, &d);
    ArrayDisplay(a);




    return 0;
}
