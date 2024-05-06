/*
File: clistPage.c
Description: implement second change page replacement
*/

#include <stdio.h>
#include "page.h"
#include <stdlib.h>

int main(int argc, char **argv){
    CList list;
    CListNode *current;

    Page *p;

    // Initialize the circular list.

    clist_init(&list, free);

    // Load a page into the list

    current = NULL;

    for (int i = 0; i < 10; i++){
        if ((p = (Page *) malloc(sizeof(Page))) == NULL) {
            return 1;
        }

        if (i < 5 ) {
            p-> reference = 1;
        } else {
            p-> reference = 0;
        }

        p-> number = i;

        if (clist_ins_next(&list, current, p) != 0){
            return 1;
        }

        if (current == NULL){
            current = clist_next(clist_head(&list));
        } else {
            current = clist_next(current);
        }
    }

    current = clist_head(&list);

    for(int i = 0; i < 10; i++){
        p = clist_data(current);

        printf("p[%d].number=%d, p[%d],reference=%d\n", i, p->number, i, p->reference);

        current = clist_next(current);
    }

    // Destroy the circular list.

    printf("Destroying the list\n");

    clist_destroy(&list);


    return 0;
}