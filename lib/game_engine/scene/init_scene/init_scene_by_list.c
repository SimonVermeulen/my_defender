/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_scene_by_list.c
*/

#include "game_engine.h"

int add_objects_by_list(node_t *lists, list_t *scene, engine_t *engine)
{
    list_t **array = NULL;

    if (lists == NULL || scene == NULL)
        return ERROR;
    array = lists->value;
    for (int i = 0; i < lists->len; i++) {
        if (add_object_by_list(array[i], scene, engine) == ERROR)
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
        return 0;
    return add_objects_by_list(node, scene, engine);
}

scene_t *init_scene_by_list(list_t *object, engine_t *engine)
{
    scene_t *scene = NULL;
    node_t *node = NULL;
    int code = 0;

    if (object == NULL || engine == NULL)
        return NULL;
    scene = init_scene(engine);
    if (scene == NULL)
        return NULL;
    code += get_objects_by_list("objects", object, scene->objects, engine);
    code += get_objects_by_list("canvas", object, scene->canvas, engine);
    return (code != 0) ? NULL : scene;
}