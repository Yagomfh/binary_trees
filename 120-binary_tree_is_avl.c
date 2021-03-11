#include "binary_trees.h"

/**
 * is_BST_Util - check if binary tree is a valid Binary Search Tree
 * @tree: pointer to root node
 * @min: minimun value
 * @max: max value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_BST_Util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_BST_Util(tree->left, min, tree->n - 1) &&
			is_BST_Util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_BST_Util(tree, INT_MIN, INT_MAX));
}

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
  * binary_tree_is_avl - checks if binary tree is AVL
  * @tree: pointer to root node
  * Return: 1 is it's avl or 0 otherwise
  */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (abs(binary_tree_balance(tree)) == 0 && binary_tree_is_bst(tree) == 1)
		return (1);
	else
		return (0);
}
