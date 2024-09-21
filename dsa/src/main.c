#include <stdio.h>
#include <stdlib.h>

#include "heaps.h"

int main(int argc, char *argv[]) {
    int *arr = malloc(sizeof(int) * 3);
    int tmp[3] = {2, 4, 3};
    for (int i = 0; i < 3; ++i) {
        arr[i] = tmp[i];
    }

    int answer = connectSticks(arr, 3);

    printf("answer: %d\n", answer);

    return 0;
}
