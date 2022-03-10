/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** object.c
*/

#include <unistd.h>
#include "game_engine.h"
#include "libma.h"

int create_secondary_step_object(object_t *object, node_t *node,
    char *name, list_t *scene)
{
    object->addons_data = NULL;
    object->isActive = sfTrue;
    object->entity = NULL;
    if (object->addons == NULL)
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
    object->addons = create_empty_list();
    if (create_secondary_step_object(object, node , string, scene) == 84)
        return NULL;
    return object;
}

int destroy_object(object_t *object)
{
    if (object == NULL)
        return 84;
    destroy_addons(object->addons);
    destroy_addons(object->addons_data);
    destroy_entity(object);
    return 0;
}

sfBool set_active(sfBool value, object_t *object, engine_t *engine)
{
    node_t *node = NULL;
    addon_t *addon = NULL;

    if (object == NULL || engine == NULL || object->isActive == value)
        return sfFalse;
    object->isActive = value;
    node = object->addons->head;
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