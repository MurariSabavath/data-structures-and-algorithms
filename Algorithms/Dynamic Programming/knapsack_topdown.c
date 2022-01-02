#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

void main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int n = sizeof(val)/sizeof(val[0]);
    int W = 50, i, j; 
    int dp[n+1][W+1];
    
    for(i=0; i<=n; i++) {
        for(j=0; j<=W; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(wt[i-1] <= j) dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    printf("%d", dp[n][W]);
}
