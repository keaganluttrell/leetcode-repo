// #include <stdio.h>
#include <stdlib.h>

#include "heaps.h"

int main(int argc, char *argv[]) {
    int *arr = malloc(sizeof(int) * 4);
    int tmp[4] = {4, 3, 6, 7};
    for (int i = 0; i < 4; ++i) {
        arr[i] = tmp[i];
    }

    minStoneSum(arr, 4, 3);

    return 0;
}
