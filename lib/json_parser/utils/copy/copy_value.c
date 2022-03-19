/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_value
*/

#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

int copy_value(node_t *src, node_t *dest)
{
    int (*copy_func[3])(node_t *, node_t *) = {copy_double,
        &copy_int, &copy_string};

    if (src->type == 1 || src->type == 10)
        dest->value = copy_list(src->value);
    else
        copy_func[src->type % 10](src, dest);
    if (!dest->value)
        return (-1);
    return (0);
}
