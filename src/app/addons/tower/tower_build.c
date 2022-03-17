/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** tower_build
*/

#include "game.h"

int init_tower_build_loader(object_t *object, engine_t *engine)
{
    object_t *sprite = seek_object_scene(object->childs, "SpriteTower");
    node_t *node_path = search_from_key(object->addons_data, "BuildPath");
    char **path = NULL;
    int *type = get_addon("type", 3, object);

    if (!sprite || !node_path || node_path->type != 40 ||
        node_path->len != 4) {
        exit_game(engine, 84);
        return 84;
    }
    path = node_path->value;
    if (change_texture(sprite, path[*type]) == 84)
        exit_game(engine, 84);
    return 0;
}

int tick_tower_build(object_t *object, engine_t *engine)
{
    init_tower_build_loader(object, engine);
}
