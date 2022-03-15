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
    sfFloatRect button = (sfFloatRect) {rect.left, rect.top + 3, 50, 50};
    node_t *tower = search_from_key(get_addon("Tower", 0, object),
        "TowerArcher");
    object_t *valid = seach_object(engine, "ValidBuild");

    if (valid == NULL)
        return 0;
    if (sfFloatRect_contains(&button, mouse.x, mouse.y) == sfTrue) {
        set_active(sfTrue, tower->value, engine);
        sfSprite_setPosition(valid->entity->sprite, (sfVector2f)
            {button.left, button.top});
        set_active(sfTrue, valid, engine);
    }
    return 0;
}