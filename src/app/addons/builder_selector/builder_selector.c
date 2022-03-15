/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** builder_selector.c
*/

#include "game.h"

int tick_builder_selector(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfFalse)
        set_active(sfFalse, object, engine);
    return 0;
}

int init_builder_selector_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_builder_selector;
    if (create_addon("builder_selector", addon, engine) == sfFalse)
        return 84;
    return 0;
}