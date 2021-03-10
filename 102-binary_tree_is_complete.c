#include "binary_trees.h"

/**
  * total_nodes - computes the total number of nodes
  * @root: pointer to root node
  * Return: number of nodes in bin-tree
  */

unsigned int total_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + total_nodes(root->left) + total_nodes(root->right));
}

/**
  * is_complete - check is a tree is complete
  * @tree: pointer to root node
  * @index: index of node
  * @nodes: total nodes
  * Return: true or false
  */

int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
  * binary_tree_is_complete - checks if a binary tree is complete
  * @tree: pointer to root node
  * Return: true or false
  */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned int index = 0, nb_nodes = total_nodes(tree);

	if (!tree)
		return (0);
	else
		return (is_complete(tree, index, nb_nodes));
}
