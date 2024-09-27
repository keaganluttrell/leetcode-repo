#include "binarysearch.h"

int searchInsert(int *nums, int n, int target) {

    int l = 0, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (nums[m] >= target) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;
}
