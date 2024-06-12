## Left rotation
Sure, I can help illustrate the `rotate_left` function with diagrams for both LL and LR rotations.

### Case 1: LL Rotation

An LL (Left-Left) rotation is performed when the left child of a node is left-heavy. Here's a step-by-step illustration:

#### Before LL Rotation

```
      A
     / \
    B   C
   / \
  D   E
```

Assume:
- `A` is the current node.
- `B` is the left child of `A`.
- `D` and `E` are children of `B`.

The balance factors before rotation:
- `A`: `AVL_LFT_HEAVY`
- `B`: `AVL_LFT_HEAVY`
- `D`, `E`, `C`: `AVL_BALANCED`

#### After LL Rotation

```
      B
     / \
    D   A
       / \
      E   C
```

- The left child `B` becomes the new root of the subtree.
- `A` becomes the right child of `B`.
- The subtree rooted at `D` remains unchanged.
- The subtree rooted at `E` becomes the left child of `A`.

Balance factors after rotation:
- `B`: `AVL_BALANCED`
- `A`: `AVL_BALANCED`
- `D`, `E`, `C`: `AVL_BALANCED`

### Case 2: LR Rotation

An LR (Left-Right) rotation is performed when the left child of a node is right-heavy. Here's a step-by-step illustration:

#### Before LR Rotation

```
      A
     / \
    B   C
     \
      D
     / \
    E   F
```

Assume:
- `A` is the current node.
- `B` is the left child of `A`.
- `D` is the right child of `B`.
- `E` and `F` are children of `D`.

The balance factors before rotation:
- `A`: `AVL_LFT_HEAVY`
- `B`: `AVL_RGT_HEAVY`
- `D`: `AVL_BALANCED` (could be any value, but for illustration, we use `AVL_BALANCED`)
- `E`, `F`, `C`: `AVL_BALANCED`

#### After LR Rotation

```
      D
     / \
    B   A
   /   / \
  E   F   C
```

- The right child `D` of `B` becomes the new root of the subtree.
- `B` becomes the left child of `D`.
- `A` becomes the right child of `D`.
- The subtree rooted at `E` becomes the left child of `B`.
- The subtree rooted at `F` becomes the left child of `A`.

Balance factors after rotation:
- `D`: `AVL_BALANCED`
- `B`: `AVL_BALANCED`
- `A`: `AVL_BALANCED`
- `E`, `F`, `C`: `AVL_BALANCED`

### Code Explanation with Diagrams

1. **LL Rotation:**

```c
if (((AvlNode *) bitree_data(left))->factor == AVL_LFT_HEAVY) {
    // Perform an LL rotation.
    bitree_left(*node) = bitree_right(left);
    bitree_right(left) = *node;

    ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
    ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;

    *node = left;
}
```

- `bitree_left(*node) = bitree_right(left);` 
  - Moves `E` to be the left child of `A`.
- `bitree_right(left) = *node;`
  - Makes `A` the right child of `B`.
- Balance factors are updated to `AVL_BALANCED` for both `A` and `B`.
- `*node = left;`
  - Updates the root of the subtree to `B`.

2. **LR Rotation:**

```c
else {
    grandchild = bitree_right(left);
    bitree_right(left) = bitree_left(grandchild);
    bitree_left(grandchild) = left;
    bitree_left(*node) = bitree_right(grandchild);
    bitree_right(grandchild) = *node;

    switch(((AvlNode *) bitree_data(grandchild))->factor) {
        case AVL_LFT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_RGT_HEAVY;
            ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
            break;
        case AVL_BALANCED:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
            break;
        case AVL_RGT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(left))->factor = AVL_LFT_HEAVY;
            break;
    }

    ((AvlNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
}
```

- `grandchild = bitree_right(left);`
  - Identifies `D` as the grandchild.
- `bitree_right(left) = bitree_left(grandchild);`
  - Moves `E` to be the right child of `B`.
- `bitree_left(grandchild) = left;`
  - Makes `B` the left child of `D`.
- `bitree_left(*node) = bitree_right(grandchild);`
  - Moves `F` to be the left child of `A`.
- `bitree_right(grandchild) = *node;`
  - Makes `A` the right child of `D`.
- Updates balance factors based on the grandchild's factor.
- `*node = grandchild;`
  - Updates the root of the subtree to `D`.

### Summary

These diagrams and explanations illustrate how the `rotate_left` function maintains the AVL tree's balance by performing the necessary rotations and updating balance factors.