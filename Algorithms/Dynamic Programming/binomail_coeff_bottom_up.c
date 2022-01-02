#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a > b) ? b : a; }

int binomailCoeff(int n, int k) {
    int dp[n+1][k+1];
    int i, j;

    for(i=0; i<=n; i++) {
        for(j=0; j<=min(i, k); j++) {
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

void main() {
    int n = 4, k = 2;
    printf("%d", binomailCoeff(n, k));
}
