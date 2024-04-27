/*
file: single_linked_list.c
description: implement a single linked list
*/

#include <stdio.h>
#include <string.h>

#include "list.h"


void list_init(List *list, void (*destroy)(void *data)) {
   // initialize the list
   list->destroy = destroy;
   list->head = NULL;
   list->tail = NULL;
   list->size = 0;
   return;
}

int list_size(List *list) {
    // return the size of the list
    return list->size;
}
void list_destroy(List *list) {
    // destroy the list
   void *data;
   // remove each element
   while (list_size(list) > 0) {
      if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
         // call a user defined function to destroy the data
         list->destroy(data);
      }
   }     
   // No operations are allowed now, but clear the structure as a precaution.
   memset(list, 0, sizeof(List)); 
   return;
}

int main() {
    List list;
    list_init(&list, free);
    return 0;
}