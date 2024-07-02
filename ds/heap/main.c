/*****************************************************************************
*                                                                            *
*  ex-1.c                                                                    *
*  ======                                                                    *
*                                                                            *
*  Description: Illustrates using a heap (see Chapter 10).                   *
*                                                                            *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

/*****************************************************************************
*                                                                            *
*  ------------------------------ print_heap ------------------------------  *
*                                                                            *
*****************************************************************************/

static void print_heap(Heap *heap) {

int                i;

/*****************************************************************************
*                                                                            *
*  Display the heap using in level order.                                    *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Heap size is %d\n", heap_size(heap));

for (i = 0; i < heap_size(heap); i++)
   fprintf(stdout, "Node=%03d\n", *(int *)heap->tree[i]);

return;

}

/*****************************************************************************
*                                                                            *
*  ------------------------------ compare_int -----------------------------  *
*                                                                            *
*****************************************************************************/

static int compare_int(const void *int1, const void *int2) {

/*****************************************************************************
*                                                                            *
*  Compare two integers.                                                     *
*                                                                            *
*****************************************************************************/

if (*(const int *)int1 > *(const int *)int2)
   return 1;
else if (*(const int *)int1 < *(const int *)int2)
   return -1;
else
   return 0;

}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv) {

Heap               heap;

void               *data;

int                intval[30],
                   i;

/*****************************************************************************
*                                                                            *
*  Initialize the heap.                                                      *
*                                                                            *
*****************************************************************************/

heap_init(&heap, compare_int, NULL);

/*****************************************************************************
*                                                                            *
*  Perform some heap operations.                                             *
*                                                                            *
*****************************************************************************/
int values[] = {5, 10, 20, 1, 25, 22, 9};

for (int index = 0; index < sizeof(values) / sizeof(values[0]); index++) {
	intval[index] = values[index];
	fprintf(stdout, "Inserting %03d\n", intval[index]);
	if (heap_insert(&heap, &intval[index]) != 0){
		fprintf(stderr, "Error Inserting %03d into the heap\n", intval[index]);
		return 1;
	}

	print_heap(&heap);
}
while (heap_size(&heap) > 0) {

   if (heap_extract(&heap, (void **)&data) != 0)
      return 1;
   fprintf(stdout, "Extracting %03d\n", *(int *)data);
   print_heap(&heap);

}

/*****************************************************************************
*                                                                            *
*  Destroy the heap.                                                         *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Destroying the heap\n");
heap_destroy(&heap);

return 0;

}

