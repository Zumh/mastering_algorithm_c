// include external function without using header file
#include "../include/other.h"

int globalVar = 10;



int main(void) {
    printf("The global variable can be use between files.\n");
    printf("Intitial value %d\n", globalVar);
    displayFunction();
    return 0;
}
