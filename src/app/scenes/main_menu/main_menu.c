/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_menu
*/

#include "game_engine.h"

scene_t *init_main_menu(engine_t *engine)
{
    list_t *scene = launch_parsing("./json/scenes/main_menu.json");
    scene_t *scene_la = NULL;

    if (scene == NULL)
        return NULL;
    scene_la = init_scene_by_list(scene, engine);
    return scene_la;
}