#include "binary_trees.h"

/**
  * maxDepth - calculates max depth of a binary tree
  * @node: head node
  * Return: max depth
  */

int maxDepth(const binary_tree_t *node)
{
	int lDepth, rDepth;

	if (node == NULL)
		return (-1);

	lDepth = maxDepth(node->left);
	rDepth = maxDepth(node->right);

	if (lDepth > rDepth)
		return (lDepth + 1);
	else
		return (rDepth + 1);
}

/**
  * binary_tree_balance - compute balance factor of binary tree
  * @tree: pointer to head node
  * Return: balance factor
  */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (maxDepth(tree->left) - maxDepth(tree->right));
}

/**
  * binary_tree_is_perfect - check is binary tree is perfect
  * @tree: pointer to root of binary tree
  * Return: 1 is perfect tree 0 otherwise
  */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int b_factor;

	if (tree == NULL)
		return (0);

	b_factor = binary_tree_balance(tree);
	if (b_factor == 0)
		return (1);
	else
		return (0);
}
