#include <stdio.h>
// is not datatype safe, not a variable but just constant representing a value

#define PI 3.14f
#define TWO_PI 2*3.1415
/* =====================================================================
 * Good practice: the #define preprocessor directive replaces at each occurrence the symbol with the value to which it is defined.
 * Whilst the 'const float pi=3.14f' is datatype safe, by incorporating information about the data type too
 * ===================================================================== */
const float pi = 3.14f;
int main() {
    printf("DEFINE constant\n");
   printf("PI = %f, TWO_PI = %f\n", PI, TWO_PI);
   printf("pi = %f\n", pi);
    return 0;
}
