/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_int
*/

#include <stdlib.h>
#include "linked_list.h"

static char *copy_single_string(char *str)
{
    char *dest = NULL;
    int len = 0;

    for (int len = 0; str[len]; len++);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    for (int i = 0; i < len; i++)
        dest[i] = str[i];
    dest[len] = '\0';
    return (dest);
}

static char **copy_string_array(char **src, int len)
{
    char **str_array = NULL;

    str_array = malloc(sizeof(char *) * (len + 1));
    if (!str_array)
        return (NULL);
    for (int i = 0; i < len; i++)
        str_array[i] = copy_single_string(src[i]);
    str_array[len] = NULL;
    return (str_array);
}

int copy_string(node_t *src, node_t *dest)
{
    char **to_copy_value = NULL;
    char *str = NULL;
    int len = (src->value == 0) ? 1 : src->value; 

    if (src->len == 0)
        dest->value = copy_single_string(src->value);
    else
        dest->value = copy_string_array(src->value, len);
    if (!dest->value)
        return (NULL);
    return (0);
}
