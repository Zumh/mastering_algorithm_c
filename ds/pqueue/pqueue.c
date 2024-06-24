// Description: Illustrates using  a priority queue (see Chapter 10)

#include <stdio.h>
#include <stdlib.h>

#include "pqueue.h"


// print_queue

static void print_queue(PQueue *pqueue){

    // Display the priority queue in level order.

    fprintf(stdout, "Priority queue in level order:\n", pqueue_size(pqueue));

    for(int index = 0; index < pqueue_size(pqueue); index++){
        fprintf(stdout, "Node=%03d\n", *(int *)pqueue->tree[index]);
    }

    return;
}

    