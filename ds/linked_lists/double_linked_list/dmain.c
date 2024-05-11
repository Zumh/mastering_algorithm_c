#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

// print list 
void print_list(const DList *list);

int main() {
    DList list;
    DListNode *node;

    int *data;

    // IINITIALIZE THE DOUBLY LINKED LIST
    // intialize the doubly linked list
    dlist_init(&list, free);

    // Perform some doubly linked list operations
    node = dlist_head(&list);

    for(int i = 10; i > 0; i--){
        if ((data = (int *) malloc(sizeof(int)))  == NULL){
            return 1;
        }

        *data = i;

        if(dlist_ins_prev(&list, dlist_head(&list), data) != 0){
            return 1;
        }
    }

    print_list(&list);




    // REMOVE NODE AFTER ON CONTAINING
    node = dlist_head(&list);
    
    // traverse the list of the node until the 8th
    for(int i = 0; i < 8; i++){
        node = dlist_next(node);

    }

    // extract the data from the list
    data = dlist_data(node);

    printf("Removing a data after the one containing %03d\n", *data);

    if (dlist_remove(&list, node, (void**)&data) != 0) {
        return 1;
    }
    printf("Removed data: %03d\n", *data);
    print_list(&list);

    // INSERTING 12 Just before THE END OF THE LIST
    printf("Inserting 12 just before at the end of the list\n");

    *data = 12;

    if(dlist_ins_prev(&list, dlist_tail(&list), data) != 0){
        return 1;

    }

    print_list(&list);


    // ITERATING AND REMOVING THE FOURTH NODE
    printf("Iterating and removing the fourth node\n");

    node = dlist_head(&list);
    printf("Head or the start of the node: %d\n", *dlist_data(node));
    node = dlist_next(node);
    printf("Next of the start of the node: %d\n", *dlist_data(node));
    node = dlist_prev(node);
    printf("The previous node from above node: %d\n", *dlist_data(node));
    node = dlist_next(node);
    printf("The next node from above node: %d\n", *dlist_data(node));
    node = dlist_prev(node);
    printf("The previous node from above node: %d\n", *dlist_data(node));
        
    node = dlist_next(node);
    printf("The next node from above node: %d\n", *dlist_data(node));
    node = dlist_next(node);
    printf("The next node from above node: %d\n", *dlist_data(node));
    node = dlist_next(node);
    printf("The next node from above node: %d\n", *dlist_data(node));

    if(dlist_remove(&list, node, (void**)&data) != 0){
        return 1;
    }


    printf("Removed data: %03d\n", *data);

    print_list(&list);


    // INSERTING 13 BEFORE THE FIRST ELEMENT
    printf("Inserint 013 beore the first node\n");

    *data = 13;

    if(dlist_ins_prev(&list, dlist_head(&list), data) !=0){
        return 1;
    }

    print_list(&list);



    // REMOVING NODE AT THE HEAD OF THE LIST
    printf("Removing node at the head of the list\n");

    if(dlist_remove(&list, dlist_head(&list), (void **)&data) != 0){
        return 1;
    }
    printf("Removed data: %d\n", *data);
    print_list(&list);



    // INSERTING 14 JUST AFTER THE HEAD OF THE LIST
    printf("Inserting 14 just after the head of the list\n");
    *data = 14;

    if(dlist_ins_next(&list, dlist_head(&list), data) != 0){
        return 1;
    }
    printf("Inserted value: %03d\n", *data);
    print_list(&list);

    // INSERTING 15 TWO NODES AFTER THE HEAD OF THE LIST

    // allocate space for data seprately from the previous data.
    // so that if we change the value it won't effect the previous data.
    if((data = (int*) malloc(sizeof(int))) == NULL){
        return 1;
    }

    *data = 15;
    printf("Inserting 15 two nodes after the head of the list\n");
    node = dlist_head(&list);
    node = dlist_next(node);

    if(dlist_ins_next(&list, node, data) != 0){
        return 1;
    }

    print_list(&list);

    // testing head and tails
    int i = dlist_is_head(dlist_head(&list));

    fprintf(stdout, "Testing dlist_is_head...Value=%d (1=OK)\n", i);

    i = dlist_is_head(dlist_tail(&list));

    fprintf(stdout, "Testing dlist_is_head...Value=%d (0=OK)\n", i);


    // testing if the list is a tail
    i = dlist_is_tail(dlist_tail(&list));
   
    fprintf(stdout, "Testing dlist_is_tail...Value=%d (1=OK)\n", i);

    i = dlist_is_tail(dlist_head(&list));

    fprintf(stdout, "Testing dlist_is_tail...Value=%d (0=OK)\n", i);


    // Destroy the doubly linked list
    printf("Destroying the doubly_linked_list\n");
    dlist_destroy(&list);
    printf("List size is %d\n", dlist_size(&list));


    return 0;
}

// display doubley linked list
void print_list(const DList *list){

    DListNode *node;
    int *data;

    // display the doubly linked list
    printf("List size is %d\n", dlist_size(list));

    // get the head first 
    node = dlist_head(list);
    int i = 0;
    while(1) {
        // extract the data here
        data = dlist_data(node);

        // print the data 
        printf("list [%03d]=%03d\n", i, *data);
        
        // check if this is a tail
        if(dlist_is_tail(node)){
            break;
        } else {
            node = dlist_next(node);
        }
        i++;
    }

    return;
}