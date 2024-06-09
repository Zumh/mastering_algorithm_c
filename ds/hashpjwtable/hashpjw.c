// hashpjw.c

#include "hashpjw.h"
#include <stdio.h>

// hashpjw
int hashpjw(const void *key){
    const char *ptr;
    int val;

    // Hash the key by performing a number of bit operations on it.
    val = 0;
    ptr = key;

    while( *ptr != '\0'){

        int tmp;
        val = (val << 4) + (*ptr);

        if (tmp = (val & 0xf0000000)){
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }

        ptr++;
    }

    // In practice, replace PRIME_TBLSIZ with the actual table size.
    return val % PRIME_TBLSIZ;

}

int
main(void){

    // Example keys to hash

    const char *keys[] = {"example1", "example2", "example3", "example4"};

    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Print the hash values for the example keys

    for(int i = 0; i < num_keys; i++){
        fprintf(stdout, "hash for '%s' : %d\n", keys[i], hashpjw(keys[i]));

    }


    return 0;
}