#include <stdio.h>
#include <stdlib.h>

#include "../single/list.h"
#include "queue.h"


// print queue

static void print_queue(const Queue *q) {
	ListNode *node;

	int *data, size, i;

	// Display the queue
	
	fprintf(stdout, "Queue size is %d\n", size = queue_size(q));

	i = 0;

	node = list_head(q);

	while(i < size){
		data = list_data(node);
		fprintf(stdout, "queue[%03d] = %d\n", i , *data);
		node = list_next(node);
		i++;
	}

	return;
}


// main
//
int main(void){

	Queue queue;

	int *data, i;


	// Initialize the queue
	queue_init(&queue, free);

	// Perform some queue operations.
	for(i = 0; i < 10; i++){
		if((data = (int *) malloc(sizeof(int))) == NULL){
			return 1;
		}

		*data = i + 1;

		if (queue_enqueue(&queue, data) != 0){
			return 1;
		}
	}
	
	print_queue(&queue);


	if((data = queue_peek(&queue)) != NULL){
		fprintf(stdout, "Peeking at the head lement...Value=%03d\n", *data);
	} else {
		fprintf(stdout, "Peeking at the head element...Value=NULL\n");
	}

	print_queue(&queue);
	fprintf(stdout, "Dequeuing all elements\n");

	while(queue_size(&queue) > 0){
		if(queue_dequeue(&queue, (void **)&data) == 0){
			free(data);
		}
	}

	if((data = queue_peek(&queue)) != NULL){
		fprintf(stdout, "Peeking at the head lement...Value=%03d\n", *data);
	} else {
		fprintf(stdout, "Peeking at the head element...Value=NULL\n");
	}

	fprintf(stdout, "Destroying the queue\n");
	// Destroy the queue
	queue_destroy(&queue);

	return 0;
}
