#include <stdio.h>
#include <stdbool.h>

// Maximum size of the chess board
#define MAX_SIZE 100

// Chess board
int board[MAX_SIZE][MAX_SIZE];

// Check if a queen can be placed at position (row, col)
bool isSafe(int row, int col, int n) 
{
    int i, j;

    // Check for row conflicts
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check for upper diagonal conflicts
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check for lower diagonal conflicts
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Place queens on the chess board
bool solveNQueens(int col, int n) {
    // If all queens are placed, return true
    if (col == n) {
        return true;
    }

    int i;

    // Try to place the queen in each row of the current column
    for (i = 0; i < n; i++) {
        // Check if the queen can be placed in this row and column
        if (isSafe(i, col, n)) {
            // Place the queen
            board[i][col] = 1;

            // Recursively place the remaining queens
            if (solveNQueens(col + 1, n)) {
                return true;
            }

            // If the remaining queens cannot be placed, remove the current queen
            board[i][col] = 0;
        }
    }

    // If no queen can be placed in this column, return false
    return false;
}

// Print the solution
void printSolution(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int n;
    
    printf("Enter the size of the chess board: ");
    scanf("%d", &n);
    
    // Initialize the chess board
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    if (solveNQueens(0, n))        
    printSolution(n);
    else
    printf("No solution found.\n");  
}
