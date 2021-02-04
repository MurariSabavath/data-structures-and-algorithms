/*
ID: B171891
NAME: MURARI SABAVATH
CODE: CIRCULAR LINKED LIST CALL BY VAL
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	int data;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

struct Node *insert_head(struct Node *head, int el) {
	struct Node *node, *temp = head;
	node = (struct Node *)malloc(sizeof(struct Node));
	node->data = el;
	if(head == NULL) {
		head = node;
		node->next = node;
	} else {
		head = node;
		node->next = temp->next;
	}
	return head;
}

void display(struct Node *head) {
	struct Node *temp = head;
	printf("%d %d", temp->data, temp->next->next == head);
}

void main() {
	struct Node *head = NULL;
	int op;
	do {
		printf("\n0.Exit\n1.Insert at Head\n2.Insert at Tail\n5.Display\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				head = insert_head(head, read_element());
				break;
			case 5:
				display(head);
				break;
			default:
				printf("\nYour option is invalid!");
		}
	} while(op != 0);
}
