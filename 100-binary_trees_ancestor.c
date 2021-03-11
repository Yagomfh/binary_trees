#include "binary_trees.h"

/**
  * depth - measures the depth of a node in a binary tree
  * @tree: pointer to node
  * Return: the depth or 0 is failed
  */

unsigned int depth(const binary_tree_t *tree)
{
	unsigned int depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
  * check_root - check if nodes are in the same binary tree
  * @f: first node
  * @s: second node
  * Return: 1 if same BT or 0 otherwise
  */

int check_root(const binary_tree_t *f, const binary_tree_t *s)
{
	while (f->parent != NULL)
		f = f->parent;
	while (s->parent != NULL)
		s = s->parent;
	if (f == s)
		return (1);
	else
		return (0);
}

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: first node
  * @second: second node
  * Return: lowest common ancestor
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	unsigned int d1, d2, diff;

	if (!first || !second)
		return (NULL);

	if (check_root(first, second) == 0)
		return (NULL);

	d1 = depth(first);
	d2 = depth(second);

	if (d1 < d2)
	{
		for (diff = d2 - d1; diff != 0; diff--)
			second = second->parent;
	}
	else
	{
		for (diff = d1 - d2; diff != 0; diff--)
			first = first->parent;
	}
	while (first->n != second->n)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
