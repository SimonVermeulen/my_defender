/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower_selector.c
*/

#include "game.h"

int on_click_tower_a(object_t *object, engine_t *engine, sfFloatRect rect,
    sfVector2f mouse)
{
    sfFloatRect button = (sfFloatRect) {rect.left + 7, rect.top + 12, 30, 30};
    static sfBool is_valid = sfFalse;
    node_t *tower = search_from_key(get_addon("Tower", 0, object),
        "TowerArcher");

    if (sfFloatRect_contains(&button, mouse.x, mouse.y) == sfTrue &&
        is_valid == sfFalse) {
        printf("je passes\n");
        is_valid = sfTrue;
        set_active(sfTrue, tower->value, engine);
    }
    return 0;
}