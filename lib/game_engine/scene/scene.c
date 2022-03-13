/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"

sfBool change_scene(char const *name, engine_t *engine)
{
    node_t *current = NULL;

    if (engine == NULL)
        return sfFalse;
    current = search_from_key(engine->scenes, name);
    if (current == NULL)
        return sfFalse;
    engine->actual_scene = current->value;
    return sfTrue;
}

int destroy_scene(scene_t *scene)
{
    node_t *node = NULL;

    if (scene == NULL)
        return ERROR;
    while (scene->objects->nb_elements != 0) {
        node = scene->objects->head;
        destroy_object(node->value);
        shift_element(scene->objects);
    }
    free(scene->objects);
    while (scene->canvas->nb_elements != 0) {
        node = scene->canvas->head;
        destroy_object(node->value);
        shift_element(scene->canvas);
    }
    free(scene->canvas);
    return 0;
}