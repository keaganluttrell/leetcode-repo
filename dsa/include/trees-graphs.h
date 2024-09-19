
#ifndef TREES_GRAPHS_H
#define TREES_GRAPHS_H
#include <stdbool.h>

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
int diameterOfBinaryTree(struct TreeNode *root);
int deepestLeavesSum(struct TreeNode *root);
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes);
struct TreeNode *insertIntoBST(struct TreeNode *root, int val);

// Graphs
bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source,
               int destination);

#define GRAPH_MAX 5001

struct Node {
    int val;
    int *neighbors;
    int i;
    int capacity;
};

struct Node *new_node(int val);
void add_neighbor(struct Node *x, struct Node *y);
void traverse_graph(struct Node *node, struct Node **graph, bool *seen);
int countComponents(int n, int **edges, int edgesSize, int *edgesColSize);
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize);
int reachableNodes(int n, int **edges, int edgesSize, int *edgesColSize,
                   int *restricted, int restrictedSize);

// graph bfs
#define MAX_QUEUE_SIZE 1000 // Adjust based on expected maze size

typedef struct {
    int row, col;
} Position;

typedef struct {
    Position data[MAX_QUEUE_SIZE];
    int front, rear, size;
} Pos_Deque;
Pos_Deque *createDeque();
void enqueue(Pos_Deque *dq, int row, int col);
Position dequeue(Pos_Deque *dq);
bool isDequeEmpty(Pos_Deque *dq);
void freeDeque(Pos_Deque *dq);
int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance,
                int entranceSize);
int snakesAndLadders(int **board, int boardSize, int *boardColSize);
int minMutation(char *startGene, char *endGene, char **bank, int bankSize);
bool canReach(int *arr, int arrSize, int start);
int maximumDetonation(int **bombs, int bombsSize, int *bombsColSize);
int ladderLength(char *beginWord, char *endWord, char **wordList,
                 int wordListSize);
#endif
