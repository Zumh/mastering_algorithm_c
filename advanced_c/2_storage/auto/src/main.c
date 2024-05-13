#include <stdio.h>
#include "../include/auto.h"
int main() {
    printf("Get number from user and double it\n");
    // auto is not needed because variable is already auto
    auto int  twice;
    // storage_class var_data_type var_name
    twice = multiply(10.0);
    printf("The double is %.3d\n", twice);
    return 0;
}
