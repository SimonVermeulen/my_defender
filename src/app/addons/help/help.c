/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** help.c
*/

#include "game.h"

int start_help(object_t *object, engine_t *engine)
{
    int *width = get_addon("HoverButton_Width", 3, object);
    int *height = get_addon("HoverButton_Height", 3, object);

    if (!object->entity->sprite || !width || !height)
        return exit_game(engine, 84);
    sfSprite_setTextureRect(object->entity->sprite, (sfIntRect) {0, 0,
        *width, *height});
    window_pause(object->actual_scene, engine, object, sfTrue);
    return 0;
}

void check_if_finish(object_t *object, engine_t *engine, sfIntRect box,
    int width)
{
    if (box.left >= (width * 3))
        add_function(destroy_object, 0, object, engine);
    window_pause(object->actual_scene, engine, object, sfFalse);
}

int event_help(object_t *object, engine_t *engine)
{
    int *width = get_addon("HoverButton_Width", 3, object);
    int *height = get_addon("HoverButton_Height", 3, object);
    sfVector2f mouse = get_mouse_position(engine);
    double *position_x = get_addon("PositionX", 2, object);
    double *position_y = get_addon("PositionY", 2, object);
    sfFloatRect rect;
    sfIntRect box = sfSprite_getTextureRect(object->entity->sprite);

    if (width == NULL || height == NULL)
        return 0;
    rect = (sfFloatRect) {*position_x, *position_y, *width,
        *height};
    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        box.left += *width;
        sfSprite_setTextureRect(object->entity->sprite, box);
        check_if_finish(object, engine, box, *width);
    }
    return 0;
}

int init_help_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_help;
    addon->on_event = event_help;
    addon->on_tick = NULL;
    if (create_addon("help", addon, engine) == sfFalse)
        return 84;
    return 0;
}