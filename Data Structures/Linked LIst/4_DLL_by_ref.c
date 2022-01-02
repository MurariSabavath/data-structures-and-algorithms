/*
ID: B171891
NAME: MURARI SABAVATH
CODE: DOUBLE LINKED LIST CALL BY REFERENCE
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int data;
};

int isEmpty(struct Node **head) {
	int emp;
	emp = *head == NULL ? 1 : 0;
	return emp;
}

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

int length(struct Node **head) {
	struct Node *temp = *head;
	int i = 0;
	while(temp != NULL) {
		i++;
		temp = temp->right;
	}
	return i;
}

int find_element(struct Node **head) {
	struct Node *temp = *head;
	int element = read_element(), i = 0;
	if(!isEmpty(head)) {
		while(temp != NULL && temp->data != element) {
			temp = temp->right;
			i++;
		}
	}else {
		printf("\nList is empty!\n");
	}
	return i;
}

struct Node* create_node() {
	struct Node *node;
	node = (struct Node *)malloc(sizeof(struct Node));
	node->data = read_element();
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert_head(struct Node **head) {
	struct Node *temp = *head, *node;
	if(isEmpty(head)) {
		*head = create_node();
	}else {
		node = create_node();
		node->right = *head;
		(*head)->left = node;
		*head = node;
	}
}

void insert_tail(struct Node **head) {
	struct Node *temp = *head;
	if(isEmpty(head)) {
		insert_head(head);
	}else {
		while(temp->right != NULL) {
			temp = temp->right;
		}
		temp->right = create_node();
	}
}

void insert_index(struct Node **head, int index) {
	struct Node *temp = *head, *node;
	int i = 0;
	if(index == 0) {
		insert_head(head);
	}
	else if(index < length(head)) {
		while(i < index) {
			i++;
			temp = temp->right;
		}
		node = create_node();
		temp->left->right = node;
		node->left = temp->left;
		node->right = temp;
		temp->left = node;
	}else {
		printf("\nIndex is greater than length!\n");
	}
}

void insert_element(struct Node **head) {
	int index = find_element(head);
	if(index != length(head)) {
		insert_index(head, index + 1);
	}else {
		printf("\nElement is not found!\n");
	}
}

void remove_head(struct Node **head) {
	struct Node *temp = *head;
	if(!isEmpty(head) && (*head)->right == NULL) {
		printf("\n%d is removed\n", temp->data);
		head = NULL;
	}else if(!isEmpty(head)) {
		printf("\n%d is removed\n", temp->data);
		temp->right->left = NULL;
		*head = temp->right;
		temp->right = NULL;
	}else {
		printf("\nList is empty!\n");
	}
}

void remove_tail(struct Node **head) {
	struct Node *temp = *head;
	if(!isEmpty(head) && (*head)->right == NULL) {
		remove_head(head);
	}
	else if(!isEmpty(head)) {
		while(temp->right != NULL) {
			temp = temp->right;
		}
		printf("\n%d is removed\n", temp->data);
		temp->left->right = NULL;
		temp->left = NULL;
	}else {
		printf("\nList is Empty!\n");
	}
}

void remove_index(struct Node **head, int index) {
	struct Node *temp = *head;
	int i = 0;
	if(!isEmpty(head) && (index == 0 || (*head)->right == NULL)) {
		remove_head(head);
	}else if(index <= length(head)) {
		while(i < index) {
			temp = temp->right;
			i++;
		}
		if(length(head) - i == 1) {
			remove_tail(head);
		}else {
			temp->right->left = temp->left;
			temp->left->right = temp->right;	
		}
		temp->left = NULL;
		temp->right = NULL;
	}else {
		printf("\nList is empty!\n");
	}
}

void display(struct Node **head) {
	struct Node *temp = *head;
	if(!isEmpty(head)) {
		printf("\nElements in the List are : ");
		while(temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->right;
		}
	}else {
		printf("\nList is empty!\n");
	}
}

void main() {
	struct Node *head = NULL;
	int op, index, len, found;
	do {
		printf("\n0.Exit\n1.Insert at head\n\
2.Insert at Tail\n\
3.Inert at Index\n\
4.Insert after element\n\
5.Display\n\
6.Length\n\
7.Find element\n\
8.Remove at Head\n\
9.Remove at Tail\n\
10.Remvoe at Index\n\
");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				insert_head(&head);
				break;
			case 2:
				insert_tail(&head);
				break;
			case 3:
				printf("\nEnter index : ");
				scanf("%d", &index);
				insert_index(&head, index);
				break;
			case 4:
				insert_element(&head);
				break;
			case 5:
				display(&head);
				break;
			case 6:
				len = length(&head);
				printf("\nLength of List is %d\n", len);
				break;
			case 7:
				found = find_element(&head);
				if(found == length(&head)) {
					printf("\nElement is not found!\n");
				}else {
					printf("\nElement is found!\n");
				}
				break;
			case 8:
				remove_head(&head);
				break;
			case 9:
				remove_tail(&head);
				break;
			case 10:
				printf("\nEnter index : ");
				scanf("%d", &index);
				remove_index(&head, index);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}	
