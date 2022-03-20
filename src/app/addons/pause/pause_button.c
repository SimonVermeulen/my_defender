/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** pause.c
*/

#include "game.h"

int event_pause_button(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = get_mouse_position(engine);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) || ) {

    }
}

int init_pause_button_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    if (create_addon("pause_button", addon, engine) == sfFalse)
        return 84;
    return 0;
}