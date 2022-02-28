/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"
#include "libma.h"

int init_scene(char const *name, sfBool const_scene, engine_t *engine)
{
    node_t *node = NULL;
    scene_t *scene = malloc(sizeof(scene_t));
    char *text = NULL;

    if (scene == NULL)
        return ERROR;
    scene->canvas = create_empty_list();
    scene->objects = create_empty_list();
    if (const_scene == sfTrue) {
        engine->const_scene = scene;
        return 0;
    }
    node = malloc(sizeof(node_t));
    text = my_strdup(name);
    if (node == NULL || text == NULL)
        return ERROR;
    node->key = text;
    node->value = scene;
    return push_element(engine->scenes, node);
}