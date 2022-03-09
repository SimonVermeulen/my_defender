/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** window_on_tick.c
*/

#include "game_engine.h"

int loop_execution_tick(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = NULL;
    int code = 0;

    node = object->addons->head;
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (addon->on_tick != NULL)
            code = addon->on_tick(object, engine);
        if (code != 0)
            return code;
    }
    return 0;
}

int window_on_tick(list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *node = NULL;
    int code = 0;

    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object->addons != NULL)
            code = loop_execution_tick(object, engine);
        print_entity(object, engine);
        if (code != 0)
            return code;
    }
    return 0;
}