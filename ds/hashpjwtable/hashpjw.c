// hashpjw.c

#include "hashpjw.h"
#include <stdio.h>

// hashpjw
/*
    this hash function process an input string ('key') and 
    computes an integer hash value based on it. The result is suitable for use in a hash table
    of size 'PRIME_TBLSIZ. The high-order bits are managed to prevent overflow and
    to ensure the distribution of hash values.
*/
int hashpjw(const void *key){
    const char *ptr;
    int val;

    // Hash the key by performing a number of bit operations on it.
    // hold the resulting hash value.
    val = 0;

    // ptr is a pointer iterate through each character of the input key
    ptr = key;

    // iverates over each character of the input string until the null terminator
    while( *ptr != '\0'){

        int tmp;
        // update val by performing left shifted by 4 bits to the value and added character
        // compute hash value
        val = (val << 4) + (*ptr);
        // Handling High bits
        // tmp capture the high bits of val that might cause overflow
        // if tmp is non-zero, the high-order bits are moved to the low-order bits of val
        // and XORed out of val to ensure they don't interfere with a the rest of the computation.
        if (tmp = (val & 0xf0000000)){
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        // next character
        ptr++;
    }

    // In practice, replace PRIME_TBLSIZ with the actual table size.
    // hash value is taken modulo PRIME_TBLSIZ to ensure it fitx within the desired hash table size.
    return val % PRIME_TBLSIZ;

}

int
main(void){

    // Example keys to hash

    const char *keys[] = {"example1", "example2", "example3", "example4"};

    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Print the hash values for the example keys

    for(int i = 0; i < num_keys; i++){
        // 
        fprintf(stdout, "hash for '%s' : %d\n", keys[i], hashpjw(keys[i]));

    }


    return 0;
}