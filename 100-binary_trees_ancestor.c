#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node. If no common ancestor
 * was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *temp;

	if (first == NULL || second == NULL)
	{
		/*If either node is NULL, no common ancestor*/
		return (NULL);
	}
	/*Create a temporary pointer to the second node*/
	temp = (binary_tree_t *)second;
	/*traverse ancestor of the first node*/
	while (first)
	{
		/*traverse ancestor of second node*/
		while (second)
		{/*if common ancestor is found return it */
			if (first == second)
				return ((binary_tree_t *)first);
			/*move parent of the scond node */
			second = second->parent;
		}
		/*rset second to the original second node*/
		second = temp;
		/*move parent of the first node*/
		first = first->parent;
	}
	/*no common ancestor found*/
	return (NULL);
}
