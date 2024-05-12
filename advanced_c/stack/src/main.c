#include <stdio.h>
#include "../include/stack.h"
int main(void){
    int age = 43;

    double salary = 72.4;

    double salaries[] = { 1000.0, 2000.0, 3000.0 };

    printf("Age: %d Current salary: %.2f\n", age, salary);

    printf("Future salaries:\n");
    int i  = 0;
    for(i = 0; i < 3; i++){
        printf("Salary: %.2f\n", salaries[i]);
    }
    return 0;
}
