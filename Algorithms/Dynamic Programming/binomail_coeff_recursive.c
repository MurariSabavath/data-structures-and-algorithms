#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int nck(int n, int k) {
    if(k == 0 || k == n) return 1;
    return nck(n-1, k-1) + nck(n-1, k);
}

void main() {
    int n = 4, k = 2;
    printf("%d", nck(n, k));

}


