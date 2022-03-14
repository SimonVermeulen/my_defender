/*
** EPITECH PROJECT, 2021
** PATHFINDING
** File description:
** pathfinding include file
*/

#ifndef PATH_FINDING_H
    #define PATH_FINDING_H
    #include <SFML/Graphics.h>
    #include "linked_list.h"

/* --------------- Structures ---------------*/

/**
 * @brief The node who forms the linked list
 * @details
 * - prev : the previous node
 * - next : the next node
 * - type : the type of the current value contained in node
 * - len : the nb of elements of the current value (if it's an array)
 * - key : the key linked to the current node
 * - value : the value of the current node
 */
typedef struct element_s {
    struct element_s *parent;
    sfVector2f position;
    int g;
    int h;
    int f;
} element_t;

/**
 * @brief The linked list composed by element_s structs
 * @details
 * circular double linked list
 * - head : the head of the list
 * - nb_elements : the nb_elements
 */
typedef struct fill_s {
    element_t *first;
    element_t *last;
    int nb_elements;
} fill_t;

/* --------------- Prototypes ---------------*/

void find_path(char **map, int start[], int end []);

list_t *initialize_list(void);

node_t *initialize_node(void);

#endif
