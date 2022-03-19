/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** free_json
*/

#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

int free_object(node_t *current)
{
    list_t **object_array = NULL;
    int len = current->len;

    if (current->type == 1) {
        free_json_recursive(current->value);
        len++;
    } else {
        object_array = current->value;
        for (int i = 0; i < current->len; i++)
            free_json_recursive(object_array[i]);
        free(object_array);
    }
    free(current->key);
    free(current);
    return (len);
}

int free_json_recursive(list_t *object)
{
    node_t *current = object->head;
    node_t *tmp = NULL;
    int len = 0;

    for (int i = 0; i < object->nb_elements; i++) {
        tmp = current->next;
        if (current->type == 1 || current->type == 10) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            len = free_object(current);
            object->nb_elements -= len;
            i -= len;
        }
        current = tmp;
    }
    free_list(object);
    return (0);
}

int free_json_object(list_t *object, int recursive)
{
    int value = 0;

    value = free_json_recursive(object);
    return (value);
}
