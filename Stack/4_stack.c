/*
ID: B171891
NAME: MURARI SABAVATH
CODE: STACK CALL BY REFERENCE
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int *a;
	int max;
	int top;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

int isFull(struct Stack **s) {
	return (*s)->max - 1 == (*s)->top ? 1 : 0;
}

int isEmpty(struct Stack **s) {
	return (*s)->top == -1 ? 1 : 0;
}

void push(struct Stack **s) {
	if(!isFull(s)) {
		(*s)->top++;
		(*s)->a[(*s)->top] = read_element();
		printf("\n%d is pushed into stack\n", (*s)->a[(*s)->top]);
	}else {
		printf("\nStack is full!\n");
	}
}

void pop(struct Stack **s) {
	if(!isEmpty(s)) {
		printf("\n%d is popped from stack\n", (*s)->a[(*s)->top--]);
	}else {
		printf("\nStack is empty!\n");
	}
}

void display(struct Stack **s) {
	int i;
	if(!isEmpty(s)) {
		printf("\nElements in the stack are : ");
		for(i = 0; i < (*s)->top + 1; i++) {
			printf("%d\t", (*s)->a[i]);
		}
	}else {
		printf("\nStack is empty!\n");
	}
}

void length(struct Stack **s) {
	printf("\nLength of stack is %d\n", (*s)->top + 1);
}

void find_element(struct Stack **s) {
	int el, flag = 0, i;
	if(!isEmpty(s)) {
		el = read_element();
		for(i = 0; i < (*s)->max; i++) {
			if((*s)->a[i] == el) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("\nElement is found!\n");
		} else {
			printf("\nElement is not present in stack!\n");
		}
	}else {
		printf("\nStack is empty!\n");
	}
}

void main() {
	struct Stack *s;
	s = (struct Stack *)malloc(sizeof(struct Stack));
	printf("Enter the length of stack : ");
	scanf("%d", &s->max);
	s->a = (int *)malloc(s->max * sizeof(int));
	s->top = -1;
	int op, emp, full;
	do {
		printf("\n0.Exit\n1.Push\n2.Pop\n3.Display\n4.Length\n5.Is Empty\n6.Is Full\n7.Find Element\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				push(&s);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				display(&s);
				break;
			case 4:
				length(&s);
				break;
			case 5:
				emp = isEmpty(&s);
				if(emp) {
					printf("\nStack is empty!\n");
				}else {
					printf("\nStack is not empty!\n");
				}
				break;
			case 6:
				full = isFull(&s);
				if(full) {
					printf("\nStack is full!\n");
				}else {
					printf("\nStack is not full\n");
				}
				break;
			case 7:
				find_element(&s);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
