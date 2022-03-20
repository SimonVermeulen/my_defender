/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** build_selector.c
*/

#include "game.h"

int print_ghost(list_t *tower, object_t *object, engine_t *engine,
    sfFloatRect rect);

int start_build_selector(object_t *object, engine_t *engine)
{
    object_t *valid = seek_object_scene(object->childs, "Valid");
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    node_t *tower_list = search_from_key(object->addons_data, "Towers");

    if (!valid || !sprite || !tower_list || tower_list->len != 4
        || tower_list->type != 10) {
        exit_game(engine, 84);
    }
    set_active(sfFalse, valid, engine);
    set_active(sfFalse, object, engine);
    set_active(sfFalse, sprite, engine);
    return 0;
}

int event_build_selector(object_t *object, engine_t *engine)
{
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    object_t *valid = seek_object_scene(object->childs, "Valid");
    list_t **tower_list = get_addon("Towers", 10, object);
    int length = search_from_key(object->addons_data, "Towers")->len;
    double *x = get_addon("PositionX", 2, object);
    double *y = get_addon("PositionY", 2, object);

    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        valid->isActive == sfFalse) {
        for (int i = 0; i < length; i++) {
            print_ghost(tower_list[i], object, engine, (sfFloatRect)
                {*x, *y, 100, 100});
        }
    }
}

int tick_build_selector(object_t *object, engine_t *engine)
{
    sfFloatRect selector = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = get_mouse_position(engine);

    if (!sfFloatRect_contains(&selector, mouse.x, mouse.y)) {
        set_active(sfFalse, object, engine);
    }
}

int init_build_selector_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_build_selector;
    addon->on_event = event_build_selector;
    addon->on_tick = tick_build_selector;
    if (create_addon("build_selector", addon, engine) == sfFalse)
        return 84;
    return 0;
}