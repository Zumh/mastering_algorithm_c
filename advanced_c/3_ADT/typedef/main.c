#include <stdio.h>

// integer_pointer is an alias to int
// readiblity
//  maintainability 
// no magic number
// protability with synonyms for basic data type 
// handle by comipler and typename not new type.
typedef int* integer_pointer;
integer_pointer bently, rolls_royce; // same as int *bently, *rolls_royce;

#define int_pointer int * // int_pointer is an alias to int
int_pointer chalk, cheese; // only replace int * with int_pointer, same as int *chalk, cheese;  cheese will be integer because of comma.

// use typedefs for types that combine arrays, structs, pointers, or functions
// use typedef for portable types, when you port the code to deifferent platforms
// typedef can be use for casting

// typedef int (*ptr_to_int_fun)(void); // pointer to int function
// char *p;
// .... = (ptr_to_int_fun) p;


int main(void) {
    
    integer_pointer p;
    integer_pointer a, *b; // b is **b to int;
    integer_pointer myArray[10]; // same as int *myArray[10];


    return 0;
}