/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"
#include "my.h"

int init_primitive_scene(engine_t *engine, init_scene_function_t init,
    const char *name)
{
    node_t *node = NULL;
    primitive_scene_t *primitive = NULL;

    if (engine == NULL)
        return 84;
    primitive = malloc(sizeof(primitive_scene_t));
    if (primitive == NULL)
        return 84;
    primitive->init = init;
    node = create_new_node(primitive, 0, name, engine->scenes);
    if (node == NULL)
        return 84;
    return 0;
}