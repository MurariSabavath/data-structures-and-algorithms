#include <stdio.h>
#include <math.h>
#include <limits.h>

void main() {
    int a[] = {0, 1, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int total = pow(2, n), i, j;
    
    for(i=1; i<total; i++) {
        for(j=0; j<n; j++) {
            int b = 1 << j;
            if(i & b) printf("%d\t", a[j]);
        }
        printf("\n");
    }
}
