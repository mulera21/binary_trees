#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *ancestor;

    if (!first || !second)
        return NULL;

    ancestor = (binary_tree_t *)second;

    while (first)
    {
        const binary_tree_t *tmp = second;
        
        while (tmp)
        {
            if (tmp == first)
                return (binary_tree_t *)tmp;

            tmp = tmp->parent;
        }

        first = first->parent;
    }

    return ancestor;
}
