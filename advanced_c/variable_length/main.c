#include <stdio.h>
// c99 and  c11 
// and array must be at the end of prameter
// for c11 we have defined _STDC_NO_VLA_ to 1
// in c11 is a optional feature
int sum2d(int, int, int array[*][*]);

// check support for variable length arrays using this code
/*
#ifdef _STDC_NO_VLA_
printf("Variable length arrays are not supported.\n")
exit(1)
#endif
*/
int main(void) {
    // this is not dynamic allocation but it just another length size in fix size
    // base on user input
    size_t size = 0;
    printf("Enter the number of eelements you want to store:");
    scanf("%zd", &size);

    float values[size];

    return 0;
}