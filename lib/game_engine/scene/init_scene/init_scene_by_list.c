/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_scene_by_list.c
*/

#include "game_engine.h"

int add_objects_by_list(list_t *objects, list_t *scene, engine_t *engine)
{
    node_t *node = NULL;

    if (objects == NULL || scene == NULL)
        return ERROR;
    node = objects->head;
    for (int i = 0; i < objects->nb_elements; i++, node = node->next) {
        if (node->type != 10)
            return ERROR;
        if (add_object_by_list(node->value, scene, engine) == ERROR)
            return ERROR;
    }
    return 0;
}

int get_objects_by_list(char const *name, list_t *objects, list_t *scene, engine_t *engine)
{
    node_t *node = NULL;

    if (objects == NULL || scene == NULL)
        return ERROR;
    node = search_from_key(objects, name);
    if (node == NULL || node->type != 10)
        return ERROR;
    return add_objects_by_list(node->value, scene, engine);
}

int init_scene_by_list(list_t *object, sfBool const_scene, engine_t *engine)
{
    scene_t *scene = NULL;
    node_t *node = NULL;

    if (object == NULL || engine == NULL)
        return ERROR;
    node = search_from_key(object, "name");
    if (node == NULL || node->type != 4)
        return ERROR;
    scene = init_scene(node->value, const_scene, engine);
    get_objects_by_list("objects", object, scene->objects, engine);
    get_objects_by_list("canvas", object, scene->canvas, engine);
    return 0;
}