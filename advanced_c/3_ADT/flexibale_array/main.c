/*
only last member of struct

can contain most one flexible array 

cannot be only member of a struct

must have one or more struct fixed member

cannot be another member of struct

cannot be statically initialized

must be dynamicaaly allocated

cannot fix the size of the flexible array member at compile time

Warning
in c89 is not compatible
can yield undefined behavior
bad practice and any undefined behavior should be avoided

Pro
Flexible array member reduces number of allocation by half 1/2
- you just have to allocate once. 

If you have to allocate a large number of struct instances
You can improve the runtime and mem usage program by stant factor
*/

#include <stdio.h>
#include <stdlib.h>

struct s {
    int arraySize;

    // this is the flexibale array
    int array[];

};

int main() {
    int desireSize = 5; 
    struct s *ptr;
    // this allocate memory size for the flexible array member
    ptr = malloc( sizeof( struct s ) + desireSize * sizeof( int ) );



    return 0;

}