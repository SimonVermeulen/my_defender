/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** object.c
*/

#include <unistd.h>
#include "game_engine.h"
#include "libma.h"

int create_object(char const *name, list_t *scene)
{
    node_t *node = NULL;
    char *string = NULL;
    object_t *object = NULL;

    if (name == NULL || scene == NULL)
        return 84;
    node = malloc(sizeof(node_t));
    string = my_strdup(name);
    object = malloc(sizeof(object_t));
    if (node == NULL || string == NULL || object == NULL)
        return 84;
    object->addons = create_empty_list();
    object->addons_data = create_empty_list();
    object->isActive = sfTrue;
    object->entity = NULL;
    if (object->addons == NULL || object->addons_data == NULL)
        return 84;
    return 0;
}

int destroy_object(object_t *object)
{
    if (object == NULL)
        return 84;
    destroy_addons(object->addons);
    destroy_addons(object->addons_data);
    destroy_entity(object);
    free(object);
    return 0;
}