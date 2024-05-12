#include "../include/heap.h"

double multiplyDouble(double *inputNumber){

    double *twice = (double *) malloc(1*sizeof(double));

    *twice = *inputNumber * 2;

    return *twice;
}