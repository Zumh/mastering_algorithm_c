#include <stdio.h>
struct point {int x, y;};
int main(void){
    int array[] = {1,2,3,[10]=19, [3 ... 8]=400};
    struct point p = {.y = 23, .x = 34};
    struct point p2 = {y: 2, x: 7};
    struct point p3 = {2, 3};

    struct point p4[5] = {[2].y = 6, [2].x = 8, [4].y = 9, [4].x = 10, 0};
    int n = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < n; i++){
        printf("number %d\n", array[i]);
    }

    printf("p4 struct\n");
    for (int i = 0; i < 5; i++){
        printf("point %d %d\n", p4[i].x, p4[i].y);
    }
    return 0;
}

