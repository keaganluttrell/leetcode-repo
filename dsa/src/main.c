#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#include "queues.h"

int main(int argc, char *argv[]) {

    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int exp[] = {-1, 3, -1};
    int return_sz;
    int *actual = nextGreaterElement(nums1, 3, nums2, 4, &return_sz);

    printf("Expected: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", exp[i]);
    }

    printf("\n");
    printf("Actual  : ");
    for (int i = 0; i < return_sz; ++i) {
        printf("%d ", actual[i]);
    }
    printf("\n");
    free(actual);

    return 0;
}
