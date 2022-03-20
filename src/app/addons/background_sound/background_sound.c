/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** background_sound.c
*/

#include "game.h"

int start_background_sound(object_t *object, engine_t *engine)
{
    object->music = sfMusic_createFromFile(
        "./assets/sounds/in_game/MusicBattlePreparationsForest.ogg");
    if (!object->music)
        return exit_game(engine, 84);
    sfMusic_setLoop(object->music, sfTrue);
    sfMusic_play(object->music);
    if (object->music == NULL)
        return exit_game(engine, 84);
    return 0;
}

int end_background_sound(object_t *object, engine_t *engine)
{
    if (!object->music)
        return exit_game(engine, 84);
    sfMusic_stop(object->music);
    return 0;
}

int init_background_sound_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_background_sound;
    addon->on_start = start_background_sound;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    if (create_addon("background_sound", addon, engine) == sfFalse)
        return 84;
    return 0;
}
