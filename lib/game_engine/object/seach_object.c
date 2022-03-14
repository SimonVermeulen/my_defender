/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** seach_object.c
*/

#include "game_engine.h"

object_t *seek_object_in_scene(scene_t *scene, char const *name)
{
    node_t *node = NULL;

    if (scene == NULL)
        return NULL;
    node = search_from_key(scene->canvas, name);
    if (node == NULL)
        node = search_from_key(scene->objects, name);
    return node;
}

object_t *seach_object(engine_t *engine, char const *name)
{
    node_t *node = NULL;

    node = seek_object_in_scene(engine->actual_scene, name);
    if (node == NULL)
        node = seek_object_in_scene(engine->const_scene, name);
    return node->value;
}