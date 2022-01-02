#include <stdio.h>
#include <stdbool.h>

int board[100][100];

bool isSafe(int n, int row, int col) {
    int i, j;
    for(i=0; i<col; i++) {
        if(board[row][i]) return false;
    }

    for(i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j]) return false;
    }

    for(i=row, j=col; i>=0 && i<n; i++, j--) {
        if(board[i][j]) return false;
    }
    return true;
}

bool nqueens(int n, int col) {
    int i, j, row;
    if(col >= n) {
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(board[i][j]) printf("| ");
                else printf("_ ");
            }
            printf("\n");
        }
        printf("\n");
    }

    for(row=0; row<n; row++) {
        if(isSafe(n, row, col)) {
            board[row][col] = 1;
            nqueens(n, col+1);
            board[row][col] = 0;
        }
    }
}

void main() {
    int n = 4;
    nqueens(n, 0);
}
