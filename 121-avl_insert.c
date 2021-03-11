#include "binary_trees.h"
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of AVL tree for inserting the value
 * @value:value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 * If the address stored in tree=NULL, the created node becomes the root node.
 * The resulting tree after insertion, must be a balanced AVL Tree
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *current;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		current = avl_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		current = avl_insert(&(*tree)->right, value);
	}
	else
		return (*tree);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		(*tree) = binary_tree_rotate_right(*tree);
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		(*tree) = binary_tree_rotate_right((*tree));
	}
	if (balance < -1 && value > (*tree)->right->n)
		(*tree) = binary_tree_rotate_left((*tree));
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		(*tree) = binary_tree_rotate_left((*tree));
	}
	return (current);
}
