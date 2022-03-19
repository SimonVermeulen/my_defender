/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower.c
*/

#include "game.h"

int start_tower(object_t *object, engine_t *engine)
{
    object_t *selector = seek_object_scene(object->childs, "BuildSelector");

    if (!get_addon("stats", 3, object) || !get_addon("type", 3, object) ||
        !get_addon("PositionX", 3, object) ||
        !get_addon("PositionY", 3, object) ||
        !selector) {
        exit_game(engine, 84);
    }
    return 0;
}

int tick_tower_build(object_t *object, engine_t *engine);

int tick_tower(object_t *object, engine_t *engine)
{
    int *stats = get_addon("stats", 3, object);

    switch (*stats) {
        case 1:
            tick_tower_build(object, engine);
            break;
    }
}

int event_tower_selector(object_t *object, engine_t *engine);

int event_tower(object_t *object, engine_t *engine)
{
    int *stats = get_addon("stats", 3, object);

    switch (*stats) {
        case 0:
            event_tower_selector(object, engine);
            break;
    }
}

int init_tower_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_tower;
    addon->on_event = event_tower;
    addon->on_tick = tick_tower;
    if (create_addon("tower", addon, engine) == sfFalse)
        return 84;
    return 0;
}