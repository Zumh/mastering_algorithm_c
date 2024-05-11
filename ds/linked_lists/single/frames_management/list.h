/**
file: list.h
description: header file for linked lists
*/

#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

// here we define the struct for linked list elements
typedef struct ListNode_ {
    void *data;
    struct ListNode_ *next;
} ListNode;

// here we define the struct for linked lists
typedef struct List_ {
    
    // easier for appending and removing nodes
    ListNode *head;
    ListNode *tail;
    int size;
    // Interface
    // here we can define generic methods for manupilating ListNodes
    int (*match) (const void *data1, const void *data2);
    void (*destroy) (void *data);
} List;

// public interface for manupilating linked lists

// intialize the list
void list_init(List *list, void (*destroy) (void *data));
void list_destroy(List *list);
int list_rem_next(List *list, ListNode *node, void **data);
int list_ins_next(List *list, ListNode *node, const void *data);

// These are macros to help manipulate ListNodes

#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
#define list_next(node) ((node)->next)
#define list_data(node) ((node)->data)
#define list_head(node) ((node)->head)
#define list_size(list) ((list)->size)

#endif 
