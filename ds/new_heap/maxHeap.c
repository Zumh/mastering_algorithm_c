#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//int heap[MAX];
//int size = 0;


typedef struct Heap_{
	void *data[MAX];
	int size;
	size_t elementSize;
	int (*compare)(const void *key1, const void *key2);
	void (*swap)(void *key1,  void *key2, size_t size);
	void (*destructor)(void *element);	
} Heap;

void init(Heap *heap, size_t elementSize, int (*compare)(const void *key1, const void *key2), void (*swap)(void *key1,  void *key2, size_t size)){
	
	heap->size = 0;
	heap->elementSize = elementSize;
	heap->compare = compare;
	heap->swap = swap;
}
void genericSwap(void *a, void *b, size_t size) {
	void *temp = malloc(size);
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);

}

void heapifyUp(Heap *heap, int index) {
    int parent = (index - 1) / 2;

    if (index && heap->compare(heap->data[parent], heap->data[index]) < 0){
    	
	    heap->swap(heap->data[parent], heap->data[index], heap->elementSize);
	    heapifyUp(heap, parent);
    }
}

void heapifyDown(Heap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap->size && heap->compare(heap->data[leftChild], heap->data[largest]) > 0){
    	largest = leftChild;
    }
    
    if (rightChild < heap->size && heap->compare(heap->data[rightChild], heap->data[largest]) > 0){
    	largest = rightChild;
    }

    if (largest != index) {
	heap->swap(heap->data[index], heap->data[largest], heap->elementSize);
        heapifyDown(heap, largest);
    }
}

void insert(Heap *heap, void *element) {

	if (heap->size >= MAX){
		fprintf(stderr, "Heap is full\n");
		return;
	}

    heap->data[heap->size] = malloc(heap->elementSize);
    if(heap->data[heap->size] == NULL) {
	    fprintf(stderr, "Memory allocation failed\n");
	    exit(EXIT_FAILURE);
    }
	
    memcpy(heap->data[heap->size], element, heap->elementSize);
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

void *extractMax(Heap *heap) {
	if (heap->size <= 0) {
		printf("Heap is empty\n");
		return NULL;
	}
	void *max = malloc(heap->elementSize);
	if (max == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	memcpy(max, heap->data[0], heap->elementSize);
	free(heap->data[0]);
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	heapifyDown(heap, 0);

	return max;
}

void displayHeap(Heap *heap, void (*printElement)(const void *)) {
    for (int i = 0; i < heap->size; i++) {
	    printElement(heap->data[i]);
	    printf(" ");
    }
    printf("\n");
}

// Comparision function for integers
int compareInt(const void *a, const void *b){
	return (*(int *) a - *(int *) b);
}

// Print function for integers
void printInt(const void *a){
	printf("%d", *(int *) a);
}
// destroy the heap
void destroyHeap(Heap *heap){
	for( int index = 0; index < heap->size; index++) {
		free(heap->data[index]);
	}
}
	
int main() {

	Heap heap;

	init(&heap, sizeof(int), compareInt, genericSwap);
	int values[] = {10, 20, 15, 30, 40};	
	int values_size = sizeof(values) / sizeof(values[0]);
	for (int index = 0; index < values_size; index++) {
		insert(&heap, &values[index]);
	}

	printf("Heap: ");
	displayHeap(&heap, printInt);

	int *max = (int *) extractMax(&heap);
	if (max != NULL) {
		printf("Max element: %d\n", *max);
		free(max);
	}

	printf("Heap after extracting max: ");
	displayHeap(&heap, printInt);
	
	// Clean up the heap
	destroyHeap(&heap);	
	fprintf(stdout, "Heap destroyed\n");
	return 0;
}

