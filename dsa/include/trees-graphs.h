
#ifndef TREES_GRAPHS_H
#define TREES_GRAPHS_H

typedef struct BTNode {
    int val;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

BTNode *create_BTNode(int val);
BTNode *create_BTNode_from_array(int *arr, int sz);
int max_depth(BTNode *node);
void free_BTNode(BTNode *node);
void dfs(BTNode *node);
void bfs(BTNode *node);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root);
int maxAncestorDiff(struct TreeNode *root);
#endif
