/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"

static int cmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    result = s1[i] - s2[i];
    return (result);
}

sfBool change_scene(char const *name, engine_t *engine)
{
    node_t *current = NULL;

    if (engine == NULL)
        return NULL;
    current = engine->scenes->head;
    for (int i = 0; i < engine->scenes->nb_elements; i++) {
        if (cmp(name, current->key)) {
            engine->actual_scene = i;
            return sfTrue;
        }
        current = current->next;
    }
    return sfFalse;
}