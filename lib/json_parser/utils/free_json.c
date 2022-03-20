/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** free_json
*/

#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

static int free_json_recursive(list_t *object);

static int free_object(node_t *current)
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

static int free_json_recursive(list_t *object)
{
    node_t *current = NULL;
    node_t *tmp = NULL;
    int len = 0;

    while (object->nb_elements != 0) {
        current = object->head;
        if (current->type == 1) {
            free_json_recursive(current->value);
            free(current->value);
            current->value = NULL;
        }
        if (current->type == 10) {
            for (int i = 0; i < current->len; i++) {
                free_json_recursive(((list_t **) current->value)[i]);
                free(((list_t **) current->value)[i]);
            }
            free(current->value);
            current->value = NULL;
            current->len = 0;
        }
        shift_element(object);
    }
    return (0);
}

int free_json_object(list_t *object)
{
    int value = 0;

    if (object == NULL)
        return 84;
    value = free_json_recursive(object);
    free(object);
    return (value);
}
