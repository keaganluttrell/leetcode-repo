
#ifndef HASHMAPS_H
#define HASHMAPS_H
#include <stdbool.h>
bool checkIfPangram(char *sentence);
int missingNumber(int *nums, int numsSize);
int countElements(int *arr, int arrSize);
int **findWinners(int matches[][2], int matchesSize, int *matchesColSize,
                  int *returnSize, int **returnColumnSizes);
int largestUniqueNumber(int *nums, int numsSize);
int maxNumberOfBalloons(char *text);
int findMaxLength(int *nums, int numsSize);
#endif
