#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */

/* Function prototype */
int is_complete_recursive(const binary_tree_t *tree, int index, int size);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_complete_recursive(tree, 0, binary_tree_size(tree));
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_complete_recursive(tree, 0, binary_tree_size(tree));
}

/**
 * is_complete_recursive - Recursive helper function to check completeness.
 * @tree: A pointer to the current node being checked.
 * @index: The index of the current node.
 * @size: The total number of nodes in the tree.
 * Return: 1 if the subtree rooted at 'tree' is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
            is_complete_recursive(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Computes the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
