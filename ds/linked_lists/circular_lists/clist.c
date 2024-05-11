/*
File: clist.c
Description: implement a circular linked list
*/

#include <stdlib.h>
#include <string.h>

#include "clist.h"

// clist init

void clist_init(CList *list, void (*destroy)(void *data)) {
    list->destroy = destroy;
    list->head = NULL;
    list->size = 0;
}

// clist destroy 
void clist_destroy(CList *list){
    void *data;
    // Remove node 
    while (clist_size(list) > 0) {
        if (clist_rem_next(list, list->head ,(void **)&data) == 0 && list->destroy != NULL){
                // call a user defined function to free dynamically allocated data.
                list->destroy(data);
        }
    }

    // No operation is allow now but clear the structure as precaution

    memset(list, 0, sizeof(CList));

    return;
}

// clist insertion to the next
int clist_ins_next(CList *list, CListNode *node, const void *data){
    CListNode *new_node;
    // Allocate storage for node

    new_node = (CListNode *) malloc(sizeof(CListNode)) ;

    if (new_node == NULL) {
        return -1;
    }

    // Insert the node into the list
    new_node->data = (void *)data;

    // check for the size of the list 
    // if the size is empty then that's the head of the list
    if (clist_size(list) == 0) {
        // Handle insertion when the list is empty

        new_node->next = new_node;
        list->head = new_node;
    } else {
        // Handle insertion when the list is not empty
        new_node->next = node->next;
        node->next = new_node;
    }

    // Adjust the size of the list to account for the inserted node
    list->size++;
    return 0;
    
}

// clist rem next 
int clist_rem_next(CList *list, CListNode *node, void **data){
    CListNode *old_node;

    // Do not allow removal from an empty list

    if(clist_size(list) == 0){
        return -1;
    }

    // Remove node from the list
    *data = node->next->data;

    if(node->next == node){
        // Handle removing the last node
        old_node = node->next;
        list->head = NULL;
    } else {
        // Handle removing other than the node
        old_node = node->next;
        node->next = node->next->next;
        if(old_node == clist_head(list)){
            list->head = old_node->next;
        }
    }

    // Free the storage allocated by the abastract datatype.

    free(old_node);

    // Adjust the size of the list to account for the removed element.
    list->size--;

    return 0;
}


