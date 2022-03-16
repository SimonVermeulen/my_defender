/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** builder_selector.c
*/

#include "game.h"

int on_click_tower_a(object_t *object, engine_t *engine, sfFloatRect rect,
    sfVector2f mouse);
int tick_builder_selector(object_t *object, engine_t *engine);

int start_builder_selector(object_t *object, engine_t *engine)
{
    list_t *tower = create_empty_list();
    int code = push_element(object->addons_data,
        create_new_node(NULL, 6, 0, "SlotTower"));
    object_t *tower_object = NULL;
    node_t *node = NULL;
    
    code += add_object_by_list(
        launch_parsing("./json/objects/ghost_tower_archer.json"), tower, engine);
    code += add_object_by_list(
        launch_parsing("./json/objects/ghost_tower_mage.json"), tower, engine);
    code += push_element(object->addons_data,
        create_new_node(tower, 0, 0, "Tower"));
    if (code >= 84)
        exit_game(engine, 84);
    return 0;
}

int event_builder_selector(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft) {
            on_click_tower_a(object, engine, rect, mouse);
    }
    return 0;
}

int init_builder_selector_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_builder_selector;
    addon->on_event = event_builder_selector;
    addon->on_tick = tick_builder_selector;
    if (create_addon("builder_selector", addon, engine) == sfFalse)
        return 84;
    return 0;
}