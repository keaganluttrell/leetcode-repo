#include <stdio.h>
// #include <stdlib.h>

#include "trees-graphs.h"

int main(int argc, char *argv[]) {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sz = 10;

    BTNode *head = create_BTNode_from_array(arr, sz);
    bfs(head);
    printf("\n");

    free_BTNode(head);

    return 0;
}
