#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int max(int a, int b)  { return (a > b ? a : b); }

int multiply(int a, int b) {
    if(a < 10 && b < 10) return a * b;

    int n1 = log10(a) + 1;
    int n2 = log10(b) + 1;

    int mid = max(n1, n2)/2;
    int p = pow(10, mid);

    int a0 = a/p;
    int b0 = b/p;

    int a1 = a%p;
    int b1 = b%p;

    int c1 = multiply(a0, b0);
    int c0 = multiply(a1, b1);
    int c2 = multiply(a0 + a1, b0 + b1) - c0 - c1;

    return (c1 * pow(10, 2*mid) + c2 * pow(10, mid) + c0);
}

void main() {
    int a = 120, b = 103;
    printf("%d\n", a*b);
    printf("%d", multiply(a, b));
}

