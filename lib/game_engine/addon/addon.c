/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** addon.c
*/

#include <stdlib.h>
#include "game_engine.h"
#include "libma.h"

void *get_addon(char const *name, int type, object_t *object)
{
    node_t *node = NULL;

    if (object == NULL)
        return NULL;
    node = search_from_key(object->addons_data, name);
    if (node == NULL || node->type != type)
        return NULL;
    return node->value;
}

sfBool create_addon(char const *name, addon_t *addon, engine_t *engine)
{
    node_t *node = malloc(sizeof(node_t));

    if (addon == NULL || engine == NULL || node == NULL)
        return sfFalse;
    node->value = addon;
    node->key = my_strdup(name);
    return push_element(engine->addons, node);
}

sfBool add_addon(char const *name, object_t *object, engine_t *engine)
{
    node_t *node = NULL;
    node_t *new = NULL;

    if (object == NULL || engine == NULL || name == NULL)
        return sfFalse;
    node = search_from_key(engine->addons, name);
    if (node == NULL)
        return sfFalse;
    new = malloc(sizeof(node_t));
    if (new == NULL)
        return sfFalse;
    new->key = node->key;
    new->value = node->value;
    push_element(object->addons, new);
    return sfTrue;
}

int destroy_addons(list_t *addon, sfBool bool)
{
    node_t *node = NULL;

    if (addon == NULL)
        return ERROR;
    while (addon->nb_elements != 0) {
        if (bool == sfTrue) {
            addon->head->key = NULL;
            addon->head->value = NULL;
        }
        shift_element(addon);
    }
    free(addon);
    return 0;
}