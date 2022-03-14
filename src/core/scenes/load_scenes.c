/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_scene
*/

#include "game.h"

int load_scenes(engine_t *engine, const int (*load_scene[])(engine_t *))
{
    for (int i = 0; load_scene[i] != NULL; i++) {
        if ((*load_scene[i])(engine) == 84)
            return 84;
    }
    return 0;
}