#ifndef BACKTRACKING_H
#define BACKTRACKING_H

int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize,
                           int *returnSize, int **returnColumnSizes);
char **letterCombinations(char *digits, int *returnSize);
char **generateParenthesis(int n, int *returnSize);
#endif
