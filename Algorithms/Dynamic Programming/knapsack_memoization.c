#include <stdio.h>
#include <stdlib.h>

int dp[200][200];

void initialize() {
    int i, j;
    for(i=0; i<201; i++) {
        for(j=0; j<201; j++) dp[i][j] = -1;
    }
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int knapsack(int wt[], int val[], int n, int W) {
    if(W == 0 || n == 0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(wt[n-1] <= W) {
        dp[n][W] =  max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
    }
    else {
        dp[n][W] = knapsack(wt, val, n-1, W);
    }
    return dp[n][W];
}

void main() {
    initialize();
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapsack(wt, val, n, W));
}
