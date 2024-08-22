#include <stdio.h>
#include <stdlib.h>

#include "arrays-strings.h"

int main(int charc, char *argv[]) {

    int nums[] = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int expected[] = {-1, -1, -1, 5, 4, 4, -1, -1, -1};
    int sz = sizeof(nums) / sizeof(nums[0]);
    int k = 1;
    int return_sz;
    int *result = getAverages(nums, sz, k, &return_sz);

    printf("expected , actual\n");
    for (int i = 0; i < return_sz; i++) {
        printf("i:%d, %d , %d\n", i, expected[i], result[i]);
    }
    free(result);
    return 0;
}
