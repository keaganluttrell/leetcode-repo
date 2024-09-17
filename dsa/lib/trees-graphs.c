#include "trees-graphs.h"
#include <cstdio>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Create a zig zag search function
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

#define ZIGZAG_MAX 2001

int **zigzagLevelOrder2(struct TreeNode *root, int *returnSize,
                        int **returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode *q[ZIGZAG_MAX];
    int front = 0, rear = 0;
    bool flip = false;

    q[rear++] = root;

    int **result = (int **)malloc(ZIGZAG_MAX * sizeof(int *));
    *returnColumnSizes = (int *)malloc(ZIGZAG_MAX * sizeof(int));
    *returnSize = 0;

    while (front < rear) {
        int lvl_size = rear - front;
        result[*returnSize] = (int *)malloc(lvl_size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = lvl_size;

        if (flip) {
            for (int i = 0; i < lvl_size; i++) {
                result[*returnSize][i] = q[front + lvl_size - 1 - i]->val;
            }
        } else {
            for (int i = 0; i < lvl_size; i++) {
                result[*returnSize][i] = q[front + i]->val;
            }
        }

        for (int i = 0; i < lvl_size; i++) {
            struct TreeNode *curr = q[front++];
            if (curr->left)
                q[rear++] = curr->left;
            if (curr->right)
                q[rear++] = curr->right;
        }

        flip = !flip; // Toggle flip for zigzag behavior
        (*returnSize)++;
    }

    return result;
}

typedef struct {
    struct TreeNode **data;
    int front, rear, capacity;
} Deque;

Deque *create_deque(int capacity) {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->data =
        (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    deque->front = capacity / 2; // Start front in the middle
    deque->rear = capacity / 2;
    deque->capacity = capacity;
    return deque;
}

bool is_empty(Deque *deque) { return deque->front == deque->rear; }

void enqueue_front(Deque *deque, struct TreeNode *node) {
    deque->data[--deque->front] = node;
}

void enqueue_rear(Deque *deque, struct TreeNode *node) {
    deque->data[deque->rear++] = node;
}

struct TreeNode *dequeue_front(Deque *deque) {
    return deque->data[deque->front++];
}

struct TreeNode *dequeue_rear(Deque *deque) {
    return deque->data[--deque->rear];
}

void free_deque(Deque *deque) {
    free(deque->data);
    free(deque);
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    Deque *deque = create_deque(ZIGZAG_MAX);
    enqueue_rear(deque, root);

    int **result = (int **)malloc(ZIGZAG_MAX * sizeof(int *));
    *returnColumnSizes = (int *)malloc(ZIGZAG_MAX * sizeof(int));
    *returnSize = 0;
    bool left_to_right = true;

    while (!is_empty(deque)) {
        int level_size = deque->rear - deque->front;
        result[*returnSize] = (int *)malloc(level_size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = level_size;

        for (int i = 0; i < level_size; ++i) {
            struct TreeNode *node;
            if (left_to_right) {
                node = dequeue_front(deque);
            } else {
                node = dequeue_rear(deque);
            }

            result[*returnSize][i] = node->val;

            if (left_to_right) {
                if (node->left)
                    enqueue_rear(deque, node->left);
                if (node->right)
                    enqueue_rear(deque, node->right);
            } else {
                if (node->right)
                    enqueue_front(deque, node->right);
                if (node->left)
                    enqueue_front(deque, node->left);
            }
        }

        left_to_right = !left_to_right; // Switch direction for next level
        (*returnSize)++;
    }

    free_deque(deque);
    return result;
}

/*
 * Define the Problem: Inser into BST
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

struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {
    if (root == NULL) {
        struct TreeNode *node = calloc(1, sizeof(struct TreeNode));
        node->left = NULL;
        node->right = NULL;
        node->val = val;
        root = node;
    } else if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void dfs_closest(struct TreeNode *node, double target, int *closest,
                 double *smallest_diff) {

    if (node == NULL) {
        return;
    }

    double curr_diff = fabs(node->val - target);
    if (curr_diff < *smallest_diff) {
        *smallest_diff = curr_diff;
        *closest = node->val;
    } else if (curr_diff == *smallest_diff) {
        if (node->val < *closest) {
            *closest = node->val;
        }
    }
    if (target < node->val) {
        dfs_closest(node->left, target, closest, smallest_diff);
    } else {
        dfs_closest(node->right, target, closest, smallest_diff);
    }
}

int closestValue(struct TreeNode *root, double target) {
    int closest = INT_MAX;
    double smallest_diff = INT_MAX;
    dfs_closest(root, target, &closest, &smallest_diff);
    return closest;
}

/*
 * Constraints:
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 20
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * There are no duplicate edges.
 * There are no self edges.
 *
 * Input:
 * n: number of edges
 * **edges: int edges[edgesSize][edgesColSize]
 * int: source node
 * destination: destination node
 */

// Find the root of a node with path compression
int find(int *parent, int node) {
    if (parent[node] != node) {
        parent[node] = find(parent, parent[node]); // Path compression
    }
    return parent[node];
}

// Union two nodes by connecting their roots
void unionNodes(int *parent, int *rank, int node1, int node2) {
    int root1 = find(parent, node1);
    int root2 = find(parent, node2);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

// Main function to check if a valid path exists using Union-Find
bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source,
               int destination) {
    // Initialize the parent array and rank array for Union-Find
    int *parent = (int *)malloc(n * sizeof(int));
    int *rank = (int *)calloc(n, sizeof(int));

    // Each node is its own parent initially
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Union the nodes based on the edges
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        unionNodes(parent, rank, x, y);
    }

    // Check if the source and destination are in the same connected component
    bool result = find(parent, source) == find(parent, destination);

    // Free the allocated memory
    free(parent);
    free(rank);

    return result;
}

struct Node *new_node(int val) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = val;
    n->capacity = 10; // Initial capacity for neighbors
    n->neighbors = malloc(n->capacity * sizeof(int));
    n->i = 0;
    return n;
}

void add_neighbor(struct Node *x, struct Node *y) {
    if (x == NULL || y == NULL) {
        printf("add_neighbor: x or y is null\n");
        exit(EXIT_FAILURE);
    }

    // Resize if necessary
    if (x->i >= x->capacity) {
        x->capacity *= 2;
        x->neighbors = realloc(x->neighbors, x->capacity * sizeof(int));
    }

    x->neighbors[x->i++] = y->val;

    if (y->i >= y->capacity) {
        y->capacity *= 2;
        y->neighbors = realloc(y->neighbors, y->capacity * sizeof(int));
    }

    y->neighbors[y->i++] = x->val;
}

void traverse_graph(struct Node *node, struct Node **graph, bool *seen) {
    if (node == NULL || seen[node->val]) {
        return;
    }

    seen[node->val] = true;

    for (int n = 0; n < node->i; n++) {
        traverse_graph(graph[node->neighbors[n]], graph, seen);
    }
}

int countComponents_old(int n, int **edges, int edgesSize, int *edgesColSize) {
    struct Node *graph[GRAPH_MAX] = {NULL};
    int i;
    int count = 0;

    bool *seen = calloc(GRAPH_MAX, sizeof(bool));

    // build out the graph
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0];
        int y = edges[i][1];

        if (graph[x] == NULL) {
            graph[x] = new_node(x);
        }
        if (graph[y] == NULL) {
            graph[y] = new_node(y);
        }

        add_neighbor(graph[x], graph[y]);
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            if (graph[i] != NULL) {
                traverse_graph(graph[i], graph, seen);
            }
            count++;
        }
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        if (graph[i] != NULL) {
            free(graph[i]->neighbors);
            free(graph[i]);
        }
    }
    free(seen);

    return count;
}

// Union two nodes by rank
void union_nodes(int *parent, int *rank, int node1, int node2) {
    int root1 = find(parent, node1);
    int root2 = find(parent, node2);

    if (root1 != root2) {
        // Union by rank
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

// Main function to count components
int countComponents(int n, int **edges, int edgesSize, int *edgesColSize) {
    int *parent = malloc(n * sizeof(int));
    int *rank = malloc(n * sizeof(int));
    int components = n;

    // Initialize parent and rank arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Initially, each node is its own parent
        rank[i] = 0;   // Initially, the rank of each node is 0
    }

    // Process all edges
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0];
        int y = edges[i][1];

        // If the nodes are in different components, union them
        if (find(parent, x) != find(parent, y)) {
            union_nodes(parent, rank, x, y);
            components--; // Reduce the number of components
        }
    }

    // Clean up
    free(parent);
    free(rank);

    return components;
}

/* Constraints
 * m == grid.length    => gridSize
 * n == grid[i].length => gridColSize
 * 1 <= m, n <= 50     => MAX: 50X50 Matrix
 * Matrix is Not Jagged
 * grid[i][j] is either 0 or 1.
 */
bool in_bounds(int gridSize, int *gridColSize, int i, int j) {
    return i >= 0 && i < gridSize && j >= 0 && j < *gridColSize;
}

void chart(int **grid, int gridSize, int *gridColSize, int *count, int i,
           int j) {
    // act on current index
    (*count)++;
    grid[i][j] = 2; // mark seen

    // chart up
    if (in_bounds(gridSize, gridColSize, i - 1, j) && grid[i - 1][j] == 1) {
        chart(grid, gridSize, gridColSize, count, i - 1, j);
    }

    // chart down
    if (in_bounds(gridSize, gridColSize, i + 1, j) && grid[i + 1][j] == 1) {
        chart(grid, gridSize, gridColSize, count, i + 1, j);
    }

    // chart left
    if (in_bounds(gridSize, gridColSize, i, j - 1) && grid[i][j - 1] == 1) {
        chart(grid, gridSize, gridColSize, count, i, j - 1);
    }

    // chart right
    if (in_bounds(gridSize, gridColSize, i, j + 1) && grid[i][j + 1] == 1) {
        chart(grid, gridSize, gridColSize, count, i, j + 1);
    }
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize) {
    int max_area = 0;
    int count;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] != 1) {
                continue;
            }

            count = 0;
            chart(grid, gridSize, gridColSize, &count, i, j);

            if (count > max_area) {
                max_area = count;
            }
        }
    }

    return max_area;
}

int reachableNodes(int n, int **edges, int edgesSize, int *edgesColSize,
                   int *restricted, int restrictedSize) {
    int *parent = malloc(n * sizeof(int));
    int *rank = malloc(n * sizeof(int));
    int *restrictedSet = malloc(n * sizeof(int));

    // Initialize DSU and restricted nodes set
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        restrictedSet[i] = 0; // False by default
    }

    // Mark restricted nodes
    for (int i = 0; i < restrictedSize; ++i) {
        restrictedSet[restricted[i]] = 1; // True if restricted
    }

    // Union nodes that are not restricted
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Only union if neither node is restricted
        if (!restrictedSet[u] && !restrictedSet[v]) {
            union_nodes(parent, rank, u, v);
        }
    }

    // Count the number of reachable nodes from node 0
    int rootZero = find(parent, 0);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!restrictedSet[i] && find(parent, i) == rootZero) {
            count++;
        }
    }

    free(parent);
    free(rank);
    free(restrictedSet);

    return count;
}

Pos_Deque *createDeque() {
    Pos_Deque *dq = (Pos_Deque *)malloc(sizeof(Pos_Deque));
    dq->front = dq->rear = 0;
    dq->size = 0;
    return dq;
}

void enqueue(Pos_Deque *dq, int row, int col) {
    if (dq->size == MAX_QUEUE_SIZE) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    dq->data[dq->rear].row = row;
    dq->data[dq->rear].col = col;
    dq->rear = (dq->rear + 1) % MAX_QUEUE_SIZE;
    dq->size++;
}

Position dequeue(Pos_Deque *dq) {
    if (dq->size == 0) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    Position pos = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX_QUEUE_SIZE;
    dq->size--;
    return pos;
}

bool isDequeEmpty(Pos_Deque *dq) { return dq->size == 0; }

void freeDeque(Pos_Deque *dq) { free(dq); }

bool __check_in_bounds(int mazeSize, int *mazeColSize, int row, int col) {
    return row >= 0 && row < mazeSize && col >= 0 && col < *mazeColSize;
}

bool __check_entrance(int *entrance, int row, int col) {
    return row == entrance[0] && col == entrance[1];
}

bool __check_empty_cell(char **maze, int row, int col) {
    return maze[row][col] == '.';
}

bool __check_exit(char **maze, int mazeSize, int *mazeColSize, int row,
                  int col) {
    return (row == 0 || row == mazeSize - 1 || col == 0 ||
            col == *mazeColSize - 1);
}

int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance,
                int entranceSize) {
    Pos_Deque *dq = createDeque();
    int level = 0;

    // Verify entrance is within bounds
    if (!__check_in_bounds(mazeSize, mazeColSize, entrance[0], entrance[1])) {
        printf("Entrance not in maze\n");
        freeDeque(dq);
        return -1;
    }

    // Mark entrance as visited
    maze[entrance[0]][entrance[1]] = '#'; // Assuming '#' denotes visited cells

    // Add entrance to the queue
    enqueue(dq, entrance[0], entrance[1]);

    while (!isDequeEmpty(dq)) {
        int level_sz = dq->size;
        ++level;

        for (int i = 0; i < level_sz; ++i) {
            Position pos = dequeue(dq);
            int row = pos.row;
            int col = pos.col;

            // Check all four directions: up, down, left, right
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int j = 0; j < 4; j++) {
                int newRow = row + directions[j][0];
                int newCol = col + directions[j][1];

                if (__check_in_bounds(mazeSize, mazeColSize, newRow, newCol) &&
                    maze[newRow][newCol] == '.') {

                    if (__check_exit(maze, mazeSize, mazeColSize, newRow,
                                     newCol)) {
                        freeDeque(dq);
                        return level;
                    }
                    // Mark as visited and enqueue
                    maze[newRow][newCol] = '#';
                    enqueue(dq, newRow, newCol);
                }
            }
        }
    }

    freeDeque(dq);
    return -1; // No exit found
}

int snakesAndLadders(int **board, int boardSize, int *boardColSize) {
    if (boardSize != *boardColSize) {
        printf("board is not n x n, rows != cols\n");
        return -1;
    }

    int arr_sz = (boardSize * boardSize) + 1;
    int *arr = malloc(sizeof(int) * arr_sz);
    if (arr == NULL) {
        perror("failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int i, j, a, f;
    a = 1;
    f = -1;

    for (i = boardSize - 1; i >= 0; --i) {
        if (++f % 2 == 0) {
            for (j = 0; j < boardSize; ++j) {
                arr[a++] = (board[i][j] == -1) ? a : board[i][j];
            }
        } else {
            for (j = boardSize - 1; j >= 0; --j) {
                arr[a++] = (board[i][j] == -1) ? a : board[i][j];
            }
        }
    }

    int *q = malloc(sizeof(int) * arr_sz);
    int *seen = malloc(sizeof(int) * arr_sz);
    for (i = 0; i < arr_sz; ++i) {
        seen[i] = 0;
    }

    seen[1] = 1;
    int front = 0;
    int back = 0;
    int levels = 0;

    q[front++] = 1;

    while (front > back) {
        int level_size = front - back;
        for (i = 0; i < level_size; ++i) {
            int curr = q[back++];
            for (j = 1; j <= 6 && curr + j < arr_sz; ++j) {
                int next = arr[curr + j];
                if (next == arr_sz - 1) {
                    free(arr);
                    free(q);
                    free(seen);
                    return levels + 1;
                }
                if (!seen[next]) {
                    seen[next] = 1;
                    q[front++] = next;
                }
            }
        }
        levels++;
    }

    free(arr);
    free(q);
    free(seen);
    return -1;
}

bool __is_neighbor(char *a, char *b, int size) {
    int ct = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            ct++;
        }
    }
    return ct == 1;
}

int __find_index(char **bank, int bankSize, char *gene) {
    for (int i = 0; i < bankSize; ++i) {
        if (strcmp(gene, bank[i]) == 0) {
            return i;
        }
    }
    return -1;
}

#define GENE_LENGTH 8
int minMutation(char *startGene, char *endGene, char **bank, int bankSize) {
    int i, j, neighbors_size;
    bool startGeneFound = false;
    neighbors_size = bankSize + 1;
    for (i = 0; i < bankSize; ++i) {
        if (strcmp(startGene, bank[i]) == 0) {
            startGeneFound = true;
            break;
        }
    }

    if (startGeneFound) {
        neighbors_size = bankSize;
    }

    char ***neighbors = malloc(sizeof(char **) * neighbors_size);
    int *sizes = malloc(sizeof(int) * neighbors_size);
    if (neighbors == NULL || sizes == NULL) {
        printf("failed to allocate memory to neighbors or sizes arr\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < neighbors_size; ++i) {
        sizes[i] = 0;
        neighbors[i] = malloc(sizeof(char *) * bankSize);
        if (neighbors[i] == NULL) {
            printf("failed to allocate memory to neihbors arr[%d]\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < bankSize; ++i) {

        if (!startGeneFound) {
            if (__is_neighbor(startGene, bank[i], GENE_LENGTH)) {
                neighbors[bankSize][sizes[bankSize]++] = strdup(bank[i]);
            }
        }

        for (j = 0; j < bankSize; ++j) {
            if (i != j && __is_neighbor(bank[i], bank[j], GENE_LENGTH)) {
                neighbors[i][sizes[i]++] = strdup(bank[j]);
            }
        }
    }

    int *q = malloc(sizeof(int) * neighbors_size * neighbors_size + 1);
    bool *visited = calloc(neighbors_size, sizeof(bool));
    int front = 0, back = 0, lvl = 0, lvl_size;

    int start_index =
        startGeneFound ? __find_index(bank, bankSize, startGene) : bankSize;

    q[front++] = start_index;
    visited[start_index] = true;

    while (front > back) {
        lvl_size = front - back;
        for (i = 0; i < lvl_size; ++i) {

            int idx = q[back++];
            char *curr_gene = idx == bankSize ? startGene : bank[idx];

            if (strcmp(curr_gene, endGene) == 0) {
                free(q);
                free(visited);
                for (i = 0; i < neighbors_size; ++i) {
                    free(neighbors[i]);
                }
                free(neighbors);
                free(sizes);
                return lvl;
            }

            char **curr_neighbors = neighbors[idx];
            for (j = 0; j < sizes[idx]; ++j) {
                int neighbor_idx =
                    __find_index(bank, bankSize, curr_neighbors[j]);
                if (neighbor_idx != -1 && !visited[neighbor_idx]) {
                    visited[neighbor_idx] = true;
                    q[front++] = neighbor_idx;
                }
            }
        }
        ++lvl;
    }

    free(q);
    free(visited);
    for (i = 0; i < bankSize; ++i) {
        free(neighbors[i]);
    }
    free(neighbors);
    free(sizes);

    return -1;
}

// Given an array of non-negative integers arr, you are initially positioned
// at start index of the array. When you are at index i, you can jump to
// i + arr[i] or i - arr[i], check if you can reach any index with value 0.
//
// Notice that you can not jump outside of the array at any time.

bool canReach(int *arr, int arrSize, int start) {
    bool *visited = (bool *)malloc(sizeof(bool) * arrSize);
    if (visited == NULL) {
        perror("failed to allocate memory for visited array");
        exit(EXIT_FAILURE);
    }

    memset(visited, false, arrSize * sizeof(bool));

    int *queue = (int *)malloc(sizeof(int) * arrSize);
    if (queue == NULL) {
        perror("failed to allocate memory for BFS queue");
        exit(EXIT_FAILURE);
    }

    int front = 0, back = 0;
    queue[back++] = start;
    visited[start] = true;

    while (front < back) {
        int curr = queue[front++];

        if (arr[curr] == 0) {
            free(visited);
            free(queue);
            return true;
        }

        int r = curr + arr[curr];
        int l = curr - arr[curr];

        if (r < arrSize && !visited[r]) {
            queue[back++] = r;
            visited[r] = true;
        }

        if (l >= 0 && !visited[l]) {
            queue[back++] = l;
            visited[l] = true;
        }
    }

    free(visited);
    free(queue);
    return false;
}
