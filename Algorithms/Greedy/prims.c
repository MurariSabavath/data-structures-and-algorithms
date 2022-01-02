#include <stdio.h>
#include <limits.h>

#define V 5

int graph[100][100];

void primMST(int graph[][100]) {
    int visit[V], cost[V];
    int totalCost = 0, i, j, v;

    for(i=0; i<V; i++) {
        cost[i] = INT_MAX;
        visit[i] = -1; 
    }

    cost[0] = 0;
    for(i=0; i<V-1; i++) {
       int min = INT_MAX, min_index = 0;
       for(j=0; j<V; j++) {
           if(visit[j] == -1 && cost[j] < min) {
               min = cost[j];
               min_index = j;
           }
       }
       int u = min_index;
       visit[u] = 1;

       for(v=0; v<V; v++) {
           if(graph[u][v] && visit[v] == -1 && graph[u][v] < cost[v]) {
               cost[v] = graph[u][v];
               totalCost += cost[v];
               printf("%d %d\n", u, v);
           }
       }
    }
    printf("%d", totalCost);
}


void main() {
    int e, v, i, j;
    printf("No of vertices : ");
    scanf("%d", &v);

    printf("No of edges : ");
    scanf("%d", &e);
    for(i=0; i<e; i++) {
        int p, q, cost;
        printf("u v cost : ");
        scanf("%d %d %d", &p, &q, &cost);
        graph[p][q] = cost;
        graph[q][p] = cost;
    }
    for(i=0; i<V; i++) {
        for(j=0; j<V; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    /* int graph[V][V] = { { 0, 2, 0, 6, 0 }, */
    /*                     { 2, 0, 3, 8, 5 }, */
    /*                     { 0, 3, 0, 0, 7 }, */
    /*                     { 6, 8, 0, 0, 9 }, */
    /*                     { 0, 5, 7, 9, 0 } }; */
    primMST(graph);
}

/* 1 2 2 */
/* 1 3 6 */
/* 2 3 3 */ 
/* 2 4 8 */
/* 2 5 5 */
/* 3 5 7 */
/* 4 5 9 */
