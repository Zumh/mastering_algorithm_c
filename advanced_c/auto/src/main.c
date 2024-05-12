#include <stdio.h>
#include "../include/auto.h"
int main() {
    printf("Get number from user and double it\n");
    // auto is not needed because variable is already auto
    auto int  twice;

    twice = multiply(10.0);
    printf("The double is %.3d\n", twice);
    return 0;
}
