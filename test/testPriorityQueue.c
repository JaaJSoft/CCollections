//
// Created by pierre on 01/05/18.
//

#include <PriorityQueue.h>
#include <time.h>

int main() {
    PriorityQueue p = newPriorityQueue();
    srand(time(NULL));
    for (int i = 0; i < 80; i++) {
        int *t = malloc(sizeof(int));
        *t = rand()%100;
        PriorityQueueAdd(p, t, 1);
    }
    for (int i = 0; i < 80; i++) {
        int *a = PriorityQueuePop(p);
        printf("%d ", *a);
        free(a);
    }


}
