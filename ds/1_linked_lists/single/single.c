/*
file: main.c
description: this file will illustrated single linked list
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define DATA_SIZE 10
static void print_list(const List *list);


int main(void){
    List list;
    ListNode *node;

    int *data;

    // INITIALIZING THE LIST 
    list_init(&list, free);

    // insert data into the linked list
    // first get the head of the list
    node = list_head(&list);

    // start from 0 to 10 and insert them in the linked list
    for (int i = 10; i >= 0; i--){
        // we have to allocate the data for this number
        data = (int *) malloc(sizeof(int));
        *data = i;

        // here insert the number that we just allocated in the list
        if (list_ins_next(&list, NULL, data) != 0){
            return -1;
        }

    }
    print_list(&list);




    // REMOVING DATA AFTER THE ONE CONTAINING DATA FROM THE LIST
    // Removing an element after the one containing after the data

    node = list_head(&list);
    for(int i = 0; i < 7; i++){
        node = list_next(node);
    }

    data = list_data(node);

    printf("Removing node after the one containing %03d\n", *data);

    if (list_rem_next(&list, node, (void **)&data) != 0){
        return -1;
    }
    print_list(&list);

    


    // INSERTING DATA IN THE LIST
    printf("Inserting 011 at the tail of the list\n");
    *data = 11;
    if (list_ins_next(&list, list_tail(&list), data) != 0){
        return 1;
    }
    print_list(&list);



    // REMOVING NODE AFTER THE FIRST NODE

    printf("Removing node after the first node\n");

    // get the first node 
    node = list_head(&list);
    // remove the first node here
    if (list_rem_next(&list, node, (void**)&data) != 0){
        return 1;
    }
    print_list(&list);




    // INSERTING 12 AT THE END OF THE LIST

    *data = 12;

    if(list_ins_next(&list, list_tail(&list), data) != 0){
        return 1;
    }
    print_list(&list);




    // ITERATING AND REMOVING THE FOURTH NODE
    printf("Iterating and removing the fourth node\n");

    node = list_head(&list);
    node = list_next(node);
    node = list_next(node);

    if (list_rem_next(&list, node, (void**)&data) != 0){
        return 1;
    }

    print_list(&list);



    // INSERTING 13 AFTER THE FIRST NODE
    printf("Inserting 13 after the first node\n");
    *data = 13;

    if(list_ins_next(&list, list_head(&list), data) != 0){
        return 1;
    }
    
    print_list(&list);


    // TESTING LIST HEAD

    int i = list_is_head(&list, list_head(&list));
    printf("Testing list_is_head...Value=%d (1=OK)\n", i);

    i = list_is_head(&list, list_tail(&list));
    printf("Testing list_is_head...Value=%d (0=OK)\n", i);

    i = list_is_tail(list_tail(&list));
    printf("Testing list_is_tail...Value=%d (1=OK)\n", i);

    i = list_is_tail(list_head(&list));
    printf("Testing list_is_tail...Value=%d (0=OK)\n", i);

    // CLEAN UP THE LIST
    printf("Cleaning up the list\n");
    list_destroy(&list);
    printf("List size: %d\n", list_size(&list));

    return 0;
}


// print_list for printing the single linked list data
static void print_list(const List *list){

    ListNode *node;
    int *data, i; 

    // print the size of the list

    fprintf(stdout, "List size: %d\n", list_size(list));
    
    // dipslay linked list
    i = 0; 
    node = list_head(list);

    while(1) {
        // extract data from the list
        data =  list_data(node);

        fprintf(stdout, "Node %d: %d\n", i, *data);

        if(list_is_tail(node)) {
            break;
        } else {
            node  = list_next(node);
        }

        i++;
    }

    return;

}

