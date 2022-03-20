/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init
*/

#include "game.h"

int load_addons(engine_t *engine, const int (*init_addon[])(engine_t *))
{
    for (int i = 0; init_addon[i] != NULL; i++) {
        if ((*init_addon[i])(engine) == 84)
            return 84;
    }
    return 0;
}
