#include "backtracking.h"
#include <stdlib.h>
#include <string.h>

void __dfs__(int **graph, int graphSize, int *graphColSize, int node,
             int target, int *path, int pathIndex, int **result,
             int *resultSize, int **returnColumnSizes) {
    path[pathIndex] = node;
    pathIndex++;

    if (node == target) {
        result[*resultSize] = (int *)malloc(sizeof(int) * pathIndex);
        for (int i = 0; i < pathIndex; i++) {
            result[*resultSize][i] = path[i];
        }
        (*returnColumnSizes)[*resultSize] = pathIndex;
        (*resultSize)++;
    } else {
        for (int i = 0; i < graphColSize[node]; i++) {
            int nextNode = graph[node][i];
            __dfs__(graph, graphSize, graphColSize, nextNode, target, path,
                    pathIndex, result, resultSize, returnColumnSizes);
        }
    }
}

int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize,
                           int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int maxPossiblePaths = 10000;
    int **result = (int **)malloc(sizeof(int *) * maxPossiblePaths);
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxPossiblePaths);

    int *path = (int *)malloc(sizeof(int) * graphSize);

    __dfs__(graph, graphSize, graphColSize, 0, graphSize - 1, path, 0, result,
            returnSize, returnColumnSizes);

    free(path);
    return result;
}

int calculateTotalCombinations(const char *digits, char *keypad[]) {
    int size = 1;
    for (const char *ptr = digits; *ptr != '\0'; ++ptr) {
        int key = *ptr - '0';
        size *= strlen(keypad[key]);
    }
    return size;
}

void generateCombinations(char **output, char *digits, char *keypad[],
                          char *currentCombination, int depth, int *index) {
    if (digits[depth] == '\0') {
        output[*index] = strdup(currentCombination);
        (*index)++;
        return;
    }

    int key = digits[depth] - '0';
    for (char *ch = keypad[key]; *ch != '\0'; ++ch) {
        currentCombination[depth] = *ch;
        generateCombinations(output, digits, keypad, currentCombination,
                             depth + 1, index);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    char *keypad[10] = {NULL};
    keypad[0] = "";
    keypad[1] = "";
    keypad[2] = "abc";
    keypad[3] = "def";
    keypad[4] = "ghi";
    keypad[5] = "jkl";
    keypad[6] = "mno";
    keypad[7] = "pqrs";
    keypad[8] = "tuv";
    keypad[9] = "wxyz";

    if (digits == NULL || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = calculateTotalCombinations(digits, keypad);

    char **output = malloc(sizeof(char *) * (*returnSize));
    char currentCombination[strlen(digits) + 1];
    currentCombination[strlen(digits)] = '\0';

    int index = 0;
    generateCombinations(output, digits, keypad, currentCombination, 0, &index);

    return output;
}

char **generateParenthesis(int n, int *returnSize) {}
