/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** time.c
*/

#include "game_engine.h"

float get_delta(engine_t *engine)
{
    return sfClock_getElapsedTime(engine->time.delta).microseconds;
}