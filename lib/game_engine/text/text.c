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

sfBool print_text(char const *text, sfVector2f position, engine_t *engine)
{

}

sfBool draw_text(print_text_t *data, engine_t *engine)
{
    if (data->text == NULL || engine == NULL)
        return sfFalse;
    sfText_setFont(engine->text.text, data->font);
    sfText_setPosition(engine->text.text, data->position);
    sfText_setString(engine->text.text, data->text);
    sfRenderWindow_drawText(engine->window, engine->text.text, NULL);
    free(data->text);
    free(data);
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