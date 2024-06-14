// Description: Illustrates using a heap (see Chapter 10)

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int heap_insert_op(Heap *heap, int *intval, int data);

// print_heap

static void print_heap(Heap * heap){

    // Display the heap using in level order.

    fprintf(stdout, "Heap size is %d\n", heap_size(heap));

    for(int index = 0; index < heap_size(heap); index++){
        fprintf(stdout, "Node=%03d\n", *(int *)heap->tree[index]);
    }

    return;
}

// compare_int
static int compare_int(const void *int1, const void  *int2){
    // Compare two integers.

    if (*(const int *) int1 > *(const int *) int2){
        return 1;
    } else if (*(const int *)int1 < *(const int *)int2){
        return -1;
    } else {
        return 0;
    }
}

// main
int main(int argc, char **argv){
    Heap heap;
    void *data;
    int intval[30];

    // Intialize the heap.
    heap_init(&heap, compare_int, NULL);

    // Perform some heap operations.
    // Insert operations
    int numbers[] = {5, 10,20, 1, 25, 22, 9};
    for (int index = 0; index < sizeof(numbers)/sizeof(int); index++){
        heap_insert_op(&heap, &intval[index], numbers[index]);
    }

    // Extract operations
    while (heap_size(&heap) > 0){
        if (heap_extract(&heap, (void **)&data) != 0){
            return 1;
        }

        fprintf(stdout, "Extracted %03d\n", *(int *)data);
        print_heap(&heap);
    }

    // Destroy the heap.

    fprintf(stdout, "Destroying the heap\n");
    heap_destroy(&heap);

    return 0;
}

int heap_insert_op(Heap *heap, int *intval, int data){
    *intval = data;
    // Insert an integer into the heap.
    fprintf(stdout, "Inserting %03d\n", *intval);
    if(heap_insert(heap, intval) != 0) {
        return 1;
    }
    print_heap(heap);
    
}