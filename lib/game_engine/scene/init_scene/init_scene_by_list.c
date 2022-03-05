/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_scene_by_list.c
*/

#include "game_engine.h"

int init_scene_by_list(list_t *object, sfBool const_scene, engine_t *engine)
{
    scene_t *scene = NULL;
    node_t *node = NULL;

    if (object == NULL || engine == NULL)
        return ERROR;
    node = search_from_key(object, "name");
    if (node->type == 4)
    scene = init_scene(node->value, const_scene, engine);
}