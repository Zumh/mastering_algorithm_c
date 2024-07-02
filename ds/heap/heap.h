// Heap.h

#ifndef _HEAP_H
#define _HEAP_H

// Define a structure for heaps.

typedef struct Heap_ {
	int size;
	
	int (*compare)(const void *key1, const void *key2);

	/*
	 
	   The destroy function pointer is typically used in situations where you want to pass a function as an argument, store a function in a data structure, or have the flexibility to change the function being called at runtime. It's commonly used in contexts such as callbacks, event handling, and polymorphism in C.

	   void (*destroy)(void *data); is a declaration of a function pointer that can point to any function that takes a void* argument and returns void. This allows for flexibility in code, enabling dynamic function calls and providing a way to handle different types of cleanup or destruction functions.
	 *
	

	*/
	void (*destroy)(void *data);

	void **tree;
	
} Heap;

// initialize the heap with function pointer like compare and destroy
void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data));


// destroy the heap tree
void heap_destroy(Heap *heap);

// Insert an element into the heap
int heap_insert(Heap *heap, const void *data);

// we use double pointer for parameter because we going to modify the data.
int heap_extract(Heap *heap, void **data);

#define heap_size(heap) ((heap)->size)
#endif
