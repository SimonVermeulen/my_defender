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
        return NULL;
    current = search_from_key(engine->scenes, name);
    if (current == NULL)
        return sfFalse;
    engine->actual_scene = current->value;
}