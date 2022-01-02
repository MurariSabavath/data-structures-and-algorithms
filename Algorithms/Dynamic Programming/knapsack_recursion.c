#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int knapsack(int wt[], int val[], int n, int W) {
    if(n == 0 || W == 0) {
        return 0;
    }

    if(wt[n-1] <= W) {
        return max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
    }else {
        return knapsack(wt, val, n-1, W);
    }

}

void main() {
    int val[] = {3000, 2000, 1500, 100, 50};
    int wt[] = { 10, 5, 5, 10, 5 };
    int W = 20;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapsack(wt, val, n, W));
}
