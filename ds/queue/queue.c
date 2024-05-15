// queue.c
//
#include <stdio.h>
#include "../single/list.h"
#include "queue.h"

// queue_enqueue
int queue_enqueue(Queue *q, void *data){
	// Enqueue the data
	return list_ins_next(q, list_tail(q), data);
}

// queue_dequeue
int queue_dequeue(Queue *q, void **data){
	// Dequeue the data.
	
	return list_rem_next(q, NULL, data);
}
