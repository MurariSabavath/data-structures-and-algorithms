/*
ID: B171891
NAME: MURARI SABAVATH
CODE: BUBBLE SORT
*/

#include <stdio.h>

void printArray(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
}
void swap(int a[], int i, int j){
	a[i] = a[i] + a[j] - (a[j] = a[i]);
}

void bubbleSort(int a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				swap(a, j, j+1);
			}
		}
	}
}

void main(){
	int i, len;
	printf("\nEnter length of array : ");
	scanf("%d", &len);
	int a[len];
	for(i = 0; i < len; i++) {
		printf("\nEnter element : ");
		scanf("%d", &a[i]);
	}
	bubbleSort(a, len);
	printArray(a, len);
}
