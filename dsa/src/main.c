#include <stdio.h>
#include <stdlib.h>

#include "greedy.h"

int main(int argc, char *argv[]) {

    int *arr = malloc(sizeof(int) * 10);
    int tmp[6] = {7, 7, 7, 7, 7, 7};
    for (int i = 0; i < 10; ++i) {
        arr[i] = tmp[i];
    }

    int answer = minSetSize(arr, 6);
    printf("answer=%d\n", answer);
    return 0;
}
