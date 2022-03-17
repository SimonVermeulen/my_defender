/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_object_by_list.c
*/

#include "game_engine.h"

int add_addon_by_list(list_t *object_list, engine_t *engine, object_t *object)
{
    char **addons_array = NULL;
    node_t *addons = NULL;
    int nbr = 0;

    addons = search_from_key(object_list, "addons");
    if (object_list == NULL || object == NULL || addons == NULL || addons->type != 40)
        return ERROR;
    addons_array = addons->value;
    for (int i = 0; i < addons->len; i++) {
        add_addon(addons_array[i], object, engine);
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

object_t *add_object_child(list_t *object_list, object_t *object, engine_t *engine)
{
    list_t *scene = get_value_list(object_list, "children", 1);

    if (scene == NULL)
        return object;
    object->childs = init_scene_by_list(scene, engine, object);
    if (object->childs == NULL)
        return NULL;
    return object;
}

object_t *create_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent)
{
    object_t *object = NULL;
    node_t *name = NULL;
    node_t *entity = NULL;

    name = search_from_key(list, "name");
    if (name == NULL || name->type != 4)
        return NULL;
    object = create_object(name->value, scene);
    if (object == NULL)
        return NULL;
    object->parent = parent;
    entity = search_from_key(list, "entity");
    if (entity != NULL && entity->type == 1) {
        if (init_entity_by_list(entity->value, object) == 84)
            return NULL;
    }
    add_addon_by_list(list, engine, object);
    add_addon_data(list, object);
    return add_object_child(list, object, engine);
}