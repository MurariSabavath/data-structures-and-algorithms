//Call by value pointer
#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int *a;
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
	if(s->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(struct Stack *s) {
	if(s->top == s->max - 1) {
		return 1;
	}
	return 0;
}

void display(struct Stack *s) {
	int i;
	if(!isEmpty(s)) {
		printf("\nElements in the stack are : ");
		for(i = 0; i < s->top; i++){
			printf("\t%d", s->a[s->top]);
		}
	}else {
		printf("\nStack is empty!\n");
	}
}

void push(struct Stack *s) {
	if(!isFull(s)) {
		s->a[++s->top] = read_element();
		printf("\n%d is pushed into stack\n", s->a[s->top]);
	}else {
		printf("\nStack is empty!\n");
	}
}

void pop(struct Stack *s) {
	if(!isEmpty(s)) {
		printf("\n%d is popped from stack\n", s->a[s->top]);
		s->top--;
	}else {
		printf("\nStack is empty!\n");
	}
}

int length(struct Stack *s) {
	return s->top + 1;
}

void find_element(struct Stack *s) {
	int emp, el, i, flag = 0;
	if(!isEmpty(s)) {
		el = read_element();
		for(i = 0; i < s->top - 1; i++) {
			if(el == s->a[i]){
				flag = 1;
				break;
			}else {
				flag = 0;
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

int main() {
	struct Stack *s;
	s = (struct Stack *)malloc(sizeof(struct Stack));
	printf("Enter the length of array : ");
	scanf("%d", &s->max);
	s->a = (int *)malloc(s->max * sizeof(int));
	s->top = -1;
	int op, emp, full, len;
	do {
		printf("\n0.Exit\n1.Push\n2.Pop\n3.Print\n4.Length\n5.Is Empty\n6.Is Full\n7.Check for element\n");
		printf("\nEnter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				push(s);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				len = length(s);
				printf("\nLength of stack is %d\n", len);
				break;
			case 5:
				emp = isEmpty(s);
				if(emp) {
					printf("\nStack is empty!\n");
				}else {
					printf("\nStack is not empty!\n");
				}
				break;
			case 6:
				full = isFull(s);
				if(full) {
					printf("\nStack is full!\n");
				}else {
					printf("Stack is not full!\n");
				}
				break;
			case 7:
				find_element(s);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
