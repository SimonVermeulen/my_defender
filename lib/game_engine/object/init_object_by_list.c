/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_object_by_list.c
*/

#include "game_engine.h"

int add_addon_by_list(list_t *object_list, engine_t *engine, object_t *object)
{
    node_t *addons = NULL;
    node_t *node = NULL;
    int nbr = 0;

    addons = search_from_key(object_list, "addons");
    if (object_list == NULL || object == NULL || addons == NULL || addons->type != 10)
        return ERROR;
    node = ((list_t *)addons->value)->head;
    nbr = ((list_t *)addons->value)->nb_elements;
    for (int i = 0; i < nbr; i++, node = node->next) {
        if (node->type != 4)
            return ERROR;
        add_addon(node->value, object, engine);
    }
    return 0;
}

int add_addon_data(list_t *object_list, object_t *object)
{
    node_t *node = NULL;

    node = search_from_key(object_list, "addon_data");
    if (node == NULL || node->type != 1)
        return ERROR;
    object->addons_data = node->value;
    return 0;
}

int add_object_by_list(list_t *object_list, list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *name = NULL;
    node_t *entity = NULL;

    name = search_from_key(object_list, "name");
    if (name == NULL || name->type != 4)
        return ERROR;
    object = create_object(name->value, scene);
    if (object == NULL)
        return ERROR;
    entity = search_from_key(object_list, "entity");
    if (entity != NULL && entity->type == 1)
        init_entity_by_list(entity->value, object);
    add_addon_by_list(object_list, engine, object);
    return 0;
}