/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** origin.c
*/

#include "game.h"

int start_origin(object_t *object, engine_t *engine)
{
    int *type = get_addon("Origin", 3, object);
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);

    if (type == NULL)
        return 0;
    switch (*type) {
        case 0:
            sfSprite_setOrigin(object->entity->sprite, (sfVector2f)
                {rect.width / 2, rect.height / 2});
            break;
    }
    return 0;
}

int init_origin_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_origin;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    if (create_addon("origin", addon, engine) == sfFalse)
        return 84;
    return 0;
}