#include <stdio.h>

void swap(int a[], int start, int end) {
    a[start] = a[start] + a[end] - (a[end] = a[start]);
}

void permutation(int a[], int start, int end) {
    int i;
    if(start == end) {
        for(i=0; i<=end; i++) printf("%d\t", a[i]);
        printf("\n");
    }
    for(i=start; i<=end; i++) {
        swap(a, start, i);
        permutation(a, start+1, end);
        swap(a, start, i);
    }
}

void main() {
    int a[] = {0, 1, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    permutation(a, 0, n-1);
}
