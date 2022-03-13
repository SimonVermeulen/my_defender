/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** search functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

static int cmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    result = s1[i] - s2[i];
    return (result);
}

node_t *search_from_key(list_t *list, char *key)
{
    node_t *current = NULL;

    if (!list)
        return (NULL);
    current = list->head;
    for (int i = 0; i < list->nb_elements; i++) {
        if (!cmp(key, current->key))
            return (current);
        current = current->next;
    }
    write(2, "Error: can't find node with this key\n", 38);
    return (NULL);
}

