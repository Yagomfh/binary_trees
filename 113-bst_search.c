#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value:value to search in the tree
 * Return: pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found,return NULL
 **/

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current;

	if (!tree)
		return (NULL);
	current = (bst_t *)tree;

	while (current->n != value)
	{
		if (current != NULL)
		{
			/* go to left of the tree */
			if (current->n > value)
			{
				current = current->left;
			}
			/* go to right */
			else
				current = current->right;
		}
		/* nothing found */
		if (current == NULL)
		{
			return (NULL);
		}
	}
	return (current);
}
