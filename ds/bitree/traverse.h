// traverse.h
#ifndef TRAVERSE_H
#define TRAVERSE_H
#include "bitree.h"
#include "../single/list.h"

// Public Interface

int preorder(const BiTreeNode *node, List *list);
int inorder(const BiTreeNode *node, List *list);
int postorder(const BiTreeNode *node, List *list);

#endif