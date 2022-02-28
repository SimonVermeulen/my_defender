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

sfBool add_font(char const *font, engine_t *engine)
{
    sfFont *font = sfFont_createFromFile(font);
    node_t *node = create_newnode(0);

    if (engine == NULL || font == NULL)
        return sfFalse;
    node->value = font;
    push_element(engine->text.fonts, node);
    return sfTrue;
}

sfBool draw_text(char const *text, sfVector2f position, engine_t *engine)
{

}

sfBool print_text(char const *text, sfVector2f position, engine_t *engine)
{
    if (text == NULL || engine == NULL)
        return sfFalse;
    sfText_setPosition(engine->text.text, position);
    sfText_setString(engine->text.text, text);
    sfRenderWindow_drawText(engine->window, engine->text.text, NULL);
    return sfTrue;
}

int destroy_text(engine_t *engine)
{
    list_t *fonts = NULL;
    node_t *temp = NULL;
    
    if (engine == NULL)
        return ERROR;
    fonts = engine->text.fonts;
    while (fonts->nb_elements != 0) {
        fonts = fonts->head;
        sfFont_destroy(fonts->head->value);
        shift_element(fonts);       
    }
    sfText_destroy(engine->text.text);
    return 0;
}