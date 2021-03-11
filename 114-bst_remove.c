#include "binary_trees.h"
bst_t *minValueNode(bst_t *tree);
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value:value to remove in the tree
 * Return: pointer to the new root node of the tree after removal of value
 * Node containing a value equals to value must be removed and freed
 * Node with two children:replace with its 1st in-order successor
 **/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (!root)
		return (root);
	else if (value < root->n)
		/* search in the left */
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		/* search in the right */
		root->right = bst_remove(root->right, value);

	else /* when value = root->n */
	{
		/* no child or 1 child */
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		/* 2 children */
		/* Inorder successor: smallest element in right subtree */
		else
		{
			tmp = minValueNode(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}

/**
 * minValueNode - finds the smallest element in BST subtree
 * @root: pointer to the roor if the tree
 * Return: smallest element
 */

bst_t *minValueNode(bst_t *root)
{

	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}
