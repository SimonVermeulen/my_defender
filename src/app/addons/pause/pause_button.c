/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** pause.c
*/

#include "game.h"

int window_pause(list_t *scene, engine_t *engine, object_t *skip, sfBool boole)
{
    object_t *object = NULL;
    node_t *node = NULL;

    if (scene == NULL)
        return 0;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object == skip)
            continue;
        object->is_pause = boole;
        window_pause(object->childs, engine, skip, boole);
    }
    return 0;
}

int event_pause_button(object_t *object, engine_t *engine)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->entity->sprite);
    sfVector2f mouse = get_mouse_position(engine);
    object_t *pause_menu = seek_object_scene(object->childs, "PauseMenu");
    int *width = get_addon("HoverButton_Width", 3, object);
    int *height = get_addon("HoverButton_Height", 3, object);
    static sfBool stats = sfFalse;

    if (!pause_menu || !width || !height)
        return exit_game(engine, 84);
    if ((sfFloatRect_contains(&rect, mouse.x, mouse.y) &&
        engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft) ||
        (engine->event.type == sfEvtKeyReleased &&
        engine->event.key.code == sfKeyEscape)) {
        stats = (stats == sfFalse) ? sfTrue : sfFalse;
        window_pause(engine->actual_scene, engine, object, stats);
        window_pause(engine->const_scene, engine, object, stats);
        set_active(stats, pause_menu, engine);
        sfSprite_setTextureRect(object->entity->sprite, (sfIntRect)
            {*width * 2, 0, *width, *height});
    }
}

int init_pause_button_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_pause_button;
    addon->on_tick = NULL;
    if (create_addon("pause_button", addon, engine) == sfFalse)
        return 84;
    return 0;
}