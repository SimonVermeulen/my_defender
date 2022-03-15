/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** valid_build.c
*/

#include "game.h"

int tick_valid_build(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfFalse) {
        set_active(sfFalse, object, engine);
        return 0;
    }
    return 0;
}

int init_valid_build_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_valid_build;
    if (create_addon("valid_build", addon, engine) == sfFalse)
        return 84;
    return 0;
}