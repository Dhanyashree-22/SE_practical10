#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // All queens are placed
    if (col == N) {
        printSolution(board);
        return true;
    }

    // Try placing this queen in all rows one by one
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place queen on the current cell
            board[i][col] = 1;

            // Recur to place rest of the queens
            res = solveNQueensUtil(board, col + 1) || res;

            // If placing queen in the current cell doesn't lead to a solution,
            // then remove queen from the current cell (backtrack)
            board[i][col] = 0;
        }
    }

    return res;
}

// Wrapper function to solve N-Queens problem
void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
        printf("Solution does not exist.\n");
}

int main() {
    solveNQueens();
    return 0;
}
