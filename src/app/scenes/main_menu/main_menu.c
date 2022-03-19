/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_menu
*/

#include "game_engine.h"

list_t *init_main_menu(engine_t *engine)
{
    list_t *scene = launch_parsing("./json/scenes/main_menu.json");
    list_t *map = NULL;

    if (scene == NULL)
        return NULL;
    map = init_scene_by_list(scene, engine, NULL);
    free_json_object(scene);
    return map;
}