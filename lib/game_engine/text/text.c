/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** text.c
*/

#include "game_engine.h"
#include "my.h"

sfBool add_font(char const *font_name, char const *name, engine_t *engine)
{
    sfFont *font = sfFont_createFromFile(font_name);
    node_t *node = malloc(sizeof(node_t));

    if (engine == NULL || font == NULL || name == NULL || node == NULL)
        return sfFalse;
    node->value = font;
    node->key = my_strdup(name);
    node->len = 0;
    push_element(engine->fonts, node);
    return sfTrue;
}

int destroy_fonts(engine_t *engine)
{
    list_t *fonts = NULL;
    node_t *temp = NULL;
    
    if (engine == NULL || engine->fonts == NULL)
        return ERROR;
    fonts = engine->fonts;
    while (fonts->nb_elements != 0) {
        temp = fonts->head;
        sfFont_destroy(temp->value);
        temp->value = NULL;
        shift_element(fonts);       
    }
    free(engine->fonts);
    return 0;
}

sfFont *get_font(char const *name, engine_t *engine)
{
    node_t *node = NULL;

    if (engine == NULL)
        return NULL;
    node = search_from_key(engine->fonts, name);
    if (node == NULL)
        return NULL;
    return node->value;
}
