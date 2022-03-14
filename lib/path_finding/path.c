/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** path.c
*/

#include "path_finding.h"
#include "my.h"
#include "linked_list.h"
#include <SFML/Graphics.h>

void find_path(char **map, int start[], int end[])
{
    node_t *start_node = initialize_node();
    node_t *end_node = initialize_node();
    list_t *open_list = create_empty_list();
    list_t *close_list = create_empty_list();

    unshift_element(open_list, start_node);
    return;
}
