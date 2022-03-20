/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** mobs_spawner.c
*/

#include "game.h"

int spawn_mob(object_t *object, engine_t *engine)
{
    node_t *mobs = search_from_key(object->addons_data, "mobs");
    list_t *mob_list = NULL;
    object_t *mob = NULL;

    if (!mobs || mobs->type != 10)
        return exit_game(engine, 84);
    mob_list = ((list_t **)mobs->value)[rand() % (mobs->len)];
    mob = create_object_list(mob_list, object->actual_scene, engine,
        object->parent);
    if (mob == NULL)
        return exit_game(engine, 84);
    return 0;
}

int tick_mobs_spawner(object_t *object, engine_t *engine)
{
    int *time_spawn = get_addon("TimeSpawn", 3, object);
    int time = sfClock_getElapsedTime(object->clock).microseconds / 100000;

    if (!time_spawn)
        return exit_game(engine, 84);
    if (time >= *time_spawn) {
        sfClock_restart(object->clock);
        spawn_mob(object, engine);
    }
    return 0;
}

int init_mobs_spawner_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_mobs_spawner;
    if (create_addon("mobs_spawner", addon, engine) == sfFalse)
        return 84;
    return 0;
}