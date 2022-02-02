#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int a[50];
	int top;
	int max;
};

int read_element() {
	int element;
	printf("\nEnter element : ");
	scanf("%d", &element);
	return element;
}

int isFull(struct Stack s) {
	if(s.top == s.max - 1) {
		return 1;
	}
	return 0;
}

int isEmpty(struct Stack s) {
	if(s.top == -1)  {
		return 1;
	}
	return 0;
}

struct Stack push(struct Stack s) {
	int el;
	if(!isFull(s)) {
		el = read_element();
		s.top++;
		s.a[s.top] = el;
		printf("\n%d is pushed into stack!\n", el);
	}else {
		printf("\nStack is full!\n");
	}
	return s;
}


struct Stack pop(struct Stack s) {
	if(!isEmpty(s)) {
		printf("\n%d is popped\n", s.a[s.top]);
		s.top--;
	}else {
		printf("\nStack is empty!\n");
	}
	return s;
}

void display(struct Stack s) {
	int i;
	if(!isEmpty(s)) {
		printf("\nElements in the stack are : ");
		for(i = 0; i < s.top + 1; i++) {
			printf("\t%d", s.a[i]);
		}
	} else {
		printf("\nStack is empty!\n");
	}
}

void length(struct Stack s) {
	printf("\nLength of stack is %d\n", s.top + 1);
}

void find_element(struct Stack s) {
	int el, flag, i;
	if(!isEmpty(s)) {
		el = read_element();
		for(i = 0; i < s.max; i++) {
			if(el == s.a[i]) {
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

void peek(struct Stack *s) {
	printf("\nPeek value is %d\n", s.a[s.top]);
}

int main() {
	struct Stack s;
	printf("Enter length of array : ");
	scanf("%d", &s.max);
	s.top = -1;
	int op, emp, full;
	do {
		printf("\n0.Exit\n1.Push\n2.Pop\n3.Print\n4.Is Empty\n5.Is Full\n6.Length\n7.Check for element\n8.Peek\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				s = push(s);
				break;
			case 2:
				s = pop(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				emp = isEmpty(s);
				if(emp) {
					printf("\nStack is empty!\n");
				}else {
					printf("\nStack is not empty!\n");
				}
				break;
			case 5:
				full = isFull(s);
				if(full) {
					printf("\nStack is full!\n");
				}else {
					printf("\nStack is not full\n");
				}
				break;
			case 6:
				length(s);
				break;
			case 7:
				find_element(s);
				break;
			case 8:
				peek(s);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
