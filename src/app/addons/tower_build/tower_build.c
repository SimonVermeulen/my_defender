/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower_build.c
*/

#include "game.h"

int tick_tower_build(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);

    sfSprite_setOrigin(object->entity->sprite, (sfVector2f) {rect.width / 2,
        rect.height / 2});
}

int init_tower_build_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_tower_build;
    if (create_addon("tower_build", addon, engine) == sfFalse)
        return 84;
    return 0;
}