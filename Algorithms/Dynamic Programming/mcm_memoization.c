#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dp[100][100];

void initialize() {
    int i, j;
    for(i=0; i<100; i++) {
        for(j=0; j<100; j++) {
            dp[i][j] = -1;
        }
    }
}

int min(int a, int b) { return a < b ? a : b; }

int matrixChainMultiplication(int a[], int i, int j) {
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int k, cost;
    dp[i][j] = INT_MAX;
    for(k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], matrixChainMultiplication(a, i, k) + matrixChainMultiplication(a, k+1, j) + a[i-1] * a[k] * a[j]);
    }
    return dp[i][j];
}

void main() {
    initialize();
    int a[] = {1, 2, 3, 4, 3};
    int n = sizeof(a)/sizeof(a[0]);

    printf("%d", matrixChainMultiplication(a, 1, n-1));
}
