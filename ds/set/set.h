#ifndef SET_H
#define SET_H
#include <stdlib.h>
#include "../single/list.h"

typedef List Set;

// public interface
void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));


#define set_destroy list_destroy
int set_insert(Set *set, const void *data);
int set_remove(Set *set, void **data);

// union operation
int set_union(Set *setu, const Set *set1, const Set *set2);
// intersection operation
int set_intersection(Set *seti, const Set *set1, const Set *set2);
// difference operation 
int set_difference(Set *setd, const Set *set1, const Set *set2);

// set difference: setd = set1 - set2
int set_is_member(const Set *set1, const void *set2);

// set is subset
int set_is_subset(const Set *set1, const Set *set2);

// set is equal 
int set_is_equal(const Set *set1, const Set *set2);


// setting a size limit
#define set_size(set) ((set)->size)
#endif
