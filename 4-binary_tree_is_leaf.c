#include "binary_trees.h"

/**
 * Function: binary_tree_is_leaf
 * ------------------------------
 * Checks if a given node is a leaf node in a binary tree.
 *
 * @node: Pointer to the node to be checked.
 *
 * Returns:
 *      - 1 if the node is a leaf node.
 *      - 0 if the node is NULL or if it has at least one child.
 */

int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}

