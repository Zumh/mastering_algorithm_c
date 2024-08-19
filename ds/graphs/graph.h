// graph.h

#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include "../single/list.h"
#include "../set/set.h"

// Define a structure for adjacency lists.

typedef struct AdjList_ {
    void *vertex;
    Set adjacent;
} AdjList;

// Define a structure for graphs.

typedef struct Graph_ {
    int vcount;
    int ecount;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    List adjlists;
} Graph;

#endif 
