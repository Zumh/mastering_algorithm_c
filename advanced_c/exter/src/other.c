
#include "../include/other.h"
// can be access by other file 
// we can't intialize global variable
extern int globalVar;
// can be accessed from other file
extern void displayFunction(){
    printf("The global variable is %d\n", ++globalVar);
}