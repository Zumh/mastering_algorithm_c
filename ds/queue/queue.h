// queue.h
//
#ifndef QUEUE_H
#define QUEUE_H
	#include <stdlib.h>

#include "../single/list.h"

// implement queue as linked list
typedef List Queue;

// Public interface

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *q, void *data);

int queue_dequeue(Queue *q, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

#define queue_size list_size

#endif
