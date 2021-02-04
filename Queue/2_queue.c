/*
ID: B171891
NAME: MURARI SABAVATH
CODE: QUEUE CALL BY REFERENCE
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

int isFull(struct Queue *q, int len) {
	int full;
	full = q->r == len - 1? 1 : 0;
	if(full) {
		printf("\nQueue is full!\n");
	}
	return full;
}

int isEmpty(struct Queue *q) {
	int emp;
	emp = q->f == q->r ? 1 : 0;
	if(emp) {
		printf("\nQueue is empty!\n");
	}
	return emp;
}

void enqueue(struct Queue *q, int len) {
	if(!isFull(q, len)) {
		q->a[++q->r] = read_element();
		printf("\n%d is enqueued into queue\n", q->a[q->r]);
	}
}

void dequeue(struct Queue *q) {
	if(!isEmpty(q)) {
		printf("\n%d is dequeued\n", q->a[++q->f]);
	}
}

void display(struct Queue *q) {
	int i;
	if(!isEmpty(q)) {
		printf("\nElements in the queue are : ");
		for(i = 0; i < q->r + 1; i++) {
			printf("%d\t", q->a[i]);
		}
	}
}

int length(struct Queue *q) {
	printf("\nLength of queue is %d\n", q->r + 1);
}

void find_element(struct Queue *q) {
	int el, i, flag = 0;
	if(!isEmpty(q)) {
		el = read_element();
		for(i = 0; i < q->r; i++) {
			if(q->a[i] == el) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("\nElement is found!\n");
		}else {
			printf("\nElement is not found!\n");
		}
	}
}

void main() {
	int len, op, full, emp;
	struct Queue q;
	q.f = -1;
	q.r = -1;
	printf("\nEnter the length of Queue : ");
	scanf("%d", &len);
	do {
		printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n4.Length\n5.Is Empty\n6.Is Full\n7.Find an element\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				enqueue(&q, len);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				length(&q);
				break;
			case 5:
				full = isFull(&q, len);
				if(!full) {
					printf("\nQueue is full!\n");
				}
				break;
			case 6:
				emp = isEmpty(&q);
				if(!emp) {
					printf("\nQueue is not empty!\n");
				}
				break;
			case 7:
				find_element(&q);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
