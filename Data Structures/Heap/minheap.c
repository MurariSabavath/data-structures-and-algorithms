/*
ID: B171891
NAME: MURARI SABAVATH
CODE: MIN HEAP
*/

#include <stdio.h>

void swap(int a[],int i,int min) { 
	a[i] = a[i] + a[min] - (a[min] = a[i]);
}
void heap(int a[],int i,int n) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int min = -1;
	if(r < n) {
		if(a[r] > a[l]) {
			min = l;
		}
		else{
			min = r;
		}
	}
	else if(l < n) {
	
		min = l;
	}
	if(min != -1 && a[i] > a[min]) {
		swap(a, i, min);
		heap(a, min, n);
	}
	}
	
void main(){
	int n, i, j;
	printf("\nEnter length : ");
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++){
		printf("\nEnter elements : ");
		scanf("%d", &a[i]);
	}
	for(i = (n/2) - 1; i >= 0; i--){
		heap(a, i, n);
	}
	for(j = 0; j < n; j++){
		printf("%d ", a[j]);
	}
}
