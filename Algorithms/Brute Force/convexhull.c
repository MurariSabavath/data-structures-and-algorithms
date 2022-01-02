#include<stdio.h>
#include<math.h>
#include<limits.h>

struct Point {
    int x, y;
};

void convex(struct Point p[], int n) {
    int i, j, k, rc, lc, ec;
    int x1, y1, x2, y2, a, b, c;
    int visited[n];
    for(i=0; i<n; i++) {
        visited[i] = 0;
    }

    for(i=0; i<n-1; i++) {
        for(j=0; j<n; j++) {
            rc = lc = ec = 0;
            x1 = p[i].x, y1 = p[i].y;
            x2 = p[j].x, y2 = p[j].y;
            a = y2 - y1;
            b = x1 - x2;
            c = x1 * y2 - y1 * x2;
            for(k=0; k<n; k++) {
                if(k != i && k != j) {
                    int x = p[k].x;
                    int y = p[k].y;
                    int cal = a*x + b*y - c;
                    if(cal > 0) rc++;
                    else if(cal < 0) lc++;
                    else ec++;
                }
            }
            if(rc+ec+2 == n || lc+ec+2 == n) {
                visited[i] = 1;
                visited[j] = 1;
            }
        }
    }
    for(i=0; i<n; i++) {
        if(visited[i]) printf("%d, %d\n", p[i].x, p[i].y);
    }
}

void main() {
    struct Point p[] = {
        {0, 3},
        {2, 2},
        {1, 1},
        {2, 1},
        {3, 0},
        {0, 0},
        {3, 3}
    };
    int n = 7;
    convex(p, n);
}
