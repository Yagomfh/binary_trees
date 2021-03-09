#include "binary_trees.h"

/**
  * binary_tree_rotate_left - performs a left-rotation on a binary tree
  * @tree: pointer to the root node of the tree to rotate
  * Return: pointer to the new root node of the tree once rotated
  */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->right;
	tree->right = pivot->left;

	if (pivot->left != NULL)
		pivot->left->parent = tree;
	pivot->parent = tree->parent;
	pivot->left = tree;
	tree->parent = pivot;
	return (pivot);
}
