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
	int a[] = {3, 8, 9, 1, 6, 2, 0, 4, 7, -1, 10, 11};
	int len = sizeof(a)/sizeof(a[0]);
	insertionSort(a, len);
	printArray(a, len);
}
