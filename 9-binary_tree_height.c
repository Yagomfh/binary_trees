#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:a pointer to the root node of the tree to measure the height.
 * Return: height of bianry tree. If tree is NULL, your function must return 0
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	if (l_height > r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}
