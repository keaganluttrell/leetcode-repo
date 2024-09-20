#include "heaps.h"
#include <stdio.h>
#include <stdlib.h>

int min_stone_comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int minStoneSum(int *piles, int pilesSize, int k) {
    int sum, i, ops;
    sum = 0, ops = 0;
    for (i = 0; i < pilesSize; ++i) {
        sum += piles[i];
    }

    qsort(piles, pilesSize, sizeof(int), min_stone_comp);
    for (i = 0; i < pilesSize; ++i) {
        printf("%d ", piles[i]);
    }
    printf("\n");

    return sum;
}
