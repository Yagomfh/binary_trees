#include "binary_trees.h"

/**
  * binary_tree_rotate_right - performs a right-rotation on a binary tree
  * @tree: pointer to the root node of the tree to rotate
  * Return: pointer to the new root node of the tree once rotated
  */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->left;
	tree->left = pivot->right;

	if (pivot->right != NULL)
		pivot->right->parent = tree;
	pivot->parent = tree->parent;
	pivot->right = tree;
	tree->parent = pivot;
	return (pivot);
}
