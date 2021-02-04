#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *right;
	struct Node *left;
	int data;
};

struct Queue {
	struct Node *a[100];
	int front;
	int rear;
};

int read_element() {
	int el;
	printf("\nEnter element : ");
	scanf("%d", &el);
	return el;
}

struct Queue enqueue(struct Queue q, struct Node *node) {
	q.a[++q.rear] = node;
	return q;
}

int isEmpty(struct Queue *q) {
	return (q->rear == q->front) ? 1 : 0;
}

struct Node* dequeue(struct Queue *q) {
	if(q->rear == q->front) {
		return NULL;
	}else {
		return q->a[++q->front];
	}
}

struct Node *insert(struct Node *root, int el) {
	struct Node *temp, *node;
	struct Queue q;
	q.front = -1;
	q.rear = -1;
	node = (struct Node *)malloc(sizeof(struct Node));
	node->right = NULL;
	node->left = NULL;
	node->data = el;
	if(root == NULL) {
		return node;
	}else {
		q = enqueue(q, root);
		while(1) {
			temp = dequeue(&q);
			if(temp->left != NULL) {
				q = enqueue(q, temp->left);
			}else {
				temp->left = node;
				break;
			}
			if(temp->right != NULL) {
				q = enqueue(q, temp->right);
			}else {
				temp->right = node;
				break;
			}
		}
	}
	return root;
}

void display(struct Node *root) {
	struct Node *temp;
	struct Queue q;
	q.rear = -1;
	q.front = -1;
	if(root == NULL) {
		printf("\nTree is empty!\n");
	}else {
		q = enqueue(q, root);
		while(!isEmpty(&q)) {
			temp = dequeue(&q);
			printf("\t%d", temp->data);
			if(temp->left != NULL) {
				q = enqueue(q, temp->left);
			}
			if(temp->right != NULL) {
				q = enqueue(q, temp->right);
			}
		}
	}
}

struct Node* find_element(struct Node *root, int el) {
	struct Node *temp;
	struct Queue q;
	q.rear = -1;
	q.front = -1;
	if(root == NULL) {
		return NULL;
	}else {
		q = enqueue(q, root);
		while(!isEmpty(&q)) {
			temp = dequeue(&q);
			if(temp->data == el) {
				return temp;
			}
			if(temp->left != NULL) {
				q = enqueue(q, temp->left);
			}
			if(temp->right != NULL) {
				q = enqueue(q, temp->right);
			}
		}
	}
	return NULL;
}

struct Node *last_node(struct Node *root) {
	struct Node *temp;
	struct Queue q;
	q.rear = -1;
	q.front = -1;
	q = enqueue(q, root);
	while(!isEmpty(&q)) {
		temp = dequeue(&q);
		if(temp->right != NULL) {
			q = enqueue(q, temp->right);
		}
		if(temp->left != NULL) {
			q = enqueue(q, temp->left);
		}
	}
	return temp;
}

struct Node* last_node_parent(struct Node *root, struct Node *last) {
	struct Node *temp;
	struct Queue q;
	q.rear = -1;
	q.front = -1;
	q = enqueue(q, root);
	while(!isEmpty(&q)) {
		temp = dequeue(&q);
		if(temp->right == last) {
			return temp;
		}
		if(temp->left == last) {
			return temp;
		}
		if(temp->right != NULL) {
			q = enqueue(q, temp->right);
		}
		if(temp->left != NULL) {
			q = enqueue(q, temp->left);
		}
	}
	return NULL;
}

struct Node *remove_node(struct Node *root, int el) {
	struct Node *present = find_element(root, el), *last, *last_parent;
	if(present) {
		last = last_node(root);
		last_parent = last_node_parent(root, last);
		present->data = last->data;
		if(last_parent->left == last) {
			last_parent->left = NULL;
		}else {
			last_parent->right = NULL;
		}
	}else {
		printf("\nElement is not found!\n");
	}
	return root;
}

void preorder(struct Node *root) {
	if(root != NULL) {
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct Node *root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}

void postorder(struct Node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}

void main() {
	struct Node *root = NULL, *present;
	int op;
	do {
		printf("\n0.Exit\n1.Insert Node\n2.Display\n3.Search Element\n4.Delete Node\n5.Pre Order Traversal\n");
		printf("\nEnter option : ");
		scanf("%d", &op);
		switch(op) {
			case 0:
				break;
			case 1:
				root = insert(root, read_element());
				break;
			case 2:
				display(root);
				break;
			case 3:
				present = find_element(root, read_element());
				if(present) {
					printf("\nElement is found!\n");
				}else {
					printf("\nElement is not found!\n");
				}
				break;
			case 4:
				root = remove_node(root, read_element());
				break;
			case 5:
				preorder(root);
				break;
			case 6:
				inorder(root);
				break;
			case 7:
				postorder(root);
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	} while(op != 0);
}
