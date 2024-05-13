#include <stdio.h>
#include <stdlib.h>
// this include insert the static function code from other file 
// so it act like a nother code.
#include "static_fun.c"
// this function prototype is automatically external
// extern make it readable that's all and is none static function
extern void not_static(void);
void local_var (void) {
    static int count = 0;
    int localVar = 0;
    printf("Count: %d Local: %d\n", ++count, ++localVar);

}
/* ==========================================================
Notes: the static keyword has different meanings depending where it is applied
1. if the static keyword is applied to a  local variable , then that variable retains its value every time the function is re-appealed. The variable does not initialize
2. it the static keyword is applied to a global variable, then that variable can not be seen outside of the current file where the global variable is defined into
3. if the static keyword is applied to a function, then that function can only be used within that file
============================================================= */
int main() {
    printf("Static variable local, global and function\n");
    printf("Local to the function\n");
    for (int i = 0; i < 5; i++){
         local_var();
    }

    printf("Static function\n");
    // because we use #include "static_fun.c" this function is inserted into the current file
   // how ever when we start using .h header file we can't use this function
   // because the function is static in other file
    static_fun();

    printf("None static to the function\n");
    not_static();

    return 0;
}
