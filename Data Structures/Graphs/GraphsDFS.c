#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	int d;
};

struct AdjList {
	struct Node *head;
};

struct Graph {
	struct AdjList *ar;
	int v;
};

struct Node* createNode(int src) {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->d = src;
	node->next = NULL;
	return node;
}

void addEdge(struct Graph *graph, int src, int dest) {
	struct Node *node = createNode(dest);
	node->next = graph->ar[src].head;
	graph->ar[src].head = node;
	
	node = createNode(src);
	node->next = graph->ar[dest].head;
	graph->ar[dest].head = node;
}

struct Graph* createGraph(int v) {
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->ar = (struct AdjList*)malloc(v * sizeof(struct AdjList));
	graph->v = v;
	
	int i;
	for(i=0; i<graph->v; i++) {
		graph->ar[i].head = NULL;
	}
	return graph;
}

void printGraph(struct Graph *graph) {
	struct Node *node;
	int i;
	for(i=0; i<graph->v; i++) {
		node = graph->ar[i].head;
		printf("Adj of %d are : ", i);
		while(node) {
			printf("%d ", node->d);
			node = node->next;
		}
		printf("\n");
	}
}

void dfs(struct Graph *graph, int vertex, int visit[]) {
	struct Node *node = graph->ar[vertex].head;
	printf("%d\t", vertex);
	visit[vertex] = 1;
	while(node) {
		if(visit[node->d] == -1) dfs(graph, node->d, visit);
		node = node->next;
	}
}

void main() {
	int v = 5, i;
	struct Graph *graph = createGraph(v);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 4, 3);
	addEdge(graph, 4, 1);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	
	int visit[graph->v];
	for(i=0; i<graph->v; i++) {
		visit[i] = -1;
	}
	
	printGraph(graph);
	
	dfs(graph, 0, visit);
}
