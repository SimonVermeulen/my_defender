/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_menu
*/

#include "game_engine.h"

int init_main_menu(engine_t *engine)
{
    list_t *scene = launch_parsing("./json/scene/main_menu.json");

    if (scene == NULL)
        return 84;
    return init_scene_by_list(scene, sfFalse, engine);
}