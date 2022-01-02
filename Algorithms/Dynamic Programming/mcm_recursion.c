#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int a[], int i, int j) {
    int k, min = INT_MAX;
    int cost;

    if(i >= j) return 0;

    for(k=i; k<j; k++) {
        cost = matrixChainMultiplication(a, i, k) + matrixChainMultiplication(a, k+1, j) + a[i-1] * a[k] * a[j];

        if(cost < min) min = cost;
    }
    return min;
}

void main() {
    int a[] = {1, 2, 3, 4, 3};
    int n = sizeof(a)/sizeof(a[0]);

    printf("%d", matrixChainMultiplication(a, 1, n-1));
}
