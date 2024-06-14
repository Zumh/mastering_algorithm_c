// Description: Illustrate using a binary search tree (see Chapter 9) of mastering algorithm with C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bistree.h"


// Define the size of strings
#define STRSIZ  6


void intialize_datas(char sarray[][STRSIZ]);

void removing_nodes(BiTree *tree, char sarray[][STRSIZ], int word);

int inserting_nodes(BiTree *tree, char sarray[][STRSIZ], int word);

void initailize_traay(char tarray[][STRSIZ]);

void lookup_nodes(BiTree *tree,  char tarray[][STRSIZ], int index);

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

    fprintf(stdout, "\n\nRemoving\n");
    removing_nodes(&tree, sarray, tap);
    removing_nodes(&tree, sarray, top);
    removing_nodes(&tree, sarray, tip);
    removing_nodes(&tree, sarray, hop);

    fprintf(stdout, "\n\nInserting some nodes\n");

    if (inserting_nodes(&tree, sarray, hop) == 1) return 1;
    if (inserting_nodes(&tree, sarray, dip) == 1) return 1;

    if(inserting_nodes(&tree, sarray, tap) == 1) return 1;
    if (inserting_nodes(&tree, sarray, top) == 1) return 1;
    if (inserting_nodes(&tree, sarray, tip) == 1) return 1;

    fprintf(stdout, "\n\nInserting more nodes\n");
    
    if (inserting_nodes(&tree, sarray, mom) == 1) return 1;
    if (inserting_nodes(&tree, sarray, hat) == 1) return 1;

    if(inserting_nodes(&tree, sarray, mop) == 1) return 1;
    if (inserting_nodes(&tree, sarray, wax) == 1) return 1;
    if (inserting_nodes(&tree, sarray, zoo) == 1) return 1;


    // Removing nodes from the tree.
    fprintf(stdout, "\n\nRemoving\n");
    removing_nodes(&tree, sarray, wax);
    removing_nodes(&tree, sarray, hop);

    fprintf(stdout, "\n\nLooking up some nodes\n");

    initailize_traay(tarray);

    lookup_nodes(&tree, tarray, 0);
    lookup_nodes(&tree, tarray, 1);
    lookup_nodes(&tree, tarray, 2);
    lookup_nodes(&tree, tarray, 3);
    lookup_nodes(&tree, tarray, 4);




    // Destroy the binary search tree.

    fprintf(stdout, "\n\nDestroying the tree\n");
    bistree_destroy(&tree);
    return 0;



}

void lookup_nodes(BiTree *tree,  char tarray[][STRSIZ], int index){
    char *target = tarray[index];

    if (bistree_lookup(tree, (void **) &target) == -1){
        fprintf(stdout, "Could not find %s\n", target);
    } else {
        fprintf(stdout, "Found %s\n", target);
    }

}

void removing_nodes(BiTree *tree, char sarray[][STRSIZ], int word){
     fprintf(stdout, "Removing %s \n", sarray[word]);

     if (bistree_remove(tree, &sarray[word]) != 0){
         fprintf(stdout, "Could not find %s\n", sarray[word]);
     } else {
        fprintf(stdout, "Tree size is %d\n", bistree_size(tree));
        fprintf(stdout, "(Preorder traversal)\n");
        preorder_tree(bitree_root(tree));
     }
}

void initailize_traay(char tarray[][STRSIZ]){
    strcpy(tarray[0], "top");

    strcpy(tarray[1], "hop");
    strcpy(tarray[2], "wax");

    strcpy(tarray[3], "hat");
    strcpy(tarray[4], "xxx");
    
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
    fprintf(stdout, "Inserting %s\n", sarray[word]);
    if(bistree_insert(tree, sarray[word]) != 0){
        return 1;
    }

    fprintf(stdout, "Tree size is %d\n", bistree_size(tree));
    fprintf(stdout, "(Preorder traversal)\n");
    preorder_tree(bitree_root(tree));
}