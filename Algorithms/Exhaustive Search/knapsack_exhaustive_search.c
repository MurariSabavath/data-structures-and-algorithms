#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Knapsack {
    int weight, value;
};

void main() {
    int n, i, j, maxWeight;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter max weight : ");
    scanf("%d", &maxWeight);
    struct Knapsack a[n];
    for(i=0; i<n; i++) {
        printf("weight value : ");
        scanf("%d %d", &a[i].weight, &a[i].value);
    }
    int total = pow(2, n), profit = 0;

    for(i=1; i<total; i++) {
        int cost = 0, capacity = 0;
        for(j=0; j<n; j++) {
            int k = 1 << j;
            if(k & i && (capacity + a[j].weight <= maxWeight)) {
                cost += a[j].value;
                capacity += a[j].weight;
            }
        }
        if(profit < cost) profit = cost;
    }
    printf("Profit : %d", profit);
}

