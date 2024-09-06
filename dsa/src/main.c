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
    struct TreeNode *two = create_node_x(2, NULL, NULL);
    struct TreeNode *one = create_node_x(1, three, four);
    struct TreeNode *root = create_node_x(0, one, two);

    int actual = deepestLeavesSum(root);

    printf("answer: %d\n", actual);

    return 0;
}
