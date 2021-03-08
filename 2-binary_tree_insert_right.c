#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to parent node
 * @value: value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp = parent->right, *new_node = malloc(sizeof(binary_tree_t));

	if (parent == NULL || new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		tmp->parent = new_node;
		new_node->right = tmp;
	}
	else
		new_node->right = NULL;
	parent->right = new_node;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->n = value;
	return (new_node);
}
