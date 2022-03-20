/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** print_ghost.c
*/

#include "game.h"

int set_active_ghost(object_t *object, engine_t *engine, list_t *tower,
    sfFloatRect rect)
{
    object_t *valid = seek_object_scene(object->childs, "Valid");
    double *x = get_addon("PositionX", 2, valid);
    double *y = get_addon("PositionY", 2, valid);
    int *type = get_value_list(tower, "type", 3);
    int *type_parent = get_addon("type", 3, object->parent);
    char *path = get_value_list(tower, "Path", 4);
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");

    if (!valid || !x || !y || !type || !type_parent || !path || !sprite)
        return exit_game(engine, 84);
    set_active(sfTrue, valid, engine);
    set_active(sfTrue, sprite, engine);
    *x = rect.left;
    *y = rect.top;
    *type_parent = *type;
    if (change_texture(sprite, path) == 84)
        return exit_game(engine, 84);
}

int print_ghost(list_t *tower, object_t *object, engine_t *engine,
    sfFloatRect rect)
{
    double *position_x = get_value_list(tower, "PositionX", 2);
    double *position_y = get_value_list(tower, "PositionY", 2);
    sfVector2f mouse = get_mouse_position(engine);

    if (!position_x || !position_y)
        return exit_game(engine, 84);
    rect.left = rect.left + *position_x;
    rect.top = rect.top + *position_y;
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y))
        set_active_ghost(object, engine, tower, rect);
    return 0;
}