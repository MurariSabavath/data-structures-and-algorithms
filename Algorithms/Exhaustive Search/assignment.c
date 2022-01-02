#include <stdio.h>
#include <limits.h>

#define N 4

int profit = INT_MAX;

void swap(int a[], int i, int j) {
    a[i] = a[i] + a[j] - (a[j] = a[i]);
}

void assignment(int a[], int start, int end, int costMatrix[][end+1]) {
    int i;
    if(start == end) {
        int sum = 0, j = 0;
        for(i=0; i<=end; i++) {
            sum += costMatrix[a[i]][j++];
        }
        if(profit > sum) profit = sum;
    } else {
        for(i=start; i<=end; i++) {
            swap(a, start, i);
            assignment(a, start+1, end, costMatrix);
            swap(a, start, i);
        }
    }
}

void main() {
    int n = 4;
    int costmatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int a[n], i;

    for(i=0; i<n; i++) a[i] = i;
    assignment(a, 0, n-1, costmatrix);

    printf("%d", profit);
}
