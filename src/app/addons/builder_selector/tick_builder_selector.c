/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tick_builder_selector.c
*/

#include "game.h"

void set_position_ghost_tower(object_t *object, int x, int y)
{
    sfFloatRect rect;

    rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfSprite_setPosition(object->entity->sprite,
    (sfVector2f) {x, y});
    sfSprite_setOrigin(object->entity->sprite, (sfVector2f)
    {rect.width / 2, rect.height / 2});
}

int print_ghost_tower(object_t *object, engine_t *engine)
{
    list_t *tower = get_addon("Tower", 0, object);
    object_t *slot_tower = get_addon("SlotTower", 6, object);
    object_t *tower_object = NULL;
    node_t *node = NULL;
    int *position_x = get_addon("PositionX", 3, slot_tower);
    int *position_y = get_addon("PositionY", 3, slot_tower);

    if (slot_tower == NULL || position_x == NULL || position_y == NULL)
        return 0;
    node = tower->head;
    for (int i = 0; i < tower->nb_elements; i++) {
        tower_object = node->value;
        set_position_ghost_tower(tower_object, *position_x, *position_y);
        print_entity(tower_object, engine);
        node = node->next;
    }
    return 0;
}

int disable_ghost_tower(object_t *object, engine_t *engine)
{
    list_t *tower = get_addon("Tower", 0, object);
    object_t *tower_object = NULL;
    node_t *node = NULL;

    if (tower == NULL)
        return 0;
    node = tower->head;
    for (int i = 0; i < tower->nb_elements; i++) {
        tower_object = node->value;
        set_active(sfFalse, tower_object, engine);
        node = node->next;
    }
    return 0;
}

int tick_builder_selector(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfFalse) {
        set_active(sfFalse, object, engine);
        search_from_key(object->addons_data, "SlotTower")->value = NULL;
        disable_ghost_tower(object, engine);
        return 0;
    }
    print_ghost_tower(object, engine);
    return 0;
}