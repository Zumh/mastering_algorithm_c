#include <stdio.h>
int sum(int a) {
    int double_number = a * 2;

    return double_number;
}
int main(void){

    printf("The sum is %d\n", sum(10));

    printf("The sum is %d\n", sum(20));

    printf("The sum is %d\n", sum(30));

    return 0;
}