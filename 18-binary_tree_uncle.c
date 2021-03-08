#include "binary_trees.h"

/**
  * binary_tree_uncle - find the uncle of node
  * @node: node to find the uncle of
  * Return: pointer to uncle or NULL
  */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandpa;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);

	grandpa = parent->parent;
	if (grandpa == NULL)
		return (NULL);

	if (grandpa->right == parent)
		return (grandpa->left);
	else
		return (grandpa->right);
}
