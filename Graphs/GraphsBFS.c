/*
ID: B171891
NAME: MURARI SABAVATH
CODE: GRAPH BFS
*/

#include<stdio.h>
#include<stdlib.h>

struct queue {
   int a[100];
   int f;
   int r;
};

void enqueue(struct queue *q,int j) {
    q->r++;
    q->a[q->r] = j;
}

int dequeue(struct queue *q) {
	int item;
	if(q->f == q->r){
        return 0;
    }
   else {
    q->f++;
    item = q->a[q->f];
    return item;
   }
}

int isempty(struct queue* q) {
	if(q->f==q->r) {
		return 1;
	}
	else {
		return 0;
	}
}

void main() {
	struct queue *q;
	q = (struct queue*)malloc(sizeof(struct queue));
	int n, i, k, j;
	q->f = q->r =-1;
	printf("Enter the order of matrix : ");
	scanf("%d",&n);
	int b[n][n];
	int visit[n];
	for(i = 0;i < 10; i++) {
	   visit[i]=0;
	}
	printf("Enter the values of matrix:\n");
	for(i = 0;i < n;i ++) {
	 for(j = 0 ;j < n; j++) {
	    scanf("%d", &b[i][j]);
	  }
	}
	for(i = 0;i < n; i++) {
	  for(j=0;j<n;j++) {
	      printf("%d\t", b[i][j]);
	   }
	  printf("\n");
	}
	enqueue(q, j);
	while(!isempty(q)) {
	    k = dequeue(q);
	    if(visit[k] == 0) {
			visit[k] = 1;
			printf("visited %d\n", k);
			for(j = 0; j < n; j++) {
		   		if(b[k][j] == 1 && visit[j] == 0) {
		    	   enqueue(q,j);
		    	}
			}
	    }
	}
}
