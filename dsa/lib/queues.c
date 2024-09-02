#include "queues.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_moving_avg(MovingAverage *o) {
    printf("Moving Average\n");
    printf("Size  :\t%d\n", o->size);
    printf("Index :\t%d\n", o->idx);
    printf("Sum   :\t%d\n", o->sum);
    printf("Values:\t");
    for (int i = 0; i < o->size; ++i) {
        printf("%d ", o->values[i]);
    }
    printf("\n");
}

MovingAverage *movingAverageCreate(int size) {
    MovingAverage *MA = (MovingAverage *)malloc(sizeof(MovingAverage));
    MA->size = size;
    MA->idx = 0;
    MA->sum = 0;
    MA->values = (int *)malloc(size * sizeof(int));
    return MA;
}

double movingAverageNext(MovingAverage *obj, int val) {

    if (obj->idx == obj->size) {
        int fifo = obj->values[obj->idx - 1];
        printf("fifo: %d\n", fifo);
        obj->sum -= fifo;
    }

    obj->sum += val;
    if (obj->idx < obj->size) {
        ++obj->idx;
    }
    // shift all values to the right
    for (int i = obj->idx - 2; i > -1; --i) {
        obj->values[i + 1] = obj->values[i];
    }

    obj->values[0] = val;

    return (double)obj->sum / (double)obj->idx;
}

void movingAverageFree(MovingAverage *obj) {
    free(obj->values);
    free(obj);
    return;
}

/*
 * Define the Problem:
 * Next greater element of some element x is an array. This is the
 * first greate element that is to the right of x in the same array.
 *
 * You are give two distinct 0-based arrays: nums1,nums2 where
 * nums1 is a subset of nums2.
 *
 * Find the index `j` such that nums1[i] == nums2[j] and determine the
 * next greater element of nums2[j] in nums 2. if no greater element,
 * return -1.
 *
 * Return an array `ans` of length nums1.length such that ans[i] is the next
 * greater element described above.
 *
 * Constraints:
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2. (subset)
 *
 * Inputs: two int arrays
 *
 * Outputs: one int array
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int map[10001];
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize) {
    int *returnArray;
    int *stack;
    int sp = 0;

    stack = malloc(sizeof(int) * nums2Size);
    if (stack == NULL) {
        free(stack);
        return NULL;
    }

    returnArray = malloc(sizeof(int) * nums1Size);
    if (returnArray == NULL) {
        free(stack);
        return NULL;
    }

    for (int i = nums2Size - 1; i >= 0; i--) {
        while (sp > 0 && stack[sp - 1] < nums2[i]) {
            sp--;
        }

        if (sp == 0) {
            map[nums2[i]] = -1;
            stack[sp++] = nums2[i];
            continue;
        } else {
            map[nums2[i]] = stack[sp - 1];
            stack[sp++] = nums2[i];
        }
    }

    for (int i = 0; i < nums1Size; i++) {
        returnArray[i] = map[nums1[i]];
    }

    if (returnSize != NULL) {
        *returnSize = nums1Size;
    }

    free(stack);

    return returnArray;
}
