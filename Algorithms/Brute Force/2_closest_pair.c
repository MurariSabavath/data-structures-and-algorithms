#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
   float x, y;
};

float dist(struct Point p1, struct Point p2) {
   float ans = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
   printf("%.2f\n", ans);
   return ans;
}

void closestPair(struct Point p[], int n) {
    int i, j;
    float x1, x2, y1, y2, min = 1000000.0;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            float d = dist(p[i], p[j]);
           if(d < min) {
               min = d;
               x1 = p[i].x;
               x2 = p[j].x;
               y1 = p[i].y;
               y2 = p[j].y;
           } 
        }
    }
    printf("x1 y1 : %.2f %.2f\nx2 y2 : %.2f %.2f\n", x1, y1, x2, y2);
}

void main() {
    int n;
    printf("Enter no of points : ");
    scanf("%d", &n);
    struct Point points[n];
    int i;
    for(i=0; i<n; i++) {
       printf("Enter %d x y : ", i); 
       scanf("%f %f", &points[i].x, &points[i].y);
    }
    closestPair(points, n);
}
