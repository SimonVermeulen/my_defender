/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_scene
*/

#include "game_engine.h"
#include "game.h"

int load_scenes(engine_t *engine, char **name, init_scene_function_t *function)
{
    for (int i = 0; name[i] != NULL; i++) {
        if (init_primitive_scene(engine, function[i], name[i]) == 84)
            return 84;
    }
    return 0;
}