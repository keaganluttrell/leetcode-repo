#include "hashmaps.h"
#include <stdio.h>
// #include <stdlib.h>

int main(int charc, char *argv[]) {

    int nums1[] = {3, 0, 1};
    int expected1 = 2;
    int actual1 = missingNumber(nums1, 3);

    int nums2[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int expected2 = 8;
    int actual2 = missingNumber(nums2, 9);

    int nums3[] = {0, 1};
    int expected3 = 2;
    int actual3 = missingNumber(nums3, 2);

    printf("actual: %d, expected: %d\n", actual1, expected1);
    printf("actual: %d, expected: %d\n", actual2, expected2);
    printf("actual: %d, expected: %d\n", actual3, expected3);
    return 0;
}
