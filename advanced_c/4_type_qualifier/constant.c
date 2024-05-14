#include <stdio.h>
// global data shouldn't be use unless with const
int main (void) {
	typedef const int zip;
	const zip q = 8;

	const float *pf; // cannot change the value it pointing to 
	float const *pfc; // same as const float *pfc
	
	float * const pf2; // pf2 cannot changed the address but value can be changed
}

void display(const int arrayy[], int limit)
// the data array is pointing to cannot be change
char *strcat(char *restrict s1, const char *restrict s2);

