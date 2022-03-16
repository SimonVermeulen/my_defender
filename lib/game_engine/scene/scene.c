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
    primitive_scene_t *primitive = NULL;

    if (engine == NULL)
        return sfFalse;
    current = search_from_key(engine->scenes, name);
    if (current == NULL)
        return sfFalse;
    primitive = current->value;
    on_end(engine->actual_scene, engine);
    engine->prev_scene = engine->actual_scene;
    engine->actual_scene = primitive->init(engine);
    if (engine->actual_scene == NULL) {
        exit_game(engine, 84);
        return sfFalse;
    }
    on_start(engine->actual_scene, engine);
    return sfTrue;
}

sfBool set_const_scene(char const *name, engine_t *engine)
{
    node_t *current = NULL;
    primitive_scene_t *primitive = NULL;

    if (engine == NULL)
        return sfFalse;
    current = search_from_key(engine->scenes, name);
    if (current == NULL)
        return sfFalse;
    primitive = current->value;
    engine->const_scene = primitive->init(engine);
    if (engine->const_scene == NULL) {
        exit_game(engine, 84);
        return sfFalse;
    }
    on_start(engine->const_scene, engine);
    return sfTrue;
}

int destroy_scene(list_t *scene)
{
    node_t *node = NULL;

    if (scene == NULL)
        return ERROR;
    while (scene->nb_elements != 0) {
        node = scene->head;
        destroy_object(node->value);
    }
    free(scene);
    return 0;
}