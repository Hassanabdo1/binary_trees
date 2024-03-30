#include "binary_trees.h"

/**
 * Function: binary_tree_is_root
 * ------------------------------
 * Checks if a given node is the root node in a binary tree.
 *
 * node: Pointer to the node to be checked.
 *
 * Returns:
 *      - 1 if the node is the root node.
 *      - 0 if the node is NULL or if it has a parent.
 */

int binary_tree_is_root(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}

