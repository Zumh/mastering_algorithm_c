// Description: Illustrate using a binary search tree (see Chapter 9) of mastering algorithm with C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bistree.h"


// Define the size of strings
#define STRSIZ  6

int inserting_nodes(BiTree *tree, char sarray[][STRSIZ], int word);

static void preorder_tree(const BiTreeNode *node){
    // Display the binary search tree rooted at the spcified node.

    if (!bitree_is_eob(node)){
        fprintf(stdout, "Node=%s, %+2d, hidden=%d\n", (char *)((AvlNode *) bitree_data(node))->data, ((AvlNode *) bitree_data(node))->factor, ((AvlNode *)bitree_data(node))->hidden);

        if(!bitree_is_eob(bitree_left(node))){
            preorder_tree(bitree_left(node));
        }


        if(!bitree_is_eob(bitree_right(node))){
            preorder_tree(bitree_right(node));
        }
    }

    return;
}

// compare_str
static int compare_str(const void *str1, const void *str2){
    int retval;

    // Compare two strings.

    if((retval = strcmp((const char *) str1, (const char *)str2)) > 0){
        return 1;
        
    } else if (retval < 0){
        return -1;
    } else {
        return 0;
    }

  

}

// Define an enum for various words to search

typedef enum Words_ {hop, hat, tap, bat, tip, mop, mom, cat, zoo, wax, top, dip} Words;

void intialize_datas(char sarray[][STRSIZ]);


int main(int argc, char **argv){
    BiTree tree;
    char *target;
    char sarray[12][STRSIZ], tarray[12][STRSIZ];

    // Load an array with the data to search.
    intialize_datas(sarray);


    // Initialize the binary search tree.
    bistree_init(&tree, compare_str, NULL);

    // Perform some binary search tree operations.

    fprintf(stdout, "Inserting some nodes\n");

    if (inserting_nodes(&tree, sarray, tap) == 1) return 1;
    if (inserting_nodes(&tree, sarray, tip) == 1) return 1;

    if(inserting_nodes(&tree, sarray, top) == 1) return 1;
    if (inserting_nodes(&tree, sarray, cat) == 1) return 1;
    if (inserting_nodes(&tree, sarray, bat) == 1) return 1;
    

    // Destroy the binary search tree.

    fprintf(stdout, "Destroying the tree\n");
    bistree_destroy(&tree);
    return 0;



}

void intialize_datas(char sarray[][STRSIZ]){
    strcpy(sarray[hop], "hop");
    strcpy(sarray[hat], "hat");
    strcpy(sarray[tap], "tap");
    strcpy(sarray[bat], "bat");
    strcpy(sarray[tip], "tip");
    strcpy(sarray[mop], "mop");
    strcpy(sarray[mom], "mom");
    strcpy(sarray[cat], "cat");
    strcpy(sarray[zoo], "zoo");
    strcpy(sarray[wax], "wax");
    strcpy(sarray[top], "top");
    strcpy(sarray[dip], "dip");
}

int inserting_nodes(BiTree *tree, char sarray[][STRSIZ], int word){
    
    if(bistree_insert(tree, sarray[word]) != 0){
        return 1;
    }

    fprintf(stdout, "Tree size is %d\n", bistree_size(tree));
    fprintf(stdout, "(Preorder traversal)\n");
    preorder_tree(bitree_root(tree));
}