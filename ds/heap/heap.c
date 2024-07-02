// File: heap.c

#include <stdlib.h>
#include <string.h>
//#include <stdio.h>

#include "heap.h"

// Define private macrosused by the heap implementation.


#define heap_parent(npos) ((int)(((npos) - 1) / 2))

#define heap_left(npos) (((npos) * 2) + 1)

#define heap_right(npos) (((npos) * 2) + 2)


// heap_init
void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data)){
	// Initialize the heap.
	
	heap->size = 0;
	heap->compare = compare;
	heap->destroy = destroy;
	heap->tree = NULL;
}


// Remove all the nodes from the heap.
void heap_destroy(Heap *heap){
	// check if the tree is empty if not then destroy the tree
	// call user define function to free dynamically allocated data
	// free all the nodes
	if (heap->destroy != NULL){

		// we extract the size of the heap and use it to traverse the tree
		for(int index = 0; index < heap_size(heap); index++){
			// destroy function is generic function initialize from main.c
			heap->destroy(heap->tree[index]);
		}
	}
	
	// free the storage allowcated for the heap.
	free(heap->tree);

	// No operations are allowed now, but clear the structure as a precaution.
	// Fill the heap with all zeros.
	memset(heap, 0, sizeof(Heap));
	
}

int heap_insert(Heap *heap, const void *data){
	void **temp;
	int indexPos, parentPos;	

	// Allocate storgate for the node
	
	temp = realloc(heap->tree, (heap_size(heap) + 1) * sizeof(void *));
	if (temp == NULL){
		return -1;
	}
	
	heap->tree = temp;
	
	// Insert the node after the last node
	heap->tree[heap_size(heap)] = (void *)data;
	

	// Heapify the tree by pushing the contents of the new node to upward.
	indexPos = heap_size(heap);
	parentPos = heap_parent(indexPos);	

	while(indexPos > 0 && heap->compare(heap->tree[parentPos], heap->tree[indexPos]) < 0){
		// swap the contents of the current node and its parent.	
		void *swap_temp = heap->tree[parentPos];
		heap->tree[parentPos] = heap->tree[indexPos];
		heap->tree[indexPos] = swap_temp;

		// Move up one leve in the tree to continue heapifying.
		indexPos = parentPos;
		parentPos = heap_parent(indexPos);
	}

	// Adjust the size of the heap to account for the inserted node.

	heap->size++;
	return 0;
}



int heap_extract(Heap *heap, void **data){

	// Do not allow extraction from an empty heap.
	if (heap_size(heap) == 0){
		return -1;
	}


	// Extract the node at the top of the heap.
	*data = heap->tree[0];
	//fprintf(stdout, "Extract data here %d\n", *(int *)*data);

	// Adjust the storage used by the heap

	void *save = heap->tree[heap_size(heap) - 1];
	if(heap_size(heap)  - 1 > 0){
		void **temp = realloc(heap->tree, (heap_size(heap) - 1) * sizeof (void *));
		if (temp == NULL){
			return -1;
		}
		heap->tree = temp;
		// Adjust the size of the heap to account for the extracted node.
		heap->size--;
	} else {
		// Manage the heap when extracting the last node.

		free(heap->tree);
		heap->tree = NULL;
		heap->size = 0;
		return 0;
	
	}

	// copy the last node to the top
	heap->tree[0] = save;
	// Heapify the tree by pushing the contents of the new top downward.
	int indexPos = 0;

	while(1){
		// Select the child to swap with the current node
		int leftPos = heap_left(indexPos);
		int rightPos = heap_right(indexPos);

		int minPos = indexPos;

		if (leftPos < heap_size(heap) && heap->compare(heap->tree[leftPos], heap->tree[indexPos]) > 0){
			minPos = leftPos;
		} 

		if (rightPos < heap_size(heap) && heap->compare(heap->tree[rightPos], heap->tree[minPos]) > 0 ){
			minPos = rightPos;
		}

		// When minpos is indexpos, the heap property has been restored.

		if (minPos == indexPos){
			break;
		} else {

			// Swap the contents of the current node and the selected child.
			void *swap_temp = heap->tree[minPos];
			heap->tree[minPos] = heap->tree[indexPos];
			heap->tree[indexPos] = swap_temp;

			// Move down one level in the tree to continue heapifying.
			indexPos = minPos;
		}

	}

	return 0;
}

