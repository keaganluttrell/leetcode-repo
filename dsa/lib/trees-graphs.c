#include "trees-graphs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

BTNode *create_BTNode(int val) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void dfs(BTNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->val);
    dfs(node->left);
    dfs(node->right);
}

void bfs(BTNode *root) {
    if (root == NULL) {
        return;
    }

    int maxSize = 10;
    BTNode **queue = malloc(maxSize * sizeof(BTNode *));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        BTNode *current = queue[front++];
        printf("%d ", current->val);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

void fill_BTNode_tree(BTNode *parent, int *arr, int sz, int index) {
    BTNode *Left;
    BTNode *Right;
    int left = index + index + 1;
    int right = index + index + 2;

    if (left < sz) {
        Left = create_BTNode(arr[left]);
        parent->left = Left;
        fill_BTNode_tree(Left, arr, sz, left);
    }
    if (right < sz) {
        Right = create_BTNode(arr[right]);
        parent->right = Right;
        fill_BTNode_tree(Right, arr, sz, right);
    }
}

BTNode *create_BTNode_from_array(int *arr, int sz) {
    if (sz == 0) {
        return NULL;
    }
    BTNode *head = create_BTNode(arr[0]);

    fill_BTNode_tree(head, arr, sz, 0);

    return head;
}

void dfs_free(BTNode *node) {
    if (node == NULL) {
        return;
    }
    dfs_free(node->left);
    dfs_free(node->right);
    printf("free %d\n", node->val);
    free(node);
}

void free_BTNode(BTNode *node) { dfs_free(node); }
/*
 * Define the Problem:
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 *
 * Constraints:
 * Range of Nodes = [0, 105]
 * -1000 <= Node.val <= 1000
 *
 * Inputs: Binary Tree
 *
 * Outputs: Int
 *
 * Edge Cases: Empty Tree
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int minDepth(struct TreeNode *node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    int left = minDepth(node->left);
    int right = minDepth(node->right);

    if (left == 0) {
        return right + 1;
    } else if (right == 0) {
        return left + 1;
    } else if (left < right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

/*
 * Define the Problem:
 *  Given the root of a binary tree, find the maximum value v
 *  for which there exist different nodes a and b where
 *  v = |a.val - b.val| and a is an ancestor of b.
 *
 *  A node a is an ancestor of b if either: any child of a is
 *  equal to b or any child of a is an ancestor of b.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 5000]
 * 0 <= Node.val <= 105
 *
 * Inputs: Binary Tree
 *
 * Outputs: Int
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

//     0
//    / \
//   1   2
//  / \ / \
// 3  4 5  6
//
int mad_worker(struct TreeNode *root, int min_val, int max_val) {
    if (root == NULL) {
        return max_val - min_val;
    }

    if (root->val < min_val) {
        min_val = root->val;
    }
    if (root->val > max_val) {
        max_val = root->val;
    }

    int l_maxdiff = mad_worker(root->left, min_val, max_val);
    int r_maxdiff = mad_worker(root->right, min_val, max_val);

    return l_maxdiff > r_maxdiff ? l_maxdiff : r_maxdiff;
}

int maxAncestorDiff(struct TreeNode *root) {
    return mad_worker(root, root->val, root->val);
}
