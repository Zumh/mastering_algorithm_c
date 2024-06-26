/*
File: stack.h
Description: This file implements the stack data structure using linked list
*/

#include <stdio.h>

#include "list.h"

// implement stacks as linked lists

typedef List Stack;

// Public interface

#define stack_init list_init
#define stack_destroy list_destroy
int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);
#define stack_peek(stack) ((stack)->head = NULL ? NULL : (stack)->head->data)
#define stack_size list_size