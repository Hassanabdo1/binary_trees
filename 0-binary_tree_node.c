#include "binary_trees.h"
/*
 * Function: binary_tree_node
 * --------------------------
 * Creates a new binary tree node with the given parent and value.
 *
 * parent: Pointer to the parent node of the new node.
 * value: Value to be assigned to the new node.
 *
 * Returns:
 *      - Pointer to the newly created binary tree node on success.
 *      - NULL if memory allocation fails.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

