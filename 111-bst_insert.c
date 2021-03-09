#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value:value to store in the node to be inserted
 * Return: pointer to the created node, NULL on failure.
 * If the address stored in tree is NULL,created node becomes root node.
 * If the value is already present in the tree, it must be ignored
 **/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;


	if (!*tree)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (*tree);
	}
	current = *tree;
	/* go to left of the tree */
	if (value < current->n)
	{
		if (!current->left) /* insert to the left if empty */
		{
			new_node = binary_tree_node(current, value);
			current->left = new_node;
			return (current->left);
		}
		return (bst_insert(&current->left, value));
	}
	/* go to the right of the tree */
	else if (value > current->n)
	{
		if (!current->right) /* insert to the right if empty */
		{
			new_node = binary_tree_node(current, value);
			current->right = new_node;
			return (current->right);
		}
		return (bst_insert(&current->right, value));
	}
	return (NULL);
}
