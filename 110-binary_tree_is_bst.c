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
