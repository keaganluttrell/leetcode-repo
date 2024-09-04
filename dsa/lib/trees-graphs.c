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
 *
 * Constraints:
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
