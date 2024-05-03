#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dlist.h"

//dlist_init initialize for this doubly linked list
void dlist_init(DList *list, void(*destroy) (void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}

// dlist destroy
void dlist_destroy(DList *list){
    void *data;
    // destroy all the data until the size reach to zero
    while(dlist_size(list) > 0 ){
        if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && (list->destroy != NULL)){
            // Calling a user defined function to free dynamically allocated data.
            list->destroy(data);
        }
    }

    // No operation is allow now but clear the structure as precaution

    memset(list, 0, sizeof(DList));

    return;
}

// insert data next
int dlist_ins_next(DList *list, DListNode *node, const void *data){
    DListNode *new_node;

    // Do not allow a NULL node unless the list is empty

    if(node == NULL && dlist_size(list) != 0){
        return -1;
    }

    // allocate storage for the node
    if((new_node = (DListNode *) malloc(sizeof(DListNode))) == NULL){
        return -1;
    }

    // insert new node into the list
    new_node->data = (void *)data;
    if(dlist_size(list) == 0){
        // Handle insertion when the list is empty.
        list->head = new_node;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_node;
    } else {
        // Handle insertion when the list is not empty
        new_node->next = node->next;
        new_node->prev = node;

        if (node->next == NULL){
            // if current node is the last node 
            // update the tail with a new node
            // the new node is the last node
            list->tail = new_node;
        } else {
            // if current node is not the last node
            // insert a new node in between current node and next node
            // in this case 
            node->next->prev = new_node;
        }
        node->next = new_node;
    }

    // Adjust the size of the list to account for the inserted node.
    list->size++;
    return 0;
}


// dlist_ins_prev

int dlist_ins_prev(DList *list, DListNode *node, const void *data){
    DListNode *new_node;

    // Do not allow a NULL node uless the list is empty
    if (node == NULL && dlist_size(list) != 0) {
        return -1;
    }

    // Allocate storage to be managed by the abstract datatype.
    if ((new_node = (DListNode *) malloc(sizeof(DListNode))) == NULL) {
        return -1;
    }

    // Insert the new node into the list
    new_node->data = (void *) data;

    if(dlist_size(list) == 0) {
        // Handle insertion when the list is empty
        list->head = new_node;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_node;
    } else {
        // Handle insertion when the list is not empty
        // new_node is inserted before the current node
        new_node->next = node;
        new_node->prev = node->prev;

        // if the current node is the head then update the head with a new node
        if(node->prev == NULL){
            list->head = new_node;
        } else {
            // otherwise insert the node in between current node and previous node
            node->prev->next = new_node;

        }

        // update current node previous node
        node->prev = new_node;

    }

    // Adjust the size of the list to account for the new node.
    list->size++;
    return 0;
}

// dlist remove

int dlist_remove(DList *list, DListNode *node, void **data){
    // Do not allow a NULL node or removal from an empty list

    if(node == NULL || dlist_size(list) == 0){
        return -1;
    }

    // REmove the node from the list

    *data = node->data;

    // if the current node is the head of the list
    if(node == list->head){
        // Handle remove from the head of the list.
        // update the next head of the list
        list->head = node->next;

        if(list->head == NULL){
            // update the tail if its empty because this is the end of the list
            list->tail = NULL;
        } else {
            // otherwise let the next node previous point to NULL
            // because node is the head now
            node->next->prev = NULL;
        }
    } else {
        // if the node is not the head
        // Handle removal from other than the head of the list

        // before the current node point to the next node
        node->prev->next = node->next;

        if(node->next == NULL){
            // update the tail if its empty because this is the end of the list
            list->tail = node->prev;
        } else {
            // otherwise let the next node previous point to the previous node
            // update the previous node of the next node
            // basically current node cut the connection from previous node and the next node
            node->next->prev = node->prev;
        }

    }

    // Free the storage allocated by the abstract datatype.

    free(node);

    // Adjust the size of the list to account for the removed node.

    list->size--;

    return 0;
}

