#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int data;
};

int search_for_element(struct Node *root, int element) {
	struct Node *temp = root;
	if(root == NULL) {
		return 0;
	}else {
		while(1) {
			if(temp->data == element){
				return 1;
			}
			else if(element > temp->data) {
				if(temp->right != NULL) {
					temp = temp->right;
				}else {
					return 0;
				}
			}else {
				if(temp->left != NULL) {
					temp = temp->left;
				}else {
					return 0;
				}
			}
		}
	}
}

struct Node* insert(struct Node *root, int element) {
	struct Node *temp = root, *node;
	if(root == NULL) {
		root = (struct Node *)malloc(sizeof(struct Node));
		root->data = element;
		root->left = NULL;
		root->right = NULL;
	}else {
		node = (struct Node *)malloc(sizeof(struct Node));
		node->data = element;
		node->left = NULL;
		node->right = NULL;
		while(1) {
			if(element > temp->data) {
				if(temp->right != NULL) {
					temp = temp->right;
				}else {
					temp->right = node;
					break;
				}
			}else {
				if(temp->left != NULL) {
					temp = temp->left;
				}else {
					temp->left = node;
					break;
				}
			}
		}
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

void postorder(struct Node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}

void inorder(struct Node *root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}

void main() {
	struct Node *root = NULL;
	int op = -1, element, present;
	while(op != 6) {
		printf("\n0.Exit\n1.Insert\n2.Search for element\n3.Preorder\n4.Postorder\n5.Inorder\n6.Exit\n");
		printf("\nEnter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("\nEnter element : ");
				scanf("%d", &element);
				root = insert(root, element);
				break;
			case 2:
				printf("\nEnter element : ");
				scanf("%d", &element);
				present = search_for_element(root, element);
				if(present) {
					printf("\nElement is found!\n");
				}else {
					printf("\nElement is not found!\n");
				}
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				break;
			default:
				printf("\nYour option is invalid!\n");
		}
	}
}
