/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** stage_01.c
*/

#include "game_engine.h"

list_t *init_stage_01(engine_t *engine)
{
    list_t *scene = launch_parsing("./json/scenes/stage_01.json");
    list_t *map = NULL;

    if (scene == NULL)
        return NULL;
    map = init_scene_by_list(scene, engine, NULL);
    free_json_object(scene);
    return map;
}
