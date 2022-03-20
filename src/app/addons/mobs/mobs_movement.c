/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** mobs_movement.c
*/

#include "game.h"
#include <math.h>

sfVector2f get_normalize_vector(sfVector2f pos, sfVector2f direction)
{
    float x = direction.x - pos.x;
    float y = direction.y - pos.y;
    float hypotenuse = sqrt(pow(x, 2) + pow(y, 2));

    return (sfVector2f) {(x / hypotenuse), (y / hypotenuse)};
}

int move_mob(object_t *object, engine_t *engine, list_t *position, int *step)
{
    double *position_x = get_addon("PositionX", 2, object);
    double *position_y = get_addon("PositionY", 2, object);
    int *speed = get_addon("Speed", 3, object);
    int *x = get_value_list(position, "x", 3);
    int *y = get_value_list(position , "y", 3);
    sfVector2f normal;
    sfFloatRect rect;

    if (!position_x || !position_y || !x || !y || !speed || *speed <= 0)
        return exit_game(engine, 84);
    normal = get_normalize_vector((sfVector2f) {*position_x, *position_y},
        (sfVector2f) {*x, *y});
    normal.x = normal.x * *speed * (get_delta(engine) / 100);
    normal.y = normal.y * *speed * (get_delta(engine) / 100);
    *position_x = *position_x + normal.x;
    *position_y = *position_y + normal.y;
    rect = (sfFloatRect) {*x - 50, *y - 50, *x + 50, *y + 50};
    if (sfFloatRect_contains(&rect, *position_x, *position_y)) {
        *step = *step + 1;
    }
    return 0;
}

int destroy_after_game(object_t *object, engine_t *engine)
{
    destroy_object(object);
}

int tick_mobs_movement(object_t *object, engine_t *engine)
{
    int *position_step = get_addon("PositionStep", 3, object);
    node_t *positions = search_from_key(object->addons_data, "Paths");
    list_t **position_list = NULL;

    if (!positions || positions->type != 10 || !position_step ||
        *position_step >= positions->len)
        return 0;
    position_list = positions->value;
    move_mob(object, engine, position_list[*position_step], position_step);
    if (*position_step >= positions->len)
        add_function(destroy_object, 0, object, engine);
    return 0;
}

int init_mobs_movement_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_mobs_movement;
    if (create_addon("mobs_movement", addon, engine) == sfFalse)
        return 84;
    return 0;
}