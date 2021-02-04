/*
ID: B171891
NAME: MURARI SABAVATH
CODE: STACK CALL BY REFERENCE
*/

#include <stdio.h>

struct Stack {
	int a[100];
	int top;
	int max;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

int isEmpty(struct Stack *s) {
	return (s->top == -1) ? 1 : 0;
}

int isFull(struct Stack *s) {
	return (s->top == s->max - 1) ? 1 : 0;
}

void push(struct Stack *s) {
	if(!isFull(s)) {
		s->a[++s->top] = read_element();
		printf("\n%d is pushed into stack\n", s->a[s->top]);
	}else {
		printf("\nStack is full!\n");
	}
}

void pop(struct Stack *s) {
	if(!isEmpty(s)) {
		printf("\n%d is popped\n", s->a[s->top--]);
	}else {
		printf("\nStack is empty!\n");
	}
}

void peek(struct Stack *s) {
	if(!isEmpty(s)) {
		printf("\nPeek value is %d", s->a[s->top]);
	}else {
		printf("\nStack is empty!\n");
	}
}

void display(struct Stack *s) {
	int i;
	if(!isEmpty(s)) {
		printf("\nElemens in the stack are : ");
		for(i = 0; i < s->top + 1; i++) {
			printf("\t%d", s->a[i]);
		}
	}else {
		printf("\nStack is empty!\n");
	}
}

void length(struct Stack *s) {
	printf("\nLength of stack is %d\n", s->top + 1);
}


void find_element(struct Stack *s) {
	int el, i, flag;
	if(!isEmpty(s)) {
		el = read_element();
		for(i = 0; i < s->top + 1; i++) {
			if(el == s->a[i]) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("\nElement is found!\n");
		}else {
			printf("\nElement is not found!\n");
		}
	}else {
		printf("\nStack is empty!\n");
	}
}

void main() {
	struct Stack s;
	printf("Enter the length of stack : ");
	scanf("%d", &s.max);
	s.top = -1;
	int op, emp, full;
	do {
		printf("\n0.Exit\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Length\n6.Is Empty\n7.Is Full\n8.Check for element\n");
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
				peek(&s);
				break;
			case 5:
				length(&s);
				break;
			case 6:
				emp = isEmpty(&s);
				if(emp) {
					printf("\nStack is empty!\n");
				}else {
					printf("\nStack is not empty!\n");
				}
				break;
			case 7:
				full = isFull(&s);
				if(full) {
					printf("\nStack is full!\n");
				}else {
					printf("\nStack is not full!\n");
				}
				break;
			case 8:
				find_element(&s);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
