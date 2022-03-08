/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** inits a node
*/

#include <stdlib.h>
#include "linked_list.h"

node_t *create_emptynode(void)
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

void splice(list_t *list, int index)
{
    node_t *current_node = NULL;

    for (int i = 0; i < index; i++)
        current_node = current_node->next;
    if (current_node == list->head)
        current_node->next = list->head;
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    free_node(current_node);
    list->nb_elements--;
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
