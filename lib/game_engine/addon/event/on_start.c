/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** on_start.c
*/

#include "game_engine.h"

int loop_execution_start(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = NULL;

    node = object->addons->head;
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (addon->on_start != NULL)
            add_function(addon->on_start, 0, object, engine);
    }
    return 0;
}

int window_on_start(list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *node = NULL;

    if (scene == NULL)
        return 0;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object->addons != NULL || object->isActive == sfTrue)
            loop_execution_start(object, engine);
    }
    return 0;
}

int on_start(scene_t *scene, engine_t *engine)
{
    if (scene == NULL || engine == NULL)
        return 84;
    window_on_start(scene->canvas, engine);
    window_on_start(scene->objects, engine);
    return 0;
}