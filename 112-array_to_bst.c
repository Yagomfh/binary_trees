#include "binary_trees.h"

/**
 *array_to_bst -  builds a Binary Search Tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 * Value of the array is already present in tree, this value must be ignored
 **/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	tree = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}
