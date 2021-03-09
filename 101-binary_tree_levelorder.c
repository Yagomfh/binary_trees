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
  * print_level - prints a level in binary tree
  * @root: pointer to root
  * @level: level to print
  * @func: function used to print
  * Return: void
  */

void print_level(const binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		print_level(root->left, level - 1, func);
		print_level(root->right, level - 1, func);
	}
}

/**
  * binary_tree_levelorder - goes through a binary tree using
  * level-order traversal
  * @tree: pointer to root node
  * @func: poitnto printf
  * Return: void
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree) + 1;
	for (i = 1; i <= height; i++)
		print_level(tree, i, func);
}
