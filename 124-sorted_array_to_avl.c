#include "binary_trees.h"

/**
  * build_avl_tree - from sorted array to avl
  * @arr: the array
  * @start: start of the array
  * @end: end of the array
  * @tree: pointer to root node
  * Return: pointer to bin tree
  */

avl_t *build_avl_tree(int *arr, int start, int end, avl_t *tree)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(tree, arr[mid]);
	if (root == NULL)
		return (NULL);
	root->left = build_avl_tree(arr, start, mid - 1, root);
	root->right = build_avl_tree(arr, mid + 1, end, root);

	return (root);
}

/**
  * sorted_array_to_avl - from sorted array to avl
  * @array: sorted array
  * @size: size of the array
  * Return: poitner to bin tree
  */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, tree));
}
