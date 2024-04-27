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
    
    ListNode *head;
    ListNode *tail;
    int size;
    // here we can define generic methods for manupilating ListNodes
    int (*match) (const void *data1, const void *data2);
    void (*destroy) (void *data);
} List;

// public interface for manupilating linked lists

// intialize the list
void list_init(List *list, void (*destroy) (void *data));
void list_destroy(List *list);

#endif 