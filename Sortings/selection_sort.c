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
	int a[] = {3, 8, 9, 1, 6, 2, 0, 4, 7, -1, 10, 11};
	int len = sizeof(a)/sizeof(a[0]);
	selectionSort(a, len);
	printArray(a, len);
}
