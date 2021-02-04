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
	int a[] = {5, 4, 3, 2, 1};
	int len = sizeof(a) / sizeof(a[0]);
	printf("\nArray before Sorting is : ");
	display(a, len);
	bubbleSort(a, len);
	printf("\nArray after Sorting is : ");
	display(a, len);
}
