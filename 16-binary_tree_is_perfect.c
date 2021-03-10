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

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to root node of the tree
 * Return: number of leaves or 0 is tree == NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_is_perfect - check is binary tree is perfect
 * @tree: pointer to root of binary tree
 * Return: 1 is perfect tree 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h, leaves, expected, exp;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);
	leaves = binary_tree_leaves(tree);
	exp = h;
	expected = 1;
	while (exp != 0)
	{
		expected *= 2;
		exp--;
	}
	if (leaves == expected)
		return (1);
	else
		return (0);
}
