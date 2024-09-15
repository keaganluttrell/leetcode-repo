#include <stdio.h>
#include <stdlib.h>

#include "trees-graphs.h"

int main(int argc, char *argv[]) {
    int rowSize = 3, colSize = 3;

    // Allocate memory for the 2D array
    int **board = malloc(rowSize * sizeof(int *));
    for (int i = 0; i < rowSize; ++i) {
        board[i] = malloc(colSize * sizeof(int));
    }

    int init[3][3] = {{-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            board[i][j] = init[i][j];
        }
    }

    int ans = snakesAndLadders(board, rowSize, &colSize);

    printf("answer: %d\n", ans);

    return 0;
}
