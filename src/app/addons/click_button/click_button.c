/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** hover_button
*/

#include "game_engine.h"

int on_click_button(object_t *object, engine_t *engine)
{
    list_t *on_click = get_addon("OnClick", 1, object);
    int *type = NULL;
    char *value = NULL;

    if (on_click == NULL)
        return 0;
    type = get_value_list(on_click, "type", 3);
    value = get_value_list(on_click, "value", 4);
    if (type == NULL || value == NULL)
        return 0;
    switch (*type) {
        case 0:
            change_scene(value, engine);
            break;
        case 1:
            exit_game(engine, 0);
            break;
    }
    return 0;
}

int click_button_event(object_t *object, engine_t *engine)
{
    int *width = get_addon("HoverButton_Width", 3, object);
    int *height = get_addon("HoverButton_Height", 3, object);
    sfVector2f mouse = get_mouse_position(engine);
    double *position_x = get_addon("PositionX", 2, object);
    double *position_y = get_addon("PositionY", 2, object);
    sfFloatRect rect;

    if (width == NULL || height == NULL)
        return 0;
    rect = (sfFloatRect) {*position_x, *position_y, *width,
        *height};
    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        sfSprite_setTextureRect(object->entity->sprite, (sfIntRect)
            {*width * 2, 0, *width, *height});
        on_click_button(object, engine);
    }
    return 0;
}

int init_click_button_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = click_button_event;
    addon->on_tick = NULL;
    if (create_addon("click_button", addon, engine) == sfFalse)
        return 84;
    return 0;
}
