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

    if (scene == NULL)
        return NULL;
    return init_scene_by_list(scene, engine, NULL);
}