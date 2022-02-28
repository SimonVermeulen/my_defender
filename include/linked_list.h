/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** includes all the prototypes of my linked lists
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

/*---------------STRUCT---------------*/

/**
 * @brief The node who forms the linked list
 * @details
 * - prev : the previous node
 * - next : the next node
 * - type : the type of the current value contained in node
 * - len : the nb of elements of the current value (if it's an array)
 * - key : the key linked to the current node
 * - value : the value of the current node
 * - id : the id of the current node
 */
typedef struct node_s {
    struct node_s *prev;
    struct node_s *next;
    int type;
    int len;
    char *key;
    void *value;
    int id;
} node_t;

/**
 * @brief The linked list composed by node_s structs
 * @details
 * circular double linked list
 * - head : the head of the list
 * - nb_elements : the nb_elements
 */
typedef struct list_s {
    node_t *head;
    int nb_elements;
} list_t;

/*----------------LIST----------------*/

/**
 * @brief Create and allocate an empty linked_list
 * 
 * @return list_t* the allocated empty list
 */
list_t *create_empty_list(void);

/**
 * @brief Deletes and free each node of the linked_list
 * 
 * @param list the list to delete
 */
void delete_list(list_t *list);

/*---------------ELEMENT--------------*/

/**
 * @brief Adds a node at the end of a given list
 * 
 * @param list the list where to add a node
 * @param data the node to add
 * @return int 0 or -1 in case of error 
 */
int push_element(list_t *list, node_t *data);

/**
 * @brief Adds a node at the begining of a given list  
 * 
 * @param list the list where to add a node
 * @param data the node to add
 * @return int 0 or -1 in case of error
 */
int unshift_element(list_t *list, node_t *data);

/**
 * @brief Deletes the last element of a given list
 * 
 * @param list the list to delete an element from
 * @return int 0 or -1 in case of error
 */
int pop_element(list_t *list);

/**
 * @brief Deletes the first element of a given liven
 * 
 * @param list the list to delete an element from
 * @return int 0 or -1 in case of error
 */
int shift_element(list_t *list);

/**
 * @brief Create an empty_node to fill
 * 
 * @param id the nb of current elements
 * @return node_t* the empty node created and allocated
 */
node_t *create_newnode(int id);

/**
 * @brief Free the given node
 * 
 * @param node the node to delete
 */
void free_node(node_t *node);

/**
 * @brief searches a node from a given key
 * 
 * @param list the list where to search the node
 * @param key the key we need to find
 * @return node_t* NULL if not found or the node we are looking for
 */
node_t *search_from_key(list_t *list, char *key);

#endif
