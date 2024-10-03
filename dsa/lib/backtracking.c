#include "backtracking.h"
#include <stdlib.h>

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
