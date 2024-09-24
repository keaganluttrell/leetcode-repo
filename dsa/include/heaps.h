#ifndef HEAPS_H
#define HEAPS_H

int minStoneSum(int *piles, int pilesSize, int k);
int connectSticks(int *sticks, int sticksSize);
int findKthLargest(int *nums, int numsSize, int k);
int **kClosest(int **points, int pointsSize, int *pointsColSize, int k,
               int *returnSize, int **returnColumnSizes);

typedef struct {
    int *heap;
    int len;
    int size;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int n);

int kthLargestAdd(KthLargest *s, int val);

void kthLargestFree(KthLargest *s);

void kthLargestPop(KthLargest *s);

int kthLargestPeek(KthLargest *s);

void kthLargestHeapify(KthLargest *s, int index);

#endif
