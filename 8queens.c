#include <stdio.h>
#include <stdbool.h>
#define N 8
int board[N][N] = {0};
int solutionCount = 0;
void printSolution() {
    printf("Solution %d:\n", solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int row, int col) {
    int i, j;
    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    // Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}
bool solveNQueens(int col) {
    if (col >= N) {
        solutionCount++;
        printSolution();
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; 
            res = solveNQueens(col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}
int main() {
    if (solveNQueens(0) == false) {
        printf("No solution exists\n");
    }
    printf("Total solutions: %d\n", solutionCount);
    return 0;
}
