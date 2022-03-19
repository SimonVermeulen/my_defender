/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** mobs_animation.c
*/

#include "game.h"

int tick_mobs_animation(object_t *object, engine_t *engine)
{
    int *width = get_addon("Width", 3, object);
    int *height = get_addon("Height", 3, object);
    int *animation_time = get_addon("AnimationTime", 3, object);
    int *step = get_addon("AnimationStep", 3, object);
    node_t *animation_array = search_from_key(object->addons_data,
        "MovementAnimation");
    int *animation = NULL;
    int time = sfClock_getElapsedTime(object->clock).microseconds;

    if (!width || !height || !animation_array || animation_array->type != 30 ||
        !animation_time)
        return exit_game(engine, 84);
    animation = animation_array->value;
    if (time >= *animation_time) {
        *step = (*step >= (animation_array->len - 1)) ? 0 : *step + 1;
        sfSprite_setTextureRect(object->entity->sprite, (sfIntRect)
            {(animation[*step] * *width), 0, *width, *height});
        sfClock_restart(object->clock);
    }
    return 0;
}

int init_mobs_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_mobs_animation;
    if (create_addon("mobs_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}