// hashtable.h

#ifndef CHTBL_H
#define CHTBL_H
#include <stdlib.h>
#include "../single/list.h"

// Define a structure for chained hash tables.
typedef struct HashTable_ {
    int buckets;
    int (*h) (const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy) (void *data);

    int size;
    List *table;

} HashTable;

// Public Interface
int hashtable_init(HashTable *htbl, int buckets, int (*h) (const void *key), int (*match)(const void *key1, const void *key2), void (*destroy) (void *data));

void hashtable_destroy(HashTable *htbl);

int hashtable_insert(HashTable *htbl, const void *data);

int hashtable_remove(HashTable *htbl, void **data);

int hashtable_lookup(const HashTable *htbl, void **data);

#define hashtable_size(htbl) ((htbl)->size)

#endif 
