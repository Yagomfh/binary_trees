#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the binary tree. If tree is NULL, return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		/* size: number of nodes in a tree */
		size += 1; /* for root */
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		return (size);
	}
	return (0);
}
