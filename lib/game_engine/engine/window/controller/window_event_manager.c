/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** window_event_manager.c
*/

#include "game_engine.h"

int loop_execution_event_manager(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = NULL;
    int code = 0;

    node = object->addons->head;
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (addon->event_manager != NULL)
            code = addon->event_manager(object, engine);
        if (code != 0)
            return code;
    }
    return 0;
}

int loop_track_event_manager(list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *node = NULL;
    int code = 0;

    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object->addons != NULL || object->isActive == sfTrue)
            code = loop_execution_event_manager(object, engine);
        if (code != 0)
            return code;
    }
    return 0;
}

int window_event_manager(list_t *scene, engine_t *engine)
{
    int code = 0;
    
    if (scene == NULL)
        return 0;
    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        if (engine->event.type == sfEvtClosed)
            sfRenderWindow_close(engine->window);
        code = loop_track_event_manager(scene, engine);
        if (code != 0)
            return code;
    }
    return 0;
}