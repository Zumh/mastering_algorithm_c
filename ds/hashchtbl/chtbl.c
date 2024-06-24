// hashtable.c

#include <stdlib.h>
#include <string.h>


#include "../single/list.h"

#include "chtbl.h"

// hashtable_init
/*
This public interface function initialize the chained hash table.
- Allocating memory for the specified number of buckets.
Inittializing each bucket as a list.
Storing the provided hash, match, and destroy function pointers.
Setting the initial size of the hash table to zero.
*/
int hashtable_init(HashTable *htbl, int buckets, int (*h) (const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)){
    
    // Allocate space for the hash table.
    if ((htbl->table = (List *) malloc(buckets * sizeof(List))) == NULL){
        return -1;
    }

    // numbers of bucktes
    htbl->buckets = buckets;

    // Initialize each buckets.
    for(int index = 0; index < htbl->buckets; index++){
        list_init(&htbl->table[index], destroy);
    }

    // Encapsulate the functions.
    htbl->h = h;
    // match function is for checking if the data is in the table
    htbl->match = match;
    // this function is for destroying hash table
    htbl->destroy = destroy;

    // Initialize the number of elements in the table.
    htbl->size = 0;

    return 0;
}


// hashtable_destroy
void hashtable_destroy(HashTable *htbl) {

    // Destroy each bucket.
    for(int index = 0; index < htbl->buckets; index++) {
        list_destroy(&htbl->table[index]);
    }

    // Free the storage allocated for the hash table.

    free(htbl->table);

    // No operations are allowed now, but clear the structure as a precaustion.

    memset(htbl, 0, sizeof(HashTable));

    return;
}

// hashtable_insert
/*
the function insert data in a bucket list
Checks if the data is already in the hash table using the lookup function.
if the data is not found, it computes the appropriate bucket using the hash function.
Inserts the data into the computed bucket using `list_ins_next`.
If the insertion is successful, it increments the size of the hash table.
Returns the result of the insertion operation.
*/
int hashtable_insert(HashTable *htbl, const void *data){
    void *temp;
    int bucket, retval;

    // Do nothing if the data is already in the table.

    temp = (void *) data;

    if (hashtable_lookup(htbl, &temp) == 0){
        return 1;
    }

    // hash the key.

    bucket = htbl->h(data) % htbl->buckets;

    // insert the data into the bucket.

    if((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0){
        htbl->size++;
    }
    return retval;
}

// hashtable_remove
/*
Removes the data from the hash table.
 */
int hashtable_remove(HashTable *htbl, void **data) {
    ListNode *element, *prev;
    int bucket;

    // Hash the bucket key.
    bucket = htbl->h(*data) % htbl->buckets;

    // Search for the data in the bucket

    prev = NULL;

    for(element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element)){
        // check given data is match with current data from the a bucket list
        if (htbl->match(*data, list_data(element))) {

            // REmove the data from the bucket if found.
            if (list_rem_next(&htbl->table[bucket], prev, data) == 0){
                // decrement the size of a bucket and delete the bucket if there is no more list for remove.
                htbl->size--;
                return 0;
              
            } else {
                // return -1 if not found
                return -1;
            }
        }

        // update the previous element
        prev = element;
    }

    // Return that the data was not found.
    return -1;

}

// hashtable_lookup
/*
Calculate the key of the data
Search for the data in the hash table
Returns 0 if the data is found and -1 if not found
*/
int hashtable_lookup(const HashTable *htbl, void **data){
    ListNode *element;
    int bucket;

    // Hash the key.
    bucket = htbl->h(*data) % htbl->buckets;

    // Search for the data in the bucket.

    for (element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element)){

        if (htbl->match(*data, list_data(element))) {
            // Pass back the data from the table.
            *data = list_data(element);
            return 0;
        }
    }
    return -1 ;
}
