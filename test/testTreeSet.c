//
// Created by pierre on 01/05/18.
//

#include <TreeSet.h>
#include <CompareTo.h>

int main() {
    TreeSet t = newTreeSet(compareToInt, sizeof(int));

    int a = 1;
    int b = 2;
    int c = 0;
    TreeSetAdd(t, &a);
    TreeSetAdd(t, &b);
    TreeSetAdd(t, &c);


}