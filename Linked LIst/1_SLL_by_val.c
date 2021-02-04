/*
ID: B171891
NAME: MURARI SABAVATH
CODE: SINGLE LINKED LIST CALL BY VALUE
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

int isEmpty(struct Node *head) {
	int emp = head == NULL ? 1 : 0;
	return emp;
}

int length(struct Node *head) {
	int len = 0;
	while(head != NULL) {
		head = head->next;
		len++;
	}
	return len;
}

struct Node* create_node() {
	struct Node* node;
	node = (struct Node *)malloc(sizeof(struct Node));
	node->data = read_element();
	node->next = NULL;
	return node;
}

struct Node* insert_head(struct Node *head){
	struct Node *node, *temp = head;
	node = create_node();
	if(isEmpty(head)){
		head = node;
	}else {
		node->next = head;
		head = node;
	}
	return head;
};

struct Node* insert_end(struct Node *head) {
	struct Node *node, *temp = head;
	if(isEmpty(head)) {
		head = insert_head(head);
	}else {
		node = create_node();
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
	}
	return head;
}

struct Node* insert_index(struct Node *head) {
	struct Node *temp = head, *temp1 = head, *node;
	int index, i = 1;
	printf("\nEnter index : ");
	scanf("%d", &index);
	if(index > length(head) - 1) {
		printf("\nIndex is greater than length!\n");
	} else if(index == 0) {
		head = insert_head(head);
	}
	else {
		while(i <= index   && temp->next != NULL) {
			temp = temp->next;
			i++;
		}
		while(temp1->next != temp) {
			temp1 = temp1->next;
		}
		node = create_node();
		node->next = temp;
		temp1->next = node;
	}
	return head;
}

struct Node* insert_after_element(struct Node *head) {
	struct Node *temp = head, *node;
	int element = read_element();
	int found = find_element(head, element);
	if(found) {
		while(temp->data != element) {
			temp = temp->next;
		}
		node = create_node();
		node->next = temp->next;
		temp->next = node;
	}else {
		printf("\nElement is not found!\n");
	}
	return head;
}

int find_element(struct Node* head, int element) {
	int index = 0;
	struct Node *temp = head;
	while(temp != NULL) {
		if(temp->data == element) {
			break;
		}
		temp = temp->next;
		index++;
	}
	return index;
}


void display(struct Node *head) {
	if(!isEmpty(head)) {
		printf("\nElements in the List are : ");
		while(head != NULL) {
			printf("\t%d", head->data);
			head = head->next;
		}
	}else {
		printf("\nList is empty!\n");
	}
	printf("\n");
}

struct Node* remove_head(struct Node *head) {
	struct Node *temp = head;
	if(!isEmpty(head)) {
		printf("\n%d is removed from list!\n", head->data);
		head = temp->next;
	}else {
		printf("\nList is empty!\n");
	}
	return head;
}

struct Node* remove_tail(struct Node *head) {
	struct Node *temp = head, *temp1 = head;
	if(!isEmpty(head) && head->next == NULL) {
		head = NULL;
	}
	else if(!isEmpty(head)) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		while(temp1->next != temp) {
			temp1 = temp1->next;
		}
		temp1->next = NULL;
	}else {
		printf("\nList is empty!\n");
	}
	return head;
}

struct Node* remove_index(struct Node *head, int index) {
	struct Node *temp = head;
	int i = 1;
	if(index > length(head) - 1) {
		printf("\nIndex is greater than length!\n");
	} else if(index == 0) {
		head = remove_head(head);
	}
	else {
		while(i < index   && temp->next != NULL) {
			temp = temp->next;
			i++;
		}
		printf("\n%d is removed from list!\n", temp->next->data);
		temp->next = temp->next->next;
	}
	return head;
}

struct Node* remove_element(struct Node* head, int element) {
	int index = find_element(head, element);
	if(index == length(head)) {
		printf("\nElement not found!\n");
		return head;
	}
	return remove_index(head, index);
}

void main() {
	struct Node *head;
	head = NULL;
	int op, index, element, found;
	do {
		printf("\n0.Exit\n1.Insert at Head\n2.Insert at Tail\n3.Insert at Index\n\
4.Insert after element\n\
5.Display\n6.Remove at Head\n\
7.Remove at Tail\n\
8.Remove at Index\n\
9.Remove given element\n\
10.Search for element\n\
");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				head = insert_head(head);
				break;
			case 2:
				head = insert_end(head);
				break;
			case 3:
				head = insert_index(head);
				break;
			case 4:
				head = insert_after_element(head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				head = remove_head(head);
				break;
			case 7:
				head = remove_tail(head);
				break;
			case 8:
				printf("\nEnter index : ");
				scanf("%d", &index);
				head = remove_index(head, index);
				break;
			case 9:
				element = read_element();
				head = remove_element(head, element);
				break;
			case 10:
				element = read_element();
				found = find_element(head, element);
				if(found != length(head)) {
					printf("\n%d is found at %d\n", element, found);
				}else {
					printf("\nElement is not found!\n");
				}
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
