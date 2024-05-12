#include <stdio.h>
/* ===========================================
Note: The register storage class is used with frequently accessed variables to store these variables in a CPU register, unlike the normal way when the variables are stored in the RAM.
It gains speed, but the size of the variable gets limited to the size of the CPU register. Additionally there can not be applied the operator & address of to a variable of register type because it doesn't have address.
============================================== */
int main() {
 
    printf("register!\n");
 
   int x = 15; 
    // we can use only in local block
    register  int *a = &x;// regiser variable (counter);

    printf("\n%d\n", *a);
    return 0;
}
