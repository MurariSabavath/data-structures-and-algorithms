#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	int data;
};

int read_element() {
	int el;
	printf("\nEnter elemnt : ");
	scanf("%d", &el);
	return el;
}

struct Node* create_node() {
	struct Node *node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->data = read_element();
	node->next = NULL;
	return node;
}

int isEmpty(struct Node **head) {
	int emp;
	emp = *head == NULL ? 1 : 0;
	return emp;
}

int length(struct Node **head) {
	int i = 0;
	struct Node *temp = *head;
	while(temp != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}

int find_element(struct Node **head, int element) {
	int index = 0, i = 0;
	struct Node *temp = *head;
	while(temp != NULL && temp->data != element) {
		temp = temp->next;
		i++;
	}
	return i;
}

void insert_head(struct Node **head) {
	struct Node *node;
	if(isEmpty(head)) {
		*head = create_node();
	}else {
		node = create_node();
		node->next = *head;
		*head = node;
	}
}

void insert_end(struct Node **head) {
	struct Node *temp = *head;
	if(isEmpty(head)) {
		insert_head(head);
	}else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = create_node();
	}
}

void insert_index(struct Node **head, int index) {
	struct Node *node, *temp = *head;
	int i = 1;
	if(index == 0) {
		insert_head(head);
	}
	else if(index <= length(head)) {
		while(i < index) {
			temp = temp->next;
			i++;
		}
		node = create_node();
		node->next = temp->next;
		temp->next = node;
	}else {
		printf("\nIndex is greater than length!\n");
	}
}

void insert_element(struct Node **head) {
	int element, index;
	printf("\nEnter element : ");
	scanf("%d", &element);
	if(!isEmpty(head)) {
		index = find_element(head, element);
		insert_index(head, index + 1);
	}
}

void display(struct Node **head) {
	struct Node *temp = *head;
	if(!isEmpty(head)) {
		printf("\nElements in the List are : ");
		while(temp != NULL) {
			printf("\t%d", temp->data);
			temp = temp->next;
		}
	}else {
		printf("\nList is empty!\n");
	}
}

void delete_head(struct Node **head) {
	struct Node *temp = *head;
	if(isEmpty(head)) {
		printf("\nList is empty!\n");
	}else if((*head)->next == NULL) {
		*head = NULL;
	}else {
		*head = (*head)->next;
	}
}

void delete_end(struct Node **head) {
	struct Node *temp = *head;
	if(temp->next == NULL) {
		delete_head(head);
	}else {
		while(temp->next->next != NULL) {
			temp = temp->next;
		}
		temp->next = NULL;
	}
}

void delete_index(struct Node **head, int index) {
	int i = 1;
	struct Node *temp = *head;
	if(index == 0) {
		delete_head(head);
	}
	else if(index < length(head)) {
		while(i < index) {
			i++;
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}else {
		printf("\nIndex is greater than length!\n");
	}
}

void delete_element(struct Node **head, int element) {
	int index = find_element(head, element);
	if(index != length(head)) {
		delete_index(head, index);
	}else{
		printf("\nElement is not found!\n");
	}
}

void main() {
	struct Node *head = NULL;
	int op, index, len;
	do {
		printf("\n0.Exit\n1.Insert at Head\n\
2.Insert at End\n\
3.Insert at Index\n\
4.Insert after element\n\
5.Display\n\
6.Length\n\
7.Find element\n\
8.Delete at Head\n\
9.Delete Tail\n\
10.Delete Index\n\
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
				insert_end(&head);
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
				printf("\nLength of the List is %d\n", len);
				break;
			case 7:
				index = find_element(&head, read_element());
				if(index == length(&head)) {
					printf("\nElement is not found!");
				}else {
					printf("\nElement is found!\n");
				}
				break;
			case 8:
				delete_head(&head);
				break;
			case 9:
				delete_end(&head);
				break;
			case 10:
				printf("\nEnter index : ");
				scanf("%d", &index);
				delete_index(&head, index);
				break;
			case 11:
				delete_element(&head, read_element());
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
