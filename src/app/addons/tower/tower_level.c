/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** tower_level.c
*/

#include "game.h"

int load_sprite_tower(object_t *object, engine_t *engine)
{
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    list_t *info = get_addon("Info", 1, object);
    char *path = get_value_list(info, "Path", 4);

    if (!info || !path || !sprite || change_texture(sprite, path) == 84)
        return exit_game(engine, 84);
    return 0;
}

int enable_tower_level(object_t *object, engine_t *engine)
{
    node_t *node_path = search_from_key(object->addons_data, "JsonTowerPath");
    node_t *info = NULL;
    char **path = NULL;
    int *type = get_addon("type", 3, object->parent);
    list_t *json = NULL;

    if (!node_path || node_path->type != 40 ||
        node_path->len != 4 || !type)
        return exit_game(engine, 84);
    path = node_path->value;
    json = launch_parsing(path[*type]);
    if (!json)
        return exit_game(engine, 84);
    info = create_new_node(json, 1, "Info",
        object->addons_data);
    if (!info)
        return exit_game(engine, 84);
    return load_sprite_tower(object, engine);
}

int init_tower_level_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_tower_level;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    if (create_addon("tower_level", addon, engine) == sfFalse)
        return 84;
    return 0;
}
