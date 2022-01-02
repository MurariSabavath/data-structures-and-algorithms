#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define V 4
#define INF 999999

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    for(i=0; i<V; i++) {
        for(j=0; j<V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(i=0; i<V; i++) {
        for(j=0; j<V; j++) {
            for(k=0; k<V; k++) {
                if(dist[j][i] + dist[i][k] < dist[j][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    for(i=0; i<V; i++) {
        for(j=0; j<V; j++) {
            if(dist[i][j] == INF) {
                printf("%7s ", "INF");
            }else {
                printf("%7d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void main() {
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
    floydWarshall(graph);

}
