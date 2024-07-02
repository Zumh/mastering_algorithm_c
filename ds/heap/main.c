// Description: Illustrates using a heap (see Chapter 10)

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

// print_heap
static void print_heap(Heap *heap){

	// Display the heap using in level order.
	fprintf(stdout, "Heap size is %d\n", heap_size(heap));

	for(int index = 0; index < heap_size(heap); index++){
		// Casts the void * pointer to an int * pointer.
		// Dereference the int * pointer to get the actual value.
		fprintf(stdout, "Node=%03d\n", *(int *)heap->tree[index]);
	}

	return;
}


// compare_int
static int compare_int(const void *key1, const void *key2){

	// Compare two integers
	
	if (*(const int *) key1 > *(const int *) key2){
		return 1;
	} else if (*(const int *) key1 < *(const int *) key2){
		return -1;
	} else {
		return 0;
	}
}

// insert and display the heap

static void insert_display(Heap *heap, int *intVal){
	fprintf(stdout, "Inserting %03d\n", *intVal);
	if (heap_insert(heap, &intVal) != 0){
		fprintf(stdout, "Failed to insert %03d\n", *intVal);
		exit(1);
	}
	print_heap(heap);
}

// main
int main(int argc, char **argv){
	Heap heap;
	void *data;
	int intVal[30], index = 0;
	
	// Initialize the heap
	heap_init(&heap, compare_int, NULL);

	// Perform some heap operations.
	int values[] = {5, 10, 20, 1, 25, 22, 9};	
	//int values[] = {5, 10};	
	int num_values = sizeof(values) / sizeof(int);

	for (index = 0; index < num_values; index++){
		intVal[index] = values[index];
		insert_display(&heap, &intVal[index]);
	}
	

	while (heap_size(&heap) > 0){
		// (void **)&data is casting the address of data to a void** (a pointer to a pointer to void). This indicates that heap_extract will store a pointer to the extracted data into data.
		if (heap_extract(&heap, (void **)&data) != 0){
			return 1;
		}
		fprintf(stdout, "Extracting %03d\n", *(int *)data);
		print_heap(&heap);
	}

	// Destroy the heap
	//
	fprintf(stdout, "Destroying heap\n");
	heap_destroy(&heap);

	
	return 0;
}
