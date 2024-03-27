#include "binary_trees.h"

/**
 * struct node_s - Is a singly linked list
 * @node: Is a const binary tree node
 * @next: This points to the next node
 */

typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - This goes through a binary tree
 *                          using level-order traversal.
 * @tree: Is a pointer to the root node of the tree to traverse.
 * @func: Is a pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - This calls func on all nodes at each level.
 * @head: Is a pointer to head of linked list with nodes at one level.
 * @func: Is a pointer to a function to call for each node.
 */

void levels_rec(ll *head, void (*func)(int));
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - This appends children of parent to linked list.
 * @head: Is a pointer to head of linked list where children 
 * ...will be appended.
 * @parent: Is a pointer to node whose children we want to append.
 * Return: Is a pointer to head of linked list of children.
 */

ll *get_children(ll *head, const binary_tree_t *parent);
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - This adds a new node at the end of a linkedlist
 * @head: Is a pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */

ll *append(ll *head, const binary_tree_t *btnode);
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - This frees all the nodes in a linked list
 * @head: Is a pointer to the head of list_t linked list
 */

void free_list(ll *head);
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
