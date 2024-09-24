#include <stdio.h>
#include <stdlib.h>

#include "greedy.h"

int main(int argc, char *argv[]) {
    int i, n, a;
    n = 6;
    int *arr = malloc(sizeof(int) * n);
    arr[0] = 9669;
    arr[1] = 9996;
    arr[2] = 9999;
    arr[3] = 666;
    arr[4] = 66;
    arr[5] = 6;
    int *exp = malloc(sizeof(int) * n);
    exp[0] = 9969;
    exp[1] = 9999;
    exp[2] = 9999;
    exp[3] = 966;
    exp[4] = 96;
    exp[5] = 9;

    for (i = 0; i < n; ++i) {
        printf("FN: %d\n", arr[i]);
        a = maximum69Number(arr[i]);
        printf("e:%d == a:%d -- %s\n", exp[i], a,
               exp[i] == a ? "true" : "false");
    }

    return 0;
}
