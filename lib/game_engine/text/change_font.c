/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** change_font
*/

#include "game_engine.h"

sfBool change_font(char const *name, engine_t *engine)
{
    node_t *node = NULL;

    if (engine == NULL)
        return NULL;
    node = search_from_key(engine->text.fonts, name);
    if (node == NULL)
        return NULL;
    sfText_setFont(engine->text.text, node->value);
    return sfTrue;
}