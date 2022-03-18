/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** view_drag.c
*/

#include "game_engine.h"

int start_view_drag(object_t *object, engine_t *engine)
{
    sfVector2i *hit_position = malloc(sizeof(sfVector2i));
    node_t *node = NULL;

    if (hit_position == NULL) {
        exit_game(84, engine);
        return 0;
    }
    if (create_new_node(hit_position, 5, "hit_position", object->addons_data)
    == NULL)
        exit_game(84, engine);
    return 0;
}

sfVector2f left_mouse_drag(sfVector2i *hit_position,
    sfVector2f *position_mouse, engine_t *engine, sfFloatRect rect)
{
    sfVector2f direction;
    sfVector2u window = sfRenderWindow_getSize(engine->window);
    sfVector2f view_position =
        sfRenderWindow_mapPixelToCoords(engine->window,
        (sfVector2i) {0, 0}, engine->view);

    direction.x = ((position_mouse->x - hit_position->x) * -1) / 15;
    direction.y = ((position_mouse->y - hit_position->y) * -1) / 15;
    direction.x += ((view_position.x + direction.x + window.x) >
        (rect.left + rect.width)) ? -((view_position.x + direction.x +
        window.x) - (rect.left + rect.width)) : 0;
    direction.y += ((view_position.y + direction.y + window.y) >
        (rect.top + rect.height)) ? -((view_position.y + direction.y +
        window.y) - (rect.top + rect.height)) : 0;
    direction.x += ((view_position.x + direction.x) < 0) ?
        -(view_position.x + direction.x) : 0;
    direction.y += ((view_position.y + direction.y) < 0) ?
        -(view_position.y + direction.y) : 0;
    return direction;
}

int event_view_drag(object_t *object, engine_t *engine)
{
    sfVector2i *hit_position = get_addon("hit_position", 5, object);
    sfVector2f mouse = get_mouse_position(engine);
    static sfBool is_pressed = sfFalse;

    if (engine->event.type == sfEvtMouseButtonPressed &&
        engine->event.mouseButton.button == sfMouseRight) {
        hit_position->x = mouse.x;
        hit_position->y = mouse.y;
        is_pressed = sfTrue;
    }
    if (is_pressed == sfTrue) {
        sfView_move(engine->view, left_mouse_drag(hit_position,
            &mouse, engine,
            sfSprite_getGlobalBounds(object->entity->sprite)));
        sfRenderWindow_setView(engine->window, engine->view);
    }
    if (engine->event.type == sfEvtMouseButtonReleased &&
        engine->event.mouseButton.button == sfMouseRight) {
        is_pressed = sfFalse;
    }
}

int init_view_drag_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_view_drag;
    addon->on_event = event_view_drag;
    addon->on_tick = NULL;
    if (create_addon("view_drag", addon, engine) == sfFalse)
        return 84;
    return 0;
}