/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"
#include "my.h"

int init_node_for_scene(char const *name, scene_t *scene, engine_t *engine)
{
    node_t *node = malloc(sizeof(node_t));
    char *text = my_strdup(name);

    if (node == NULL || text == NULL)
        return ERROR;
    node->key = text;
    node->value = scene;
    push_element(engine->scenes, node);
    return 0;
}

scene_t *init_scene(char const *name, sfBool const_scene, engine_t *engine)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return NULL;
    scene->canvas = create_empty_list();
    scene->objects = create_empty_list();
    if (const_scene == sfTrue) {
        engine->const_scene = scene;
        return scene;
    }
    if (init_node_for_scene(name, scene, engine) != 0)
        return NULL;
    return scene;
}