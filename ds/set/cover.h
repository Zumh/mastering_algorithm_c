// cover.h

#ifndef COVER_H
#define COVER_H
#include "set.h"

// Define a structure for subsets identified by a key.
typedef struct Kset_ {
	void *key;
	Set set;
} Kset;

// Public Interface
int cover(Set *members, Set *subsets, Set *covering);

#endif


