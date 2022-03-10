/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** main.c
*/

#include "../include/game_engine.h"

int main(int argc, char **argv)
{
    list_t *scene = launch_parsing("./src/json/scene.json");
    engine_t *engine = init_game((sfVideoMode) {1980, 1080, 32}, "bonjour");
    init_scene_by_list(scene, sfTrue, engine);
    return open_game(engine, 30);
}