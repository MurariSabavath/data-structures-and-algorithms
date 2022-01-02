/*
ID: B171891
NAME: MURARI SABAVATH
CODE: SELECTION SORT
*/


#include <stdio.h>

void printArray(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}

void swap(int a[], int i, int j) {
	a[i] = a[i] + a[j] - (a[j] = a[i]);
}

void selectionSort(int a[], int n) {
	int i, j, low;
	for(i = 0; i < n; i++)	{
		low = i;
		for(j = i+1; j < n; j++) {
			if(a[low] > a[j]) {
				low = j;
			}
		}
		swap(a, i, low);
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
	selectionSort(a, len);
	printArray(a, len);
}
