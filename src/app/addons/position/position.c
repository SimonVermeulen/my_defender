/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** position
*/

#include "game_engine.h"

int set_position_canvas(object_t *object, engine_t *engine, int x, int y)
{
    sfVector2f position_camera = sfRenderWindow_mapPixelToCoords(
        engine->window, (sfVector2i) {0, 0}, engine->view);

    sfSprite_setPosition(object->entity->sprite, position_camera);
    sfSprite_move(object->entity->sprite, (sfVector2f) {x, y});
}

int start_position(object_t *object, engine_t *engine)
{
    double *x = get_addon("PositionX", 2, object->parent);
    double *y = get_addon("PositionY", 2, object->parent);
    double *pos_x = get_addon("PositionX", 2, object);
    double *pos_y = get_addon("PositionY", 2, object);

    if (!object->parent || !x || !y || !pos_x || !pos_y)
        return 0;
    *pos_x = *x + *pos_x;
    *pos_y = *y + *pos_y;
    return 0;
}

int position_tick_event(object_t *object, engine_t *engine)
{
    double *x = get_addon("PositionX", 2, object);
    double *y = get_addon("PositionY", 2, object);
    int *is_canvas = get_addon("IsCanvas", 3, object);

    if (object->entity == NULL || x == NULL || y == NULL)
        return 0;
    if (is_canvas != NULL && *is_canvas == sfTrue) {
        set_position_canvas(object, engine, *x, *y);
    } else {
        sfSprite_setPosition(object->entity->sprite, (sfVector2f) {*x, *y});
    }
    return 0;
}

int init_position_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_position;
    addon->on_event = NULL;
    addon->on_tick = position_tick_event;
    if (create_addon("position", addon, engine) == sfFalse)
        return 84;
    return 0;
}
