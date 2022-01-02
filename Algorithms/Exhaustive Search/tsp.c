#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int graph[100][100], a[100], minCost = INT_MAX;

void initialize(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }

    for(i=0; i<n; i++) a[i] = i;
}


void display(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++) printf("%d\t", a[i]);
    printf("\n");
}

void addEdge(int u, int v, int c) { 
    graph[u][v] = c; 
    graph[v][u] = c;
}

void swap(int a[], int i, int j) { a[i] = a[i] + a[j] - (a[j] = a[i]); }

void permute(int a[], int start, int end) {
    int i, city[end+1], totalCost;
    if(start == end) {
        totalCost= 0;
        for(i=0; i<=end; i++) city[i] = a[i];
        city[i] = a[0];

        for(i=1; i<=end+1; i++) {
            if(graph[city[i-1]][city[i]] == 0) return;
            totalCost += graph[city[i-1]][city[i]];
        }

        if(totalCost < minCost) minCost = totalCost;

    } else {
        for(i=start; i<=end; i++) {
            swap(a, start, i);
            permute(a, start+1, end);
            swap(a, start, i);
        }
    }
}

void main() {
    int e, v, i;
    printf("No of cities : ");
    scanf("%d", &v);
    printf("No of edges : ");
    scanf("%d", &e);
    initialize(v);
    for(i=0; i<e; i++) {
        int u, v, c;
        printf("u v c : ");
        scanf("%d %d %d", &u, &v, &c);
        addEdge(u, v, c);
    }
    permute(a, 0, v-1);
    printf("Minimum cost is : %d", minCost);
}

