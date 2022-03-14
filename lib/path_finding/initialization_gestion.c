/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** initalization_gestion.c
*/

#include "path_finding.h"
#include "my.h"
#include "linked_list.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

node_t *initialize_node(void)
{
    node_t *start_node = malloc(sizeof(node_t));
    element_t *element = malloc(sizeof(element_t));

    if (!start_node)
        return (NULL);
    element->f = 0;
    element->g = 0;
    element->h = 0;
    element->parent = NULL;
    element->position.x = 0;
    element->position.y = 0;
    start_node->value = element;
    return (start_node);
}
