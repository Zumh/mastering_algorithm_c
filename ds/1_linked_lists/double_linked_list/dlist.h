/*
file: dlist.h
Description: This file contains the class definition for the double linked list
*/

#ifndef DLIST_H
#define DLIST_H
#include <stdlib.h>

// Define a structure for doubly linked list nodes.

typedef struct DListNode_ {
    int *data;
    struct DListNode_ *next;
    struct DListNode_ *prev;

} DListNode;

// Define a structure for doubly linked lists

typedef struct DList_ {
    // size 
    int size;
    // methods for 
    // match
    int (*match)(const void *key1, const void *key2);
    // destroy the data 
    void (*destroy)(void *data);
    // head and tail
    DListNode *head;
    DListNode *tail;
} DList;


// Public Interface 
void dlist_init(DList *list, void(*destroy) (void *data));
void dlist_destroy(DList *list);

int dlist_ins_next(DList *list, DListNode *node, const void *data);
int dlist_ins_prev(DList *list, DListNode *node, const void *data);
int dlist_remove(DList *list, DListNode *node, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_tail(list)((list)->tail)
#define dlist_head(list)((list)->head)

#define dlist_data(list)((list)->data)
#define dlist_next(list)((list)->next)
#define dlist_prev(list)((list)->prev)

#define dlist_is_head(list)((list)->prev == NULL ? 1: 0)
#define dlist_is_tail(list)((list)->next == NULL ? 1: 0)

#endif