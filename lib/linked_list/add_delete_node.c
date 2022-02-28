/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** inits a node
*/

#include <stdlib.h>
#include "linked_list.h"

node_t *create_newnode(void)
{
    node_t *new_node = NULL;

    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return (NULL);
    new_node->type = -1;
    new_node->len = 0;
    new_node->value = NULL;
    new_node->key = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

//à coder
static void free_value(node_t *node);

void free_node(node_t *node)
{
    if (node) {
        free(node->key);
        free(node->value);
        free(node);
    }
}
