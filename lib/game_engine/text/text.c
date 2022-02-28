/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** text.c
*/

#include "game_engine.h"

int init_text(engine_t *engine)
{
    engine->text.fonts = NULL;
    engine->text.text = sfText_create();
    if (engine->text.text == NULL)
        return ERROR;
    return 0;
}

int add_font(char const *font, engine_t *engine)
{
    sfFont *font = sfFont_createFromFile(font);

    if (engine == NULL || font == NULL)
        return ERROR;
}