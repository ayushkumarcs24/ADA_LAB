#include <stdio.h>

#define N 4

int board[N][N];

// Function to check whether position is safe
int isSafe(int row, int col) {
    int i, j;

    // Check column
    for(i = 0; i < row; i++) {
        if(board[i][col])
            return 0;
    }

    // Check left diagonal
    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j])
            return 0;
    }

    // Check right diagonal
    for(i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if(board[i][j])
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQueens(int row) {

    // All queens placed
    if(row == N)
        return 1;

    int col;

    for(col = 0; col < N; col++) {

        if(isSafe(row, col)) {

            // Place queen
            board[row][col] = 1;

            // Recur for next row
            if(solveNQueens(row + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

// Print solution
void printBoard() {
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {

            if(board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {

    if(solveNQueens(0)) {
        printf("Solution Exists:\n\n");
        printBoard();
    }
    else {
        printf("No Solution Exists");
    }

    return 0;
}
