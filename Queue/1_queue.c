/*
ID: B171891
NAME: MURARI SABAVATH
CODE: QUEUE BY VAL
*/

#include <stdio.h>

struct Queue {
	int a[100];
	int f;
	int r;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

int isFull(struct Queue q, int len) {
	int full = q.r == len - 1 ? 1 : 0;
	if(full) {
		printf("\nQueue is full!\n");
	}
	return full;
}

int isEmpty(struct Queue q) {
	int emp = q.f == q.r ? 1 : 0;
	if(emp) {
		printf("\nQueue is empty!\n");
	}
	return emp;
}

struct Queue enqueue(struct Queue q, int len) {
	if(!isFull(q, len)) {
		q.a[++q.r] = read_element();
		printf("\n%d is enqueued\n", q.a[q.r]);
	}
	return q;
}

struct Queue dequeue(struct Queue q) {
	if(!isEmpty(q)) {
		printf("\n%d is dequeud\n", q.a[++q.f]);
	}
	return q;
}

void display(struct Queue q) {
	int i;
	if(!isEmpty(q)) {
		printf("\nElements in the queue are : ");
		for(i = 0; i < q.r + 1; i++) {
			printf("\t%d", q.a[i]);
		}
	}
}

void length(struct Queue q) {
	printf("\nLength of queue is %d\n", q.r + 1);
}

void main() {
	struct Queue q;
	q.f = -1;
	q.r = -1;
	int op, len, emp, full;
	printf("\nEnter length : ");
	scanf("%d", &len);
	do {
		printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n4.Length\n5.Is Empty\n6.Is Full\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				q = enqueue(q, len);
				break;
			case 2:
				q = dequeue(q);
				break;
			case 3:
				display(q);
				break;
			case 4:
				length(q);
				break;
			case 5:
				emp = isEmpty(q);
				if(!emp) {
					printf("\nQueue is not empty!\n");
				}
				break;
			case 6:
				full = isFull(q, len);
				if(!full) {
					printf("\nQueue is not full!\n");
				}
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}

