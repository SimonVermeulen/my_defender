/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** load.c
*/

#include "game.h"

const int WIDTH = 50;
const int HEIGHT = 10;

int init_tower_build_loader(object_t *object, engine_t *engine)
{
    object_t *tower = object->parent;
    object_t *sprite = seek_object_scene(object->actual_scene, "SpriteTower");
    node_t *node_path = search_from_key(tower->addons_data, "BuildPath");
    char **path = NULL;
    int *type = get_addon("type", 3, tower);

    if (!tower || !sprite || !node_path || node_path->type != 40 ||
        node_path->len != 4 || !type) {
        return exit_game(engine, 84);
    }
    path = node_path->value;
    if (change_texture(sprite, path[*type]) == 84)
        return exit_game(engine, 84);
    return 0;
}

int enable_load_build(object_t *object, engine_t *engine)
{
    sfTexture *load = sfTexture_create(WIDTH, HEIGHT);
    sfColor *pixels = malloc(sizeof(sfColor) * WIDTH * HEIGHT);

    if (!object->entity || !load || !pixels)
        return exit_game(engine, 82);
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            pixels[y * WIDTH + x] = sfBlack;
    sfTexture_destroy(object->entity->texture);
    object->entity->texture = load;
    sfSprite_setTexture(object->entity->sprite, load, sfTrue);
    sfTexture_updateFromPixels(object->entity->texture,
        (sfUint8 *) pixels, WIDTH, HEIGHT, 0, 0);
    sfClock_restart(object->clock);
    init_tower_build_loader(object, engine);
    free(pixels);
    return 0;
}

int get_load_finish(object_t *object, engine_t *engine, int time)
{
    int *stats = get_addon("stats", 3, object->parent);
    object_t *level = seek_object_scene(object->actual_scene, "TowerLevel");

    if (!object->parent || !stats || !level)
        return exit_game(engine, 83);
    if (time >= 2000000) {
        set_active(sfFalse, object, engine);
        *stats = 2;
        set_active(sfTrue, level, engine);
    }
    return 0;
}

int tick_load_build(object_t *object, engine_t *engine)
{
    int time = sfClock_getElapsedTime(object->clock).microseconds;
    int width = (time * WIDTH) / 2000000;
    sfColor *pixels = malloc(sizeof(sfColor) * width * HEIGHT);

    if (!pixels || !object->entity->texture)
        return exit_game(engine, 85);
    for (int x = 0; x < width; x++)
        for (int y = 0; y < HEIGHT; y++)
            pixels[y * width + x] = sfRed;
    sfTexture_updateFromPixels(object->entity->texture,
        (sfUint8 *) pixels, width, HEIGHT, 0, 0);
    free(pixels);
    return get_load_finish(object, engine, time);
}

int init_load_build_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_load_build;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_load_build;
    if (create_addon("load_build", addon, engine) == sfFalse)
        return 84;
    return 0;
}