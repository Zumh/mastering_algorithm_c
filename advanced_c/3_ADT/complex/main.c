#include <stdio.h>
#include <complex.h>
#define __STDC_WANT_LIB_EXT1__ 1
/*
    c99 support complex
    c11 support optional complex
*/
int main(void){

    #ifdef __STDC_NO_COMPLEX__
        printf("Complex is not supported.\n");
    #else 
        printf("Complex is supported.\n");
    #endif

    // float _Complex, double long double, float _imaginary
    // complex.h we do not need to to _Complex 
    // double complex ix = 1.0 + 2.0i;
    // creal(z1) return real part
    // complex.h return cpow
    double _Complex a = 1.0 + 2.0i;

    double complex sum = creal(a) + cimag(a);

    printf("Sum is %f + %fi\n", creal(sum), cimag(sum));

    double complex b = 3.034i;

    double complex quotient = creal(a) / cimag(b);
    printf("Quotient is %f / %fi\n", creal(quotient), cimag(quotient));

    double complex conjvalue = conj(a);

    printf("Conjugate is %f + %fi\n", creal(conjvalue), cimag(conjvalue));
    
    return 0;
}