#include "binary_trees.h"

/**
 * binary_tree_insert_left - This func inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: Rep a pointer to the node to insert the left-child in.
 * @value: This is the value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - returns a pointer to the new node.
 *
 * Description: If parent has a left-child already, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
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

