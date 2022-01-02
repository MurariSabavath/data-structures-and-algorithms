#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct Item {
    int price, weight;
};

void swap(struct Item a[], float b[], int i, int j) {
    b[i] = b[i] + b[j] - (b[j] = b[i]);
    a[i].price = a[i].price + a[j].price - (a[j].price = a[i].price);
    a[i].weight = a[i].weight + a[j].weight - (a[j].weight = a[i].weight);
}

int partition(float b[], int start, int end, struct Item a[]) {
    float pivot = b[end];
    int pInd = start-1, i;
    for(i=start; i<end; i++) {
        if(b[i] > pivot) {
            pInd++;
            swap(a, b, i, pInd);
        }
    }
    swap(a, b, pInd+1, end);
    return pInd+1;
}

void quickSort(float b[], int start, int end, struct Item a[]) {
    if(start <= end) {
        int m = partition(b, start, end, a);

        quickSort(b, start, m-1, a);
        quickSort(b, m+1, end, a);
    }
}

void sort(struct Item a[], int n) {
    float b[n];
    int i;
    for(i=0; i<n; i++) {
        b[i] = a[i].price/a[i].weight;
    }
    quickSort(b, 0, n-1, a);
}

float knapSackGreedy(struct Item a[], int n, int W) {
    sort(a, n);
    float profit = 0;
    int i;
    for(i=0; i<n; i++) {
        if(W == 0) break;
        if(W - a[i].weight >= 0) {
            profit += a[i].price;
            W -= a[i].weight;
        } 
        else {
            profit += ((float)W/a[i].weight) * a[i].price;
        }
    }
    return profit;
}

void main() {
    int n, i, W;
    printf("Enter n : ");
    scanf("%d", &n);
    struct Item a[n];
    for(i=0; i<n; i++) {
        printf("weight price : ");
        scanf("%d %d", &a[i].weight, &a[i].price);
    }
    printf("Enter max weight : ");
    scanf("%d", &W);
    /* struct Item a[] = { { 9, 5 }, { 7, 4 }, { 10, 3 } }; */
    /* int n = sizeof(a)/sizeof(a[0]); */
    printf("Profit : %.2f", knapSackGreedy(a, n, W));
}
