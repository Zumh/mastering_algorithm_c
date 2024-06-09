// Filename: main.c
// Description: Illustrates using a chaned hash table (see Chapter 8).
// execute:  gcc -o chtbl chtbl.c main.c ../single/list.c

#include <stdio.h>
#include "chtbl.h"
#include "../single/list.h"

// Define the size of the chaned hash table.

#define TBLSIZ 11

// match_char
// we use this generic match char function to compare two characters
// pass it to the chained hash table public interface methods
static int match_char(const void *char1, const void *char2){
    // Compare two characters.

    return (*(const char *) char1 == *(const char *) char2);
}

// h_char
// we use this generic hash char function to hash a character within the table size
static int h_char(const void *key){

    // Define a simplistic hash function.

    return *(const char *) key % TBLSIZ;
}

// print_table
static void print_table(const CHTbl*htbl){
    ListNode *node;
    int i;

    // Display the chained hash table
    fprintf(stdout, "Table size is %d\n", chtbl_size(htbl));

    // Iterate through the table and display each bucket  
    for(int i = 0; i < TBLSIZ; i++){
        fprintf(stdout, "Bucket[%03d]=", i);

        for(node = list_head(&htbl->table[i]); node != NULL; node = list_next(node)){
            fprintf(stdout, "%c", *(char *) list_data(node));
        }

        fprintf(stdout, "\n");
    }
    return;
}

// main

int main(int argc, char **argv) {
    CHTbl htbl;
    char *data, c;

    int retval, i;

    // Iinitialize the chaned hash table.

    if (chtbl_init(&htbl, TBLSIZ, h_char, match_char, free) !=0){

        return 1;
    }

    // Perform some chained hash table operations.

    for(int index = 0; index < TBLSIZ; index++){

        if ((data = (char *) malloc(sizeof(char))) == NULL){

            return 1;
        }

        *data = ((5 + (index * 6)) %23 ) + 'A';


        if (chtbl_insert(&htbl, data) != 0){

            return 1;
        }

        print_table(&htbl);

    }


    for(int index = 0; index < TBLSIZ; index++){

        if ((data = (char *) malloc(sizeof(char))) == NULL){
            return 1;
        }

        *data = ((3 + (i * 4)) % 23) + 'a';

        if (chtbl_insert(&htbl, data) != 0) {
            return 1;
        }

        print_table(&htbl);
    }

    if ((data = (char *) malloc(sizeof(char))) == NULL){
        return 1;
    }

    *data = 'd';

    if ((retval = chtbl_insert(&htbl, data)) != 0){
        free(data);
    }

    fprintf(stdout, "Trying to insert d again...Value=%d (1=OK)\n", retval);

    if((data = (char *) malloc(sizeof(char))) == NULL){
        return 1;
    }

    *data = 'G';

    if ((retval = chtbl_insert(&htbl, data)) != 0){
        free(data);
    }

    fprintf(stdout, "Trying to insert G again...Value=%d (1=OK)\n", retval);

    fprintf(stdout, "Removing d, G, and S\n");

    c = 'd';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0){
        free(data);
    }

    c = 'G';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0){
        free(data);
    }

    c = 'S';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0){
        free(data);
    }

    print_table(&htbl);

    if ((data = (char *)malloc(sizeof(char))) == NULL){

        return 1;
    }

    *data = 'd';

    if ((retval = chtbl_insert(&htbl, data)) != 0){
        free(data);
    }

    fprintf(stdout, "Trying to insert d again...Value=%d (0=OK)\n", retval);

    if ((data = (char *) malloc(sizeof(char))) == NULL){
        return 1;
    }

    *data = 'G';

    if((retval = chtbl_insert(&htbl, data)) != 0){
        free(data);
    }

    fprintf(stdout, "Trying to insert G again...Value=%d (0=OK)\n", retval);

    print_table(&htbl);

    fprintf(stdout, "inserting X and Y\n");

    if ((data = (char *)malloc(sizeof(char))) == NULL){
        return 1;
    }

    *data = 'X';

    if (chtbl_insert(&htbl, data) != 0){
        return 1;
    }

    if ((data = (char *) malloc(sizeof(char))) == NULL) {
        return 1;

    }

    *data = 'Y';

    if (chtbl_insert(&htbl, data) != 0){
        return 1;
    }

    print_table(&htbl);

    c = 'X';
    data = &c;

    if (chtbl_lookup(&htbl, (void **)&data) == 0){
        fprintf(stdout, "Found an occurence of X\n");
    } else {
        fprintf(stdout, "Did not find an occurence of X\n");
    }

    c = 'Z';
    data = &c;

    if (chtbl_lookup(&htbl, (void **)&data) == 0){
        fprintf(stdout, "Found an occurence of Z\n");
    } else {
        fprintf(stdout, "Did not find an occurence of Z\n");
    }




    // Destroy the chained hash table.

    fprintf(stdout, "Destroying the hash table\n");
    chtbl_destroy(&htbl);
    return 0;
}