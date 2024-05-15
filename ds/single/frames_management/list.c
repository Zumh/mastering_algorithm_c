/*
file: single_linked_list.c
description: implement a single linked list
*/

#include <stdio.h>
#include <string.h>

#include "list.h"

// this method initialize the list with a destroy function to free the data.
// the destroy function is generic function pointer like a template.
void list_init(List *list, void (*destroy)(void *data)) {
   // initialize the list
   list->destroy = destroy;
   list->head = NULL;
   list->tail = NULL;
   list->size = 0;
   return;
}

// this method destroy the list with a destroy function to free the data.
void list_destroy(List *list) {
   // generic variable to be destroy if the list is not empty
   void *data;
   // remove each element
   // find out the size of the list is not empty
   while (list_size(list) > 0) {
      // if the list is not empty && iterate the next node && the list have a destroy function
      // we can free the data from the list
      if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
         // call a user defined function to destroy the data
         list->destroy(data);
      }
   }     

   // clear the list structure
   // No operations are allowed now, but clear the structure as a precaution.
   memset(list, 0, sizeof(List)); 
   return;
}

int list_rem_next(List *list, ListNode *node, void **data) {
   ListNode *old_node;

   // return if list is empty
   if (list_size(list) == 0) {
      return -1;
   }

   // remove element from the list
   if (node == NULL) {
      // remove from the head
      *data = list->head->data;
      old_node = list->head;
      list->head = list->head->next;

      if (list_size(list) == 1) {
         list->tail = NULL;
      }
   } else {
      // Handle removal from somewhere other than the head.
      *data = node->next->data;
      old_node = node->next;
      node->next = node->next->next;
      if (node->next == NULL) {
         list->tail = node;
      }
   }

   // free the old node
   free(old_node);

   // decrement the list size
   list->size--;
   
   return 0;

    
}

static void print_list(const List *list){
   ListNode *node;
   int *data, i;

   // show the size of a list 
   fprintf(stdout, "list size: %d\n", list_size(list));

   i = 0;
   node = list_head(list);
   while(1){
      // get the data from the node
      data = list_data(node);
      fprintf(stdout, "data [%03d]: %03d\n", i, *data);

      i++;

      if (list_is_tail(node)) {
         break;
      } else {
         node = list_next(node);
      }
   }
   return; 
}

int list_ins_next(List *list, ListNode *node, const void *data) {
   ListNode *new_node;
   // allocate storage for the node
   if ((new_node =(ListNode *) malloc(sizeof(ListNode))) == NULL) {
      // fail to allocate memory for the node
      return -1;
   }

   // insdert node into the list
   new_node->data = (void *)data;

   // check if we are in the start of the list
   // if we are inserting a new node at the head
   if (node == NULL) {
      // insert at the head
      if (list_size(list) == 0) {
	 // update the tail of a list, if the list is empty
	 // indicating this newnode is the tail
         list->tail = new_node;
      }
      // replace what ever the list is pointing to withh a new node next pointer
      new_node->next = list->head;
      // update the head with a new node
      list->head = new_node;
   } else {
      if (node->next == NULL) {
	 // insert at the tail because current node is the last node and we are appending new node 
         list->tail = new_node;
      }
      // insert in the middle by replacing what ever current node pointing at
      new_node->next = node->next;
      // so now current node is pointing at a new node
      // we are inserting a new node just right after current node
      node->next = new_node;
   }
   // adjust the list size
   list->size++;
   return 0;
}


