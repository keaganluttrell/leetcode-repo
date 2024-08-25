// #include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

#include "hashmaps.h"
int main(int argc, char *argv[]) {

    int arr[] = {0, 1};
    int expected = 2;
    int actual = findMaxLength(arr, 2);

    printf("e: %d, a: %d\n", expected, actual);

    int arr2[] = {0, 1, 0};
    int expected2 = 2;
    int actual2 = findMaxLength(arr2, 2);

    printf("e: %d, a: %d\n", expected2, actual2);

    int arr3[] = {1, 1, 0, 0};
    int expected3 = 4;
    int actual3 = findMaxLength(arr3, 4);

    printf("e: %d, a: %d\n", expected3, actual3);

    return 0;
}
