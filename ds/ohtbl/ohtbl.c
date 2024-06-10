// file ohtbl.c

#include <stdlib.h>
#include <string.h>

#include "ohtbl.h"

// Reserve a sentinel memory address for vacated elements.

static char vacated;

int ohtbl_init(OHTbl *htbl, int positions, 
int (*h1)(const void *key), 
int (*h2)(const void *key), 
int (*match)(const void *key1, const void *key2),
 void (*destroy)(void *data)){
    
    // Allocate space for the hash table.

    if ((htbl->table = (void **)malloc(positions * sizeof(void *))) == NULL){
        return -1;
    }

    // Initialize each position.
    htbl->positions = positions;

    for(int index = 0; index < htbl->positions; index++){
        htbl->table[index] = NULL;
    }
    // Set the vacated member to the sentinel memroy address reserved for this.
    htbl->vacated = &vacated;

    // Encapsulate the functions.
    htbl->h1 = h1;
    htbl->h2 = h2;
    htbl->match = match;
    htbl->destroy = destroy;

    // Initialize the number of elements in the table.
    htbl->size = 0;

    return 0;
    
 }

void ohtbl_destroy(OHTbl *htbl) {
    // Call a user-defined function to free dynamically allocated data. 
    for (int index = 0; index < htbl->positions; index++) {
        if (htbl->table[index] != NULL && htbl->table[index] != htbl->vacated){
            htbl->destroy(htbl->table[index]);
        }
    }

    // Free the storage allocated for the hash table.
    free(htbl->table);

    // No operations are allowed now, but clear the structure as a precaution.
    memset(htbl, 0, sizeof(OHTbl));

    return;
}

// ohtbl_insert
int ohtbl_insert(OHTbl *htbl, const void *data){
    void *temp;
    int position = 0;

    // Do not exceed the number of positions in the table.
    if (htbl->size == htbl->positions){
        return -1;
    }

    // Do nothing if the data is already in the table.
    temp = (void *) data;
    if (ohtbl_lookup(htbl, &temp) == 0){
        return 1;
    }

    // Use double hashing to hash the key.
    for (int index = 0; index < htbl->positions; index++){
        position = (htbl->h1(data) + (index * htbl->h2(data))) % htbl->positions;

        if (htbl->table[position] == NULL || htbl->table[position] == htbl->vacated){
            // Insert the data into the table.
            htbl->table[position] = (void *) data;
            htbl->size++;
            return 0;
        } 
    }

    return -1;
}
int ohtbl_remove(OHTbl *htbl, void **data){
    int position = 0;

    // Use double hashing to hash the key.
    for(int index = 0; index < htbl->positions; index++){
        position = (htbl->h1(*data) + (index * htbl->h2(*data))) % htbl->positions;

        if (htbl->table[position] == NULL){

            // Return that the data was not found.
            return -1 ;
        } else if (htbl->table[position] == htbl->vacated) {
            // Search beyond vacated positions.

            continue;

        } else if (htbl->match(htbl->table[position], *data)){
            // Pass back the data from the table.
            *data = htbl->table[position];
            htbl->table[position] = htbl->vacated;
            htbl->size--;
            return 0;
        }
    }

    // Return that the data was not found.
    return -1;
}

int ohtbl_lookup(const OHTbl *htbl, void **data){

    int position = 0;

    // Use double hashing to hash the key.
    for(int index = 0; index < htbl->positions; index++){

        position = (htbl->h1(*data) + (index * htbl->h2(*data))) % htbl->positions;

        if (htbl->table[position] == NULL){
            // Return that the data was not found.
            return -1;
        } else if (htbl->match(htbl->table[position], *data)){
            // Pass back the data from the table.
            *data = htbl->table[position];
            return 0;
        }
    }
`
    // Return that the data was not found.
    return -1;
}