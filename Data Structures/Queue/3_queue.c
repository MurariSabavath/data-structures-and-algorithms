#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int *a;
	int f;
	int r;
	int max;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

int isFull(struct Queue *q) {
	int full;
	full = (q->r == q->max - 1) ? 1 : 0;
	if(full) {
		printf("\nQueue is full!\n");
	}
	return full;
}

int isEmpty(struct Queue *q) {
	int emp;
	emp = (q->f == q->r) ?  1: 0;
	if(emp) {
		printf("\nQueue is empty!\n");
	}
	return emp;
}

void enqueue(struct Queue *q) {
	if(!isFull(q)) {
		q->a[++q->r] = read_element();
		printf("\n%d is enqueued!\n", q->a[q->r]);
	}
}

void dequeue(struct Queue *q) {
	if(!isEmpty(q)) {
		q->f++;
		printf("\n%d is dequeued!\n", q->a[q->f]);
	}
}

void display(struct Queue *q) {
	int i;
	if(!isEmpty(q)) {
		for(i = 0; i < q->r + 1; i++) {
			printf("%d\t", q->a[i]);
		}
	}
}

void length(struct Queue *q) {
	printf("\nLength of Queue is %d\n", q->r + 1);
}

void find_element(struct Queue *q) {
	int el, flag = 0, i;
	if(!isEmpty(q)) {
		el = read_element();
		for(i = 0; i < q->r; i++) {
			if(el == q->a[i]) {
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
	struct Queue *q;
	q = (struct Queue *)malloc(sizeof(struct Queue));
	printf("Enter length of Queue : ");
	scanf("%d", &q->max);
	q->a = (int *)malloc(q->max * sizeof(int));
	q->f = -1;
	q->r = -1;
	int op, emp, full;
	do {
		printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n4.Length\n5.Is Empty\n6.Is Full\n7.Find Element\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				enqueue(q);
				break;
			case 2:
				dequeue(q);
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
				full = isFull(q);
				if(!full) {
					printf("\nQueue is not full!\n");
				}
				break;
			case 7:
				find_element(q);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
