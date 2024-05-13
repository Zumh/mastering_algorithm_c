#include <stdio.h>
static double global_var = 3.0;
float global_float = 10.0;
int main(void){
    {
        int temp = 10;
        printf("Block scope local variable is %d\n", temp);
    }

    
    printf("The global variable is %f\n", global_var);


    // define register
    register int b = 10;
    printf("The register variable is %d\n", b);
    
    
    printf("The global float variable is %f\n", global_float);
    return 0;


}