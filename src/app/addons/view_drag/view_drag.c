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
    if (push_element(object->addons_data,
    create_new_node(hit_position, 5, 0, "hit_position")) == 84)
        exit_game(84, engine);
    return 0;
}

sfVector2f left_mouse_drag(sfVector2i *hit_position,
    sfVector2i *position_mouse)
{
    sfVector2f direction;

    direction.x = (position_mouse->x - hit_position->x) * -1;
    direction.y = (position_mouse->y - hit_position->y) * -1;
    printf("%f, %f\n", direction.x, direction.y);
    return direction;
}

int event_view_drag(object_t *object, engine_t *engine)
{
    sfVector2i *hit_position = get_addon("hit_position", 5, object);
    sfVector2i position_mouse_relative =
        sfMouse_getPositionRenderWindow(engine->window);
    sfVector2i view_position =
        sfRenderWindow_mapCoordsToPixel(engine->window,
        (sfVector2f) {0, 0}, engine->view);

    if (engine->event.type == sfEvtMouseButtonPressed &&
        engine->event.mouseButton.button == sfMouseRight) {
        hit_position->x = position_mouse_relative.x;
        hit_position->y = position_mouse_relative.y;
    }
    if (engine->event.type == sfEvtMouseButtonReleased &&
        engine->event.mouseButton.button == sfMouseRight) {
        sfView_move(engine->view, left_mouse_drag(hit_position,
            &position_mouse_relative));
        sfRenderWindow_setView(engine->window, engine->view);
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