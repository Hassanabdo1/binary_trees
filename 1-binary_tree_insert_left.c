#include "binary_trees.h"

/**
 * Function: binary_tree_insert_left
 * -----------------------------------
 * Inserts a new node as the left child of the given parent node.
 *
 * @parent: Pointer to the parent node where the new node will be inserted as left child.
 * @value: Value to be assigned to the new node.
 *
 * Returns:
 *      - Pointer to the newly created binary tree node on success.
 *      - NULL if memory allocation fails or if the parent node is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}

