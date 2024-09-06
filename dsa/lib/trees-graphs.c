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

// DFS ////////////////////////////////////////

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

/*
 * Define the Problem:
 * Given the root of a binary tree, return the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path between
 * any two nodes in a tree. This path may or may not pass through the root. The
 * length of a path between two nodes is represented by the number of edges
 * between them.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 *
 * Inputs:
 *
 * Outputs:
 *
 * Edge Cases:
 *
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */

int diameter_worker(struct TreeNode *root, int *max) {
    if (root == NULL) {
        return 0;
    }

    int left, right, total;
    left = diameter_worker(root->left, max);
    right = diameter_worker(root->right, max);
    total = left + right;

    if (total > *max) {
        *max = total;
    }

    return right > left ? right + 1 : left + 1;
}

int diameterOfBinaryTree(struct TreeNode *root) {
    int max = 0;
    diameter_worker(root, &max);
    return max;
}

// BFS ////////////////////////////////////////////////
/*
 * Define the Problem:
 * Given the root of a binary tree, return the sum of values of
 * its deepest leaves.
 *
 * Constraints:
 * Range [1,10^4]
 * 1 <= Node.val <= 100
 *
 * Inputs: tree node
 *
 * Outputs: int
 *
 * Edge Cases:
 *:warn("%s");
 * Come up with a solution in pseudocode
 * Solve the problem
 * Analyze Performance
 * Refactor to Optimal Solution
 */
int deepestLeavesSum2(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    struct TreeNode *q[10000];

    int front = 0;
    int rear = 0;

    q[rear++] = root;
    int curr_lvl_sum = 0;

    while (front < rear) {
        int lvl_sz = rear - front;
        curr_lvl_sum = 0;

        for (int i = 0; i < lvl_sz; i++) {
            struct TreeNode *curr = q[front++];

            curr_lvl_sum += curr->val;

            if (curr->left != NULL) {
                q[rear++] = curr->left;
            }

            if (curr->right != NULL) {
                q[rear++] = curr->right;
            }
        }
    }

    return curr_lvl_sum;
}

void dfs_worker(struct TreeNode *root, int depth, int *max_depth, int *sum) {
    if (root == NULL) {
        return;
    }

    if (depth == *max_depth) {
        *sum += root->val;

    } else if (depth > *max_depth) {
        *sum = root->val;
        *max_depth = depth;
    }

    dfs_worker(root->left, depth + 1, max_depth, sum);
    dfs_worker(root->right, depth + 1, max_depth, sum);
}

int deepestLeavesSum(struct TreeNode *root) {
    int max_depth = 0;
    int sum = 0;
    dfs_worker(root, 0, &max_depth, &sum);
    return sum;
}
