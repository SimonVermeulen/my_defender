/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** valid_build.c
*/

#include "game.h"

int event_valid_build(object_t *object, engine_t *engine)
{
    object_t *selector = seach_object(engine, "BuildSelector");
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (selector == NULL ||
        sfClock_getElapsedTime(object->entity->clock).microseconds < 10000)
        return 0;
    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        set_active(sfFalse, selector, engine);
        set_active(sfFalse, object, engine);
        set_active(sfFalse, get_addon("SlotTower", 0, selector), engine);
    }
}

int tick_valid_build(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfFalse) {
        set_active(sfFalse, object, engine);
        return 0;
    }
    return 0;
}

int on_start_valid_build(object_t *object, engine_t *engine)
{
    int *type = malloc(sizeof(int));
    
    object->addons_data = create_empty_list();
    if (type == NULL || object->addons_data == NULL) {
        exit_game(engine, 84);
        return 0;
    }
    *type = 0;
    if (push_element(object->addons_data,
        create_new_node(type, 3, 0, "type")) == 84)
        exit_game(engine, 84);
    if (get_addon("type", 3, object) == type)
        printf("bon");
    return 0;
}

int init_valid_build_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = on_start_valid_build;
    addon->on_event = event_valid_build;
    addon->on_tick = tick_valid_build;
    if (create_addon("valid_build", addon, engine) == sfFalse)
        return 84;
    return 0;
}