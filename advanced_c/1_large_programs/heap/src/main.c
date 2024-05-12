#include <stdio.h>
#include "../include/heap.h"
int main() {
    printf("Doubling Heap\n");

    // allocate memory in the heap
    int *age = (int *) malloc( 1 * sizeof(int));
    *age = 43;

    // allocate memory in the heap
    double *salary = (double *) malloc(1 *sizeof(double));
    *salary = 72.4;

    // allocate memory in the heap
    double *myArray = (double *) malloc(3 *sizeof(double));
    myArray[0] = 1000.0;
    myArray[1] = 2000.0;
    myArray[2] = 3000.0;

    // allocate memory in the heap
    double *twice = (double *) malloc(1 *sizeof(double));
    *twice = multiplyDouble(salary);

    printf("The double is %.3f\n", *twice);


    // free them in order. 
    free(twice);
    free(myArray);
    free(salary);
    free(age);    
    return 0;
}
