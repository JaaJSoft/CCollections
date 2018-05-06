//
// Created by pierre on 01/05/18.
//

#include <TreeSet.h>
#include <CompareTo.h>
#include <time.h>

void printInt(T value) {
    printf("%d ", *((int *) value));
}

int main() {
    /*
    TreeSet t = newTreeSet(compareToInt, sizeof(int));

    int a = 1;
    int b = 2;
    int c = 0;
    TreeSetAdd(t, &a);
    TreeSetAdd(t, &b);
    TreeSetAdd(t, &c);
    int *test = TreeSetNext(t);
    printf("%d\n", *test);
    test = TreeSetNext(t);
    printf("%d\n", *test);
    test = TreeSetNext(t);
    printf("%d\n", *test);
    */

    TreeSet p = newTreeSet(compareToInt, sizeof(int *));
    srand(time(NULL));
    printf("Inserted : \n");
    for (int i = 0; i < 10; i++) {
        int *j = malloc(sizeof(int));
        *j = rand() % 10;
        printf("%d ", *j);
        TreeSetAdd(p, j);
    }
    printf("\nfind : ");

    TreeSetForEach(p, printInt);

    /*printf("\nFind : \n");
    int *next = NULL;
    do {
        next = TreeSetNext(p);
        printf("%d ", *next);
        free(next);
    } while (next != NULL);
*/
}