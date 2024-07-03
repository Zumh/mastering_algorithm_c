#include <stdio.h>
#include <stdlib.h>

#include "pqueue.h"

void print_pqueue(PQueue *pqueue){
	// Display the priority queue in level order.
	fprintf(stdout, "Priority queue size is %d\n", pqueue_size(pqueue));

	for(int index = 0; index < pqueue_size(pqueue); index++){
		fprintf(stdout, "Node=%03d\n", *(int *)pqueue->tree[index]);
	}
}

int compare_int(const void *int1, const void *int2){
	// Compare two integers
	int a = *(const int *)int1;

	int b = *(const int *)int2;
	return (a > b) - (a < b);
}

int main(int argc, char *argv[]){
	PQueue pqueue;

	void *data;
	int values[] = {5, 10, 20, 1, 25, 22, 12};

	// Intialize the priority queue.
	pqueue_init(&pqueue, compare_int, NULL);

	// Perform some priority queue operations.
	for(int index = 0; index < sizeof(values)/sizeof(int); index++){
		fprintf(stdout, "Inserting %d\n", values[index]);
		if (pqueue_insert(&pqueue, &values[index]) != 0){
			return 1;
		}
		print_pqueue(&pqueue);
		
	}

	// Extract the elements from priority queue.
	while(pqueue_size(&pqueue) > 0){
		fprintf(stdout, "Peeking at the highest priority element..Value=%03d\n", *(int *)pqueue_peek(&pqueue));
		if (pqueue_extract(&pqueue, &data) != 0){
			return 1;
		}
		fprintf(stdout, "Extracting %03d\n", *(int *)data);
		print_pqueue(&pqueue);
	}

	// Destroy the priority queue.
	fprintf(stdout, "Destroying the priority pqueue\n");
	pqueue_destroy(&pqueue);
	return 0;
}
