
#include <stdlib.h>
#include "frames.h"
#include <stdio.h> // Include for printf
// This main function mimic the behavior of the frames
/*
The alloc_ frame and free_ frame functions employ a linked list to maintain the frames that are available to be allocated. 
The alloc_ frame function retrieves the number of a free frame from a list of available frames. 
Given a specific page, this number is placed in the page table to indicate in which physical frame the page is to reside. 
The free_ frame function accepts a frame number and places it back into the list of available frames once a page has been removed from physical memory. 
Both functions assume that before either is called, the operating system has inserted into the list all frames that it wishes to make available. 
The example for circular lists later in this chapter addresses what happens when alloc_ frame is called and the list is empty.
*/
int main() {
   List frames;
   list_init(&frames, free);

   for (int i = 0; i < 10; i++) {
	   int *frame_number = (int *) malloc(sizeof(int));
	   *frame_number = i;
	   list_ins_next(&frames, NULL, frame_number);
   }
    printf("Before we allocated a frame, List size: %d\n", list_size(&frames));
   //Allocate a frame
   int allocated_frame = alloc_frame(&frames);
   printf("Allocated frame: %d\n", allocated_frame);
   printf("After we allocated a frame, List size: %d\n", list_size(&frames));
// display allocated numbers. Just like frames in physical memory
   for (int i = 0; i < 10; i++) {
	   int *frame_number;
	   list_rem_next(&frames, NULL, (void **)&frame_number);
	   printf("Frame number: %d\n", *frame_number);
   }
    printf("List size: %d\n", list_size(&frames));
   // Free the allocated frame
   int freed = free_frame(&frames, allocated_frame);
    printf("List size: %d\n", list_size(&frames));
   if (freed != 0) {
      printf("Failed %d to free frame\n", allocated_frame);
   } else {
      printf("Freed frame: %d\n", allocated_frame);
   }
   // Clean up the frames list
   list_destroy(&frames);
   return 0;
}

int alloc_frame(List *frames){
	int frame_number, *data;
	if (list_size(frames) == 0){
		return -1;
	} else {
		if (list_rem_next(frames, NULL, (void **)&data) != 0){
			return -1;	
		} else {
			frame_number = *data;
			free(data);	
		}
	}
	return frame_number;
}

int free_frame(List *frames, int frame_number){
	int *data;
	if((data = (int *) malloc(sizeof(int))) == NULL){
		
		return -1;
	}

	*data = frame_number;
	if (list_ins_next(frames, NULL, data) != 0){
		return -1;
	}
	return 0;
}
