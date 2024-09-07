#include <stdio.h>
#include <stdlib.h>

#include "trees-graphs.h"

struct TreeNode *create_node_x(int val, struct TreeNode *left,
                               struct TreeNode *right) {
    struct TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = left;
    n->right = right;
    return n;
}

int main(int argc, char *argv[]) {

    struct TreeNode *four = create_node_x(4, NULL, NULL);
    struct TreeNode *three = create_node_x(3, NULL, NULL);
    struct TreeNode *two = create_node_x(2, three, four);
    struct TreeNode *one = create_node_x(1, NULL, NULL);
    struct TreeNode *root = create_node_x(0, one, two);

    int return_sz = 0;
    int *return_columnSizes = NULL;

    int **actual = zigzagLevelOrder(root, &return_sz, &return_columnSizes);

    printf("expected: 0, 2, 1, 3, 4, \n");
    printf("actual  : ");

    for (int i = 0; i < return_sz; i++) {
        for (int j = 0; j < return_columnSizes[i]; j++) {
            printf("%d, ", actual[i][j]);
        }
    }
    printf("\n");

    return 0;
}
