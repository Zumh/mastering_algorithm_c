#include <stdio.h>
#include "extern.c"
int number = 10; 
void displayFunction(void);

int main(void){
    printf("The number is %d\n", number);
    displayFunction();
    printf("The number is %d\n", number);
    return 0;
}