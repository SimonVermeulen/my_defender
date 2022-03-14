/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** position
*/

#include "game_engine.h"

int set_position_canvas(object_t *object, engine_t *engine, int x, int y)
{
    sfVector2i position_camera;

    position_camera = sfRenderWindow_mapCoordsToPixel(engine->window,
    (sfVector2f) {0, 0}, engine->view);
    sfSprite_setPosition(object->entity->sprite, (sfVector2f)
    {position_camera.x, position_camera.y});
    sfSprite_move(object->entity->sprite, (sfVector2f) {x, y});
}

int position_tick_event(object_t *object, engine_t *engine)
{
    int *x = get_addon("PositionX", 3, object);
    int *y = get_addon("PositionY", 3, object);
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
    addon->event_manager = NULL;
    addon->on_scene_loaded = NULL;
    addon->on_tick = position_tick_event;
    if (create_addon("position", addon, engine) == sfFalse)
        return 84;
    return 0;
}