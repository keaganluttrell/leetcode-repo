#include "binarysearch.h"
#include <limits.h>
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

int _comparator(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize,
                   int *returnSize) {
    int *result = (int *)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    qsort(nums, numsSize, sizeof(int), _comparator);

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

int computeSum(int *nums, int n, int d, int t) {
    int sum = 0, x = d - 1;
    for (int i = 0; i < n; i++) {
        sum += (nums[i] + x) / d;
        if (sum > t) {
            return sum;
        }
    }
    return sum;
}

int smallestDivisor(int *nums, int n, int threshold) {
    int low = 1, high = 0, mid;

    for (int i = 0; i < n; ++i) {
        if (nums[i] > high) {
            high = nums[i];
        }
    }

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (computeSum(nums, n, mid, threshold) <= threshold) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int canDivide(int *sweetness, int sweetnessSize, int k, int minSweetness) {
    int pieces = 0, currentSweetness = 0;

    for (int i = 0; i < sweetnessSize; i++) {
        currentSweetness += sweetness[i];

        if (currentSweetness >= minSweetness) {
            pieces++;
            currentSweetness = 0;
        }
    }

    return pieces >= k + 1;
}

int maximizeSweetness(int *sweetness, int sweetnessSize, int k) {
    int low = 1, high = 0, mid;

    for (int i = 0; i < sweetnessSize; i++) {
        high += sweetness[i];
    }

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (canDivide(sweetness, sweetnessSize, k, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int canSplit(int *nums, int numsSize, int k, int maxSum) {
    int currentSum = 0;
    int subarrays = 1;

    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] > maxSum) {
            subarrays++;
            currentSum = nums[i];
            if (subarrays > k) {
                return 0;
            }
        } else {
            currentSum += nums[i];
        }
    }

    return 1;
}

int splitArray(int *nums, int n, int k) {
    int low = 0, high = 0, mid, i;

    for (i = 0; i < n; ++i) {
        if (nums[i] > low) {
            low = nums[i];
        }
        high += nums[i];
    }

    while (low < high) {
        mid = low + (high - low) / 2;

        if (canSplit(nums, n, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
