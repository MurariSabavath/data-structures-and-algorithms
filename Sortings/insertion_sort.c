/*
ID: B171891
NAME: MURARI SABAVATH
CODE: INSERTION SORT
*/

#include <stdio.h>

void printArray(int a[], int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d\t", a[i]);
	}
}


void insertionSort(int a[], int n) {
	int i, key, index;
	for(i=0; i<n; i++) {
		index = i-1;
		key = a[i];
		while(index >= 0 && key <= a[index]) {
			a[index+1] = a[index];
			index--;
		}
		a[index+1] = key;
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
	insertionSort(a, len);
	printArray(a, len);
}
