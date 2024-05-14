// the restrict type qualifier is an optimization hint for the compiler 
// - the compiler can choose to ingore it
// Used in pointer declarations as a type qualiefier for pointers
// - tells the coimpiler that a particular pointer is the only reference to the value it points to throughout its scope
// -- the same value is not referenced by any other pointer or variable within that scope
// -- the pointer is the sole initial means of accessing a data object
// - tells the compiler it does not need to add any additional checks
//
// without the restrict keyword, the comipler has to assume the worse case
// -- that some other identifier might have changed the data in between two uses of a pointer
// - with the restrict keyword used, the compiler is free to look for computational shortcuts 
// - if a programmer uses restrict keyword and violate the above condition, result is undefined behavior
// not supported by C++
//

int * restrict intPtrA;
int * restrict intPtrB;

// - tells the compiler that, for the duration of the scope in which intPtrA and intPtrB are defined
// they will never access the same value
//
// their use for pointing to integers inside an array is mutually exclusive


#include <stdio.h>
#include <stdlib.h>
int main(void){
/*
	int n; 
	int array[10];

	// sole access to malloc
	int * restrict restart = (int *) malloc(10*sizeof(int));

	// not qualified as restrict
	int *par = array;

	for (n = 0; n < 10; n++){
		par[n] += 5;
		restart[n] += 5;
		array[n] *= 2;
		par[n] += 3;
		restart[n] += 3;

	}
	restart[n] += 8;

	// no overlap 
	// no accesss to same block of data
	void * memcpy(void * restrict dest, const void * restrict src, size_t n);

	// no over write before it was use
	void * memremove(void * dest, const void * src, size_t n);


	*/
}

// a1 and a2 is memory block is independent of each other.
// comipler optimize when comile
void f1(int n, float * restrict a1, const float * restrict a2){
	int i;
	for(i = 0; i < n; i++){
		a1[i] += a2[i];
	}
}
