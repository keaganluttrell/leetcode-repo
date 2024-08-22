#include <stdio.h>
#include <stdlib.h>

#include "arrays-strings.h"

/* TWO POINTERS
 * Define the problem: We take a non decreasing array of integers (ints)
 * square them, and return them in non-decreasing order.
 *
 * Constraints: array will have atleast one int, but no more than 10,000
 *
 * Inputs: array of ints in non decreasing order
 *
 * Outputs: array of squared ints in non decreating order
 *
 * Edge Cases: single array
 *
 * Psuedocode then solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

int *sorted_squares(int *nums, int num_sz, int *return_sz) {
    int *return_nums = (int *)malloc(sizeof(int) * num_sz);

    int ptr = num_sz - 1;
    int l = 0;
    int r = num_sz - 1;

    while (l <= r) {
        int l2 = nums[l] * nums[l];
        int r2 = nums[r] * nums[r];

        if (l2 > r2) {
            return_nums[ptr--] = l2;
            l++;
        } else {
            return_nums[ptr--] = r2;
            r--;
        }
    }
    *return_sz = num_sz;
    return return_nums;
}

/* TWO POINTERS
 * Define the Problem: given a string and its size,
 * reverse the string in place
 *
 * Constraints: reverse the sting in place
 *  -> String Size 1<= string sz <= 10^5
 *  -> each char is a printable ascii char
 *
 * Inputs: string_ptr and int sz
 *
 * Outputs: void, side effect is that the string changes in place
 *
 * Edge Cases:
 *  -> Empty string?
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

void reverse_string(char *s, int sz) {
    printf("sz %d\n", sz);

    if (sz < 2)
        return;

    int left = 0;
    int right = sz - 1;

    while (left < right) {
        // swap pointers
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

/* SLIDING WINDOW
 * Add element to window from right
 * While condition is not met,
 * rm elements from left
 *
 * Define the Problem:
 *
 * Constraints:
 *  n == nums.length
 *  1 <= k <= n <= 10^5
 *  10^-4 <= nums[i] <= 10^4
 *
 * Inputs: int array of numbers, n elements, and int k
 *
 * Outputs: Double (Max Avg of sub array length of k)
 *
 * Edge Cases:
 *  single element array, return value as double
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 * [0,1,2,3,4,5]; k=4
 *  1 2 3 4
 */

double findMaxAverage(int *nums, int numsSize, int k) {
    int max_sum = 0;
    int left = 0;
    int right = k;

    // if k == numSize
    for (int i = 0; i < k; i++) {
        max_sum += nums[i];
    }

    // sum has been calculated for first sub array
    // of length k.
    int running_sum = max_sum;

    while (right < numsSize) {
        running_sum -= nums[left++];
        running_sum += nums[right++];
        if (running_sum > max_sum) {
            max_sum = running_sum;
        }
    }

    return ((double)max_sum / (double)k);
}

/*
 * Define the Problem: Given an array of ints, size of array,
 * and number of allowed flips, find the longest subarray of 1's
 *
 * Constraints:
 *  1<=numsSize<=10^5
 *  nums[i] = 0 or 1;
 *  0 <= k <= numsSize;
 *
 * Inputs: array of ints, array length as int, k number of flips
 * A flip is the number of flips from 0 to in a given binary array.
 *
 * Outputs: int representing length of longest contiguous subarray
 * with the allowed flips (k)
 *
 * Edge Cases:
 *  k = 0;
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 *
 * [0,0,0]0,0,1,0,1,1,1,1,0,1], k = 0
 *
 */

int longestOnes(int *nums, int numsSize, int k) {
    int longestSize = nums[0];
    int left = 0, right;
    int flips = 0;

    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            k--;
        }
        if (k < 0) {
            k += 1 - nums[left];
            left++;
        }
    }
    return right - left;
}

/*
 * Define the Problem: Given an array nums,
 * we define a running sum of an array as
 * runnginsum[i] = sum(num[0]..sum[i]);
 *
 * returning sum of sums
 *
 * Constraints:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 *
 * Inputs: int array[], int sz, return ptr
 *
 * Outputs: int array[] == running sum per index
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int *runningSum(int *nums, int numsSize, int *returnSize) {

    *returnSize = numsSize;
    int *arr = (int *)malloc(sizeof(int) * *returnSize);

    arr[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        arr[i] = arr[i - 1] + nums[i];
    }

    return arr;
}

/*
 * Define the Problem:
 * Given an array of ints, you start with an initial positive value.
 * (startValue) in each iteration, calculate the step by step sum of startValue
 * plus elements in nums from left to right.
 *
 * return the minimum positive value of startValue such that the step by step
 * sum is never less than 1
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 *
 * Inputs: Array of Int's
 *
 * Outputs: Int (min positive value of start value)
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int minStartValue(int *nums, int numsSize) {
    int max_neg_sum = 0;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < max_neg_sum) {
            max_neg_sum = sum;
        }
    }

    return (max_neg_sum * -1) + 1;
}

/*
 * Define the Problem:
 * k-radius avg of a subarray of nums centered at a given index (i)
 * The radius is index range (i-k) to (i+k) inclusive
 *
 * Goal is to build an array avgs of length 'n' where avgs[i] is the k k-radius
 * average for the subarray centered at index i;
 *
 * The average of x is the sum of k radius(i) divided by x, using int division.
 * Not really a problem for c.
 *
 * Constraints:
 * n == nums.length
 * 1 <= n <= 10^5
 * 0 <= nums[i], k <= 10^5
 *
 * Inputs: int array, int array_sz, int k,  int return_sz
 *
 * Outputs: int array, with outputs of the averages at the given index.
 *
 * Edge Cases: if there are less than k elements to the left or right of
 * a given index (i) return -1
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int *getAverages(int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize;
    int *result = (int *)malloc(sizeof(int) * *returnSize);
    int *sums = (int *)malloc(sizeof(int) * *returnSize);

    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        sums[i] = sum;
    }

    for (int i = 0; i < numsSize; i++) {
        if (i >= k && i + k < numsSize) {
            if (i - k - 1 < 0) {
                result[i] = sums[i + k] / (k + k + 1);
            } else {
                result[i] = (sums[i + k] - sums[i - k - 1]) / (k + k + 1);
            }
        } else {
            result[i] = -1;
        }
    }
    free(sums);
    return result;
}
