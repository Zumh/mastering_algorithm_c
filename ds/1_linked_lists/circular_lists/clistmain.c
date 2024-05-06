#include <stdio.h>
#include <stdlib.h>

#include "clist.h"

static void print_list(const CList *list);

// print_list

int main(void){
    CList list;
    CListNode *node;

    int *data;

    // INITIALIZE THE CIRCULAR LINKED LIST
    // intialize the circular linked list
    clist_init(&list, free);

    // PERFORM CIRCULAR LINKED LIST OPERATIONS 

    // get the head 
    node = clist_head(&list);

    // start from 0 to 10 and insert them in the linked list
    for (int i = 0; i < 10; i++){

        // get the size of the individual data for inserting into the node
        if((data = (int *) malloc(sizeof(int))) == NULL){
            return 1;
        }


        *data = i + 1;

        // insert the first number to the head 
        // insert the rest of the number between each node
        
        if (clist_ins_next(&list, node, data) != 0) {
            // fail to insert the data 
            return 1;
        }

        if (node == NULL){
            node = clist_next(clist_head(&list));
        } else {
            node = clist_next(node); 
        }
    }

    // print the list 

    print_list(&list);

    // CIRCLING AND REMOVING AN ELEMENT AFTER THE ONE CONTAINING

    node = clist_head(&list);

    // iterate through the list and using for loop
    for(int i = 0; i < 10; i++){
        node = clist_next(node);
    }

    // extract the data from the clist
    data = clist_data(node);

    printf("Circling and removing a node after the one containing %03d\n", *data);

    if (clist_rem_next(&list, node, (void **)&data) != 0){
        return 1;
    }

    free(data);
    print_list(&list);


    // get the head of the list
    node = clist_head(&list);

    for(int i = 0; i < 15; i++){
        node = clist_next(node);
    }

    data = clist_data(node);
    

    

    // destroy the list
    printf("Destroying the list \n");
    clist_destroy(&list);
    return 0;
}

static void print_list(const CList *list){

    CListNode *node;

    int *data, size;

    // display the circular linked list

    printf("List size is %d (circling twice)\n", clist_size(list));

    size = clist_size(list);
    node = clist_head(list);

    // Iterate twice through the circular list to veriify the circular links.

    int i = 0;

    while (i < size){
        // extract the data
        data = clist_data(node);

        printf("list [%03d]=%03d\n", (i % size), *data);

        node = clist_next(node);

        i++;
    }

    return;
}