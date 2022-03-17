/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** valid.c
*/

#include "game_engine.h"

void disable_build_items(object_t *tower, object_t *object, engine_t *engine)
{
    object_t *selector = seek_object_scene(tower->childs, "BuildSelector");

    if (!selector) {
        exit_game(engine, 84);
        return 0;
    }
    set_active(sfFalse, selector, engine);
    set_active(sfFalse, object, engine);
    return 0;
}

int event_build_valid_selector(object_t *object, engine_t *engine)
{
    object_t *tower = NULL;
    sfFloatRect rect_valid = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = get_mouse_position(engine);
    int *stats = NULL;

    if (!object->parent || !object->parent->parent) {
        exit_game(engine, 84);
        return 0;
    }
    tower = object->parent->parent;
    stats = get_addon("stats", 3, tower);
    if (stats == NULL) {
        exit_game(engine, 84);
        return 0;
    }
    if (!sfFloatRect_contains(&rect_valid, mouse.x, mouse.y) &&
        sfClock_getElapsedTime(object->clock).microseconds > 100000) {
        disable_build_items(tower, object, engine);
        *stats = 1; 
    }
    return 0;
}

int tick_build_valid_selector(object_t *object, engine_t *engine)
{
    object_t *tower = NULL;
    object_t *sprite = NULL;
    sfFloatRect rect_valid = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = get_mouse_position(engine);

    if (!object->parent || !object->parent->parent) {
        exit_game(engine, 84);
        return 0;
    }
    tower = object->parent->parent;
    sprite = seek_object_scene(tower->actual_scene, "SpriteTower");
    if (!sprite) {
        exit_game(engine, 84);
        return 0;
    }
    if (!sfFloatRect_contains(&rect_valid, mouse.x, mouse.y) &&
        sfClock_getElapsedTime(object->clock).microseconds > 100000) {
        set_active(sfFalse, object, engine);
        set_active(sfFalse, sprite, engine);
    }
    return 0;
}

int init_build_valid_selector(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_build_valid_selector;
    addon->on_tick = tick_build_valid_selector;
    if (create_addon("build_valid_selector", addon, engine) == sfFalse)
        return 84;
    return 0;
}