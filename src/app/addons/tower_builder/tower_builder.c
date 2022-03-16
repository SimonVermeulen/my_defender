/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower_builder.c
*/

#include "game.h"

int event_tower_builder_addons(object_t *object, engine_t *engine)
{
    int *position_x = get_addon("PositionX", 3, object);
    int *position_y = get_addon("PositionY", 3, object);
    object_t *selector = seach_object(engine, "BuildSelector");
    sfFloatRect rect;
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    if (position_x == NULL || position_y == NULL) {
        exit_game(engine, 84);
        return 0;
    }
    rect = (sfFloatRect) {(*position_x - 50), (*position_y - 50), 100, 100};
    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft && 
        sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        search_from_key(selector->addons_data, "SlotTower")->value = object;
        set_active(sfTrue, selector, engine);
        sfSprite_setPosition(selector->entity->sprite, (sfVector2f)
            {*position_x, *position_y});
    }
}

int create_build_tower(int type, engine_t *engine, sfVector2f position,
    list_t *scene)
{
    list_t *build_tower = launch_parsing("./json/objects/build_tower.json");
    object_t *build_tower_object = NULL;
    int *type_build = NULL;

    if (build_tower == NULL ||
        add_object_by_list(build_tower, scene, engine) == 84) {
        exit_game(engine, 84);
        return 0;
    }
    build_tower_object = scene->head->prev->value;
    sfSprite_setPosition(build_tower_object->entity->sprite, position);
    type_build = get_addon("type", 3, build_tower_object);
    *type_build = type;
    return 0;
}

int on_disable_tower_builder(object_t *object, engine_t *engine)
{
    object_t *valid = seach_object(engine, "ValidBuild");
    int *type = get_addon("type", 3, valid);
    int *position_x = get_addon("PositionX", 3, object);
    int *position_y = get_addon("PositionY", 3, object);

    switch (*type) {
        case 0:
            create_build_tower(*type, engine, (sfVector2f) {*position_x,
                *position_y}, object->actual_scene);
            break;
    }
}

int position_cursor(object_t *object, engine_t *engine)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);

    //printf("%f, %f\n", mouse.x, mouse.y);
}

int init_tower_builder_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = on_disable_tower_builder;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_tower_builder_addons;
    addon->on_tick = position_cursor;
    if (create_addon("tower_builder", addon, engine) == sfFalse)
        return 84;
    return 0;
}