#include<stdio.h>
#include<math.h>
#include<limits.h>

int dp[100][100];

void initialize() {
    int i, j;
    for(i=0; i<100; i++) {
        for(j=0; j<100; j++) {
            dp[i][j] = -1;
        }
    }
}

int nck(int n, int k) {
    if(dp[n][k] != -1) return dp[n][k];

    if(k == 0 || k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }
    dp[n][k] = nck(n-1, k-1) + nck(n-1, k);

    return dp[n][k];
}

void main() {
    int n = 5, k = 4;
    initialize();
    printf("%d", nck(n, k));
}
