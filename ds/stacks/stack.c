// File: stack.c
// Description: implement a stack using linked list
#include <stdlib.h>

#include "stack.h"
#include "list.h"

// push to the stack
int stack_push(Stack *stack, const void *data){
    // push the data on to the stack
    return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data){
    // pop the data off the stack
    return list_rem_next(stack, NULL, data);
}