/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** hover_button
*/

#include "game_engine.h"

int start_hover_button(object_t *object, engine_t *engine)
{
    object->music = sfMusic_createFromFile(
        "./assets/sounds/gui/Sound_ButtonCommon.ogg");
    sfMusic_setLoop(object->music, sfFalse);
    if (object->music == NULL)
        return exit_game(engine, 84);
    return 0;
}

int play_music_hover(object_t *object, engine_t *engine, int *is_music)
{
    if (!*is_music) {
        sfMusic_play(object->music);
        *is_music = sfTrue;
    }
}

int hover_button_tick(object_t *object, engine_t *engine)
{
    int *width = get_addon("HoverButton_Width", 3, object);
    int *height = get_addon("HoverButton_Height", 3, object);
    int *is_music = get_addon("IsPlaying", 3, object);
    sfVector2f mouse = get_mouse_position(engine);
    sfVector2f pos = sfSprite_getPosition(object->entity->sprite);
    sfFloatRect rect;
    sfIntRect rect_texture;

    if (width == NULL || height == NULL || !object->music || !is_music)
        return 0;
    rect = (sfFloatRect) {pos.x, pos.y, *width, *height};
    rect_texture = (sfIntRect) {0, 0, *width, *height};
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        play_music_hover(object, engine, is_music);
        rect_texture.left = *width;
    } else {
        *is_music = sfFalse;
        sfMusic_stop(object->music);
    }
    sfSprite_setTextureRect(object->entity->sprite, rect_texture);
}

int init_hover_button_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_hover_button;
    addon->on_event = NULL;
    addon->on_tick = hover_button_tick;
    if (create_addon("hover_button", addon, engine) == sfFalse)
        return 84;
    return 0;
}
