//
// Created by Pierre on 06/04/2018.
//

#include <ArrayList.h>
#include <time.h>

int main() {

    ArrayList a = newArrayList(sizeof(int));
    srand(time(NULL));
    printf("Expected : \n");
    for (int i = 0; i < 80; i++) {
        int *t = malloc(sizeof(int));
        *t = rand() % 100;
        printf("%d ", *t);
        ArrayListAppend(a, t);
    }
    printf("\nFind : \n");
    for (int i = 0; i < 80; i++) {
        int *b = ArrayListGet(a, i);
        printf("%d ", *b);
        free(b);
    }

    ArrayListDelete(a);
    return 0;
}
