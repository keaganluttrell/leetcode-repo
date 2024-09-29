#include "binarysearch.h"
#include <stdlib.h>

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

int comparator(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize,
                   int *returnSize) {
    int *result = (int *)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    qsort(nums, numsSize, sizeof(int), comparator);

    int *prefixSum = (int *)malloc(numsSize * sizeof(int));
    prefixSum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (int i = 0; i < queriesSize; i++) {
        int query = queries[i];
        int left = 0, right = numsSize - 1;
        int maxSubsequenceSize = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] <= query) {
                maxSubsequenceSize = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[i] = maxSubsequenceSize;
    }

    free(prefixSum);
    return result;
}

int ceiling_div(int a, int b) { return (a + b - 1) / b; }

int smallestDivisor(int *nums, int n, int threshold) {
    int max, i, j, a;
    for (i = 0, max = 0; i < n; ++i) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    for (i = max; i > 0; --i) {
        a = 0;
        for (j = 0; j < n; ++j) {
            a += ceiling_div(nums[j], i);
        }
        if (a < threshold) {
            return i;
        }
    }
    return i;
}
