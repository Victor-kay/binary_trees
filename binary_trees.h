#ifndef UNIQUE_BINARY_TREES_H
#define UNIQUE_BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Unique Binary Tree Node Structure */
struct unique_binary_tree_node {
    int data;
    struct unique_binary_tree_node *parent;
    struct unique_binary_tree_node *left;
    struct unique_binary_tree_node *right;
};

typedef struct unique_binary_tree_node unique_binary_tree_t;
typedef struct unique_binary_tree_node unique_bst_t;
typedef struct unique_binary_tree_node unique_avl_t;
typedef struct unique_binary_tree_node unique_heap_t;

/* Level Order Traversal Queue Structure */
typedef struct unique_levelorder_queue {
    unique_binary_tree_t *node;
    struct unique_levelorder_queue *next;
} unique_levelorder_queue_t;

/* Printing Helper Function */
void unique_binary_tree_print(const unique_binary_tree_t *);

/* Unique Task Function Prototypes */
unique_binary_tree_t *unique_binary_tree_node(unique_binary_tree_t *parent, int value);
unique_binary_tree_t *unique_binary_tree_insert_left(unique_binary_tree_t *parent, int value);
unique_binary_tree_t *unique_binary_tree_insert_right(unique_binary_tree_t *parent, int value);
void unique_binary_tree_delete(unique_binary_tree_t *tree);
int unique_binary_tree_is_leaf(const unique_binary_tree_t *node);
int unique_binary_tree_is_root(const unique_binary_tree_t *node);
void unique_binary_tree_preorder(const unique_binary_tree_t *tree, void (*func)(int));
void unique_binary_tree_inorder(const unique_binary_tree_t *tree, void (*func)(int));
void unique_binary_tree_postorder(const unique_binary_tree_t *tree, void (*func)(int));
size_t unique_binary_tree_height(const unique_binary_tree_t *tree);
size_t unique_binary_tree_depth(const unique_binary_tree_t *tree);
size_t unique_binary_tree_size(const unique_binary_tree_t *tree);
size_t unique_binary_tree_leaves(const unique_binary_tree_t *tree);
size_t unique_binary_tree_nodes(const unique_binary_tree_t *tree);

/* Add more function prototypes as needed */

#endif /* UNIQUE_BINARY_TREES_H */
