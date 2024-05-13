#include <stdio.h>
#include <stdlib.h>
#include "display.c"
int count;
void display();

int main(void){
    // here we count global count variable
    for(count = 0; count < 3; count++);

    // here we display global count variable
    display();
    return 0;
}