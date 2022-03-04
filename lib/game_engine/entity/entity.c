/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** entity.c
*/

#include "game_engine.h"

int init_entity(int order, char const *texture, object_t *object)
{
    sfSprite *sprite = NULL;
    sfTexture *texture = NULL;
    sfClock *clock = NULL;
    entity_t *entity = NULL;

    if (texture == NULL || object == NULL)
        return 84;
    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(texture, NULL);
    clock = sfClock_create();
    if (sprite == NULL || texture == NULL || clock == NULL)
        return 84;
    sfSprite_setTexture(sprite, texture, sfTrue);
    entity = malloc(sizeof(entity_t));
    if (entity == NULL)
        return 84;
    entity->order = order;
    entity->clock = clock;
    entity->sprite = sprite;
    entity->texture = texture;
}

int print_entity(object_t *object, engine_t *engine)
{
    if (object == NULL || object->isActive == sfFalse)
        return 84;
    return add_print(NULL, object->entity, object->entity->order, engine);
}

int destroy_entity(object_t *object)
{
    if (object == NULL)
        return 84;
    sfSprite_destroy(object->entity->sprite);
    sfTexture_destroy(object->entity->texture);
    sfClock_destroy(object->entity->clock);
    free(object->entity);
    return 0;
}