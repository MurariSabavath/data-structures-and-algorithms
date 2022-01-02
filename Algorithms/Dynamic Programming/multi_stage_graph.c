#include<stdio.h>
#include<math.h>
#include<limits.h>

#define N 8

int shortestDist(int graph[N][N]) {
    int cost[N], d[N], path[N];
    int i, j, mini;

    cost[N-1] = 0;
    d[N-1] = N-1;

    for(i=N-2; i>=0; i--) {
        mini = INT_MAX;
        for(j=i; j<N; j++) {
            if(graph[i][j] != 0 && (graph[i][j] + cost[j] < mini)) {
                mini = graph[i][j] + cost[j];
                d[i] = j;
            }
        }
        cost[i] = mini;
    }

    path[0] = 0;
    for(i=1; i<N; i++) path[i] = d[path[i-1]];

    for(i=0; i<N; i++) {
        if(path[i] != N-1) printf("%d\t", path[i]);
    }
    printf("%d\n", path[N-1]);
    printf("\n");
    return cost[0];
}

void main() {
    int graph[N][N] = { 
        {0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 6, 0, 0, 7, 0},
        {0, 0, 0, 0, 6, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("%d", shortestDist(graph));
}
