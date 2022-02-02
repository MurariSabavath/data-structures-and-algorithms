#include <stdio.h>

void swap(int a[],int i,int min) {
	a[i] = a[i] + a[min] - (a[min] = a[i]);
}

void heap(int a[],int i,int n) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int max = -1;
	if(r<n) {
		if(a[r] < a[l]) {
			max = l;
		}
		else {
			max = r;
		}
	}
	else if(l < n) {
	
		max=l;
	}
	if(max!=-1&&a[i]<a[max]){
		swap(a, i, max);
		heap(a, max, n);
	}
	}
	
void main(){
	int n, i, j;
	printf("\nEnter length of array : ");
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++){
		printf("\nEnter element : ");
		scanf("%d", &a[i]);
	}
	for(i = (n/2) - 1; i >= 0; i--) {
		heap(a, i, n);
	}
	for(j = 0; j < n; j++) {
		printf("%d ", a[j]);
	}
}
