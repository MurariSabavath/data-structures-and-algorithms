/*
ID: B171891
NAME: MURARI SABAVATH
CODE: BUBBLE SORT
*/

#include <stdio.h>

void display(int a[], int len) {
	int i;
	for(i = 0; i < len; i++) {
		printf("\t%d", a[i]);
	}
}

void bubbleSort(int a[], int len) {
	int i, j;
	for(i = 0; i < len; i++) {
		for(j = 0; j < len - i - 1; j++) {
			if(a[j] > a[j+1]) {
				a[j] = a[j] + a[j+1] - (a[j+1] = a[j]);
			}
		}
	}
}

void main() {
	int i, len;
	printf("\nEnter length of array : ");
	scanf("%d", &len);
	int a[len];
	for(i = 0; i < len; i++) {
		printf("\nEnter element : ");
		scanf("%d", &a[i]);
	}
	printf("\nArray before Sorting is : ");
	display(a, len);
	bubbleSort(a, len);
	printf("\nArray after Sorting is : ");
	display(a, len);
}
