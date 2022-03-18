/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** build_selector.c
*/

#include "game.h"

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

int print_ghost(list_t *tower, object_t *object, engine_t *engine,
    sfFloatRect rect)
{
    object_t *valid = seek_object_scene(object->childs, "Valid");
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    int *position_x = get_value_list(tower, "PositionX", 3);
    int *position_y = get_value_list(tower, "PositionY", 3);
    int *x = get_addon("PositionX", 3, valid);
    int *y = get_addon("PositionY", 3, valid);
    char *path = get_value_list(tower, "Path", 4);
    int *type = get_value_list(tower, "type", 3);
    int *type_parent = get_addon("type", 3, object->parent);
    sfVector2f mouse = get_mouse_position(engine);

    if (!position_x || !position_y || !path || !type_parent) {
        exit_game(engine, 84);
        return 0;
    }
    rect.left = rect.left + *position_x;
    rect.top = rect.top + *position_y;
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        set_active(sfTrue, valid, engine);
        set_active(sfTrue, sprite, engine);
        *x = rect.left;
        *y = rect.top;
        *type_parent = *type;
        if (change_texture(sprite, path) == 84) {
            exit_game(engine, 84);
            return 0;
        }
    }
    return 0;
}

int event_build_selector(object_t *object, engine_t *engine)
{
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    object_t *valid = seek_object_scene(object->childs, "Valid");
    list_t **tower_list = get_addon("Towers", 10, object);
    int length = search_from_key(object->addons_data, "Towers")->len;
    int *x = get_addon("PositionX", 3, object);
    int *y = get_addon("PositionY", 3, object);

    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        valid->isActive == sfFalse) {
        for (int i = 0; i < length; i++) {
            print_ghost(tower_list[i], object, engine, (sfFloatRect)
                {*x, *y, 50, 50});
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