/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_game
*/

#include "game.h"

const int (*load_scene[])(engine_t *) = {init_main_menu, NULL};
const int (*load_addon[])(engine_t *) = {NULL};

const int width = 1980;
const int height = 1080;
const int fps = 60;
const char title[] = "titre";

int load_game(void)
{
    engine_t *engine = init_game((sfVideoMode) {width, height, 32}, title);

    if (engine == NULL || load_addons(engine, load_addon) == 84 ||
        load_scenes(engine, load_scene) == 84 || load_fonts(engine) == 84)
        return 84;
    change_scene("MainMenu", engine);
    return open_game(engine, fps);
}