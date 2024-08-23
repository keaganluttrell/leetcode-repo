#include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

int main(int charc, char *argv[]) {

    int nums1[] = {1, 2, 3};
    int expected1 = 2;
    int actual1 = countElements(nums1, 3);

    int nums2[] = {1, 1, 3, 3, 5, 5, 7, 7};
    int expected2 = 0;
    int actual2 = countElements(nums2, 8);

    printf("actual: %d, expected: %d\n", actual1, expected1);
    printf("actual: %d, expected: %d\n", actual2, expected2);
    return 0;
}
