/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower.c
*/

#include "game.h"

int start_tower(object_t *object, engine_t *engine)
{
    object_t *selector = seek_object_scene(object->childs, "BuildSelector");

    if (!get_addon("stats", 3, object) || !get_addon("type", 3, object) ||
        !get_addon("PositionX", 3, object) ||
        !get_addon("PositionY", 3, object) ||
        !selector) {
        exit_game(engine, 84);
    }
    return 0;
}

int tick_tower_build(object_t *object, engine_t *engine)
{
    
}

int tick_tower(object_t *object, engine_t *engine)
{

}

int event_tower(object_t *object, engine_t *engine)
{
    int *stats = get_addon("stats", 3, object);
    int *position_x = get_addon("PositionX", 3, object);
    int *position_y = get_addon("PositionY", 3, object);
    object_t *selector = seek_object_scene(object->childs, "BuildSelector");
    sfFloatRect rect = (sfFloatRect) {(*position_x - 50), (*position_y - 50),
        100, 100};
    sfVector2f mouse = get_mouse_position(engine);

    if (*stats > 0)
        return 0;
    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft && 
        sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        set_active(sfTrue, selector, engine);
    }
}

int init_tower_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_tower;
    addon->on_event = event_tower;
    addon->on_tick = NULL;
    if (create_addon("tower", addon, engine) == sfFalse)
        return 84;
    return 0;
}