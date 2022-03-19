/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** active.c
*/

#include "game.h"

int start_active(object_t *object, engine_t *engine)
{
    int *enable = get_addon("Enable", 3, object);

    if (!enable || (*enable != 1 && *enable != 0))
        return 0;
    set_active(*enable, object, engine);
    return 0;
}

int init_active_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_active;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    if (create_addon("active", addon, engine) == sfFalse)
        return 84;
    return 0;
}