#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
int searchInsert(int *nums, int numsSize, int target);
int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize,
                   int *returnSize);
int smallestDivisor(int *nums, int numsSize, int threshold);
int maximizeSweetness(int *sweetness, int sweetnessSize, int k);
int splitArray(int *nums, int numsSize, int k);
#endif
