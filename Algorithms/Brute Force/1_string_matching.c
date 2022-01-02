#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, m;
    printf("Enter length of string : ");
    scanf("%d", &n);
    printf("\nEnter length of pattern : ");
    scanf("%d", &m);
    char s[n], pat[m];
    printf("Enter char : ");
    scanf("%s", &s);
    printf("\nEnter pattern : ");
    scanf("%s", &pat);

    int i, flag = 0;

    for(i=0; i<n-m+1; i++) {
        int j;
        for(j=0; j<m; j++) {
            if(s[i+j] != pat[j]) break;
        }
        if(j == m) {
            flag = 1;
            printf("Match found\n");
            break;
        }
    }
    if(flag == 0) {
        printf("Match not found\n");
    }
}
