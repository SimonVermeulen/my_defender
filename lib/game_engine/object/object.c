/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** object.c
*/

#include <unistd.h>
#include "game_engine.h"
#include "my.h"

int create_secondary_step_object(object_t *object, node_t *node,
    char *name, list_t *scene)
{
    object->addons_data = NULL;
    object->isActive = sfTrue;
    object->entity = NULL;
    object->parent = NULL;
    object->childs = NULL;
    object->clock = sfClock_create();
    if (object->addons == NULL || object->clock == NULL)
        return 84;
    node->value = object;
    node->key = name;
    return push_element(scene, node);
}

object_t *create_object(char const *name, list_t *scene)
{
    node_t *node = NULL;
    char *string = NULL;
    object_t *object = NULL;

    if (name == NULL || scene == NULL)
        return NULL;
    node = malloc(sizeof(node_t));
    string = my_strdup(name);
    object = malloc(sizeof(object_t));
    if (node == NULL || string == NULL || object == NULL)
        return NULL;
    object->name = string;
    object->actual_scene = scene;
    object->addons = create_empty_list();
    if (create_secondary_step_object(object, node , string, scene) == 84)
        return NULL;
    return object;
}

int destroy_object(object_t *object)
{
    node_t *node = NULL;
    node_t *next = NULL;

    if (object == NULL)
        return 84;
    destroy_addons(object->addons, sfTrue);
    destroy_addons(object->addons_data, sfFalse);
    destroy_entity(object);
    destroy_scene(object->childs);
    node = search_from_key(object->actual_scene, object->name);
    next = object->actual_scene->head;
    for (int i = 0; i < object->actual_scene->nb_elements; i++) {
        if (next == node) {
            splice(object->actual_scene, i);
            return 0;
        }
        next = next->next;
    }
    return 84;
}

object_t **stock_object(object_t *object)
{
    object_t **stock = malloc(sizeof(object_t *));

    if (stock == NULL || object == NULL) {
        free(stock);
        return NULL;
    }
    *stock = object;
    return stock;
}

sfBool set_active(sfBool value, object_t *object, engine_t *engine)
{
    node_t *node = NULL;
    addon_t *addon = NULL;

    if (object == NULL || engine == NULL || object->isActive == value)
        return sfFalse;
    object->isActive = value;
    node = object->addons->head;
    sfClock_restart(object->clock);
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (object->isActive == sfTrue) {
            add_function(addon->on_enable, 0, object, engine);
            continue;
        }
        add_function(addon->on_disable, 0, object, engine);
    }
    return sfTrue;
}