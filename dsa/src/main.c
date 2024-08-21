#include <stdio.h>
// #include <stdlib.h>

#include "arrays-strings.h"

int main(int charc, char *argv[]) {

    int nums[] = {1, 0, 1};
    int numsSize = 3;
    int k = 0;

    int result = longestOnes(nums, numsSize, k);
    printf("assert %d is 1\n", result);

    int nums2[] = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    //                         L                       L
    int numsSize2 = 19;
    int k2 = 3;
    int result2 = longestOnes(nums2, numsSize2, k2);
    printf("assert %d is 10\n", result2);

    int nums3[] = {0, 0, 1};
    int numsSize3 = 3;
    int k3 = 0;
    int result3 = longestOnes(nums3, numsSize3, k3);
    printf("assert %d is 1\n", result3);

    return 0;
}
