/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_fonts
*/

#include "game.h"

const char fonts_path[][256] = {"\0"};
const char fonts_name[][256] = {"\0"};

//le faire avec un chargement json c'est mieux 🦸 🤰
int load_fonts(engine_t *engine)
{
    for (int i = 0; fonts_name[i][0] != 0; i++) {
        if (add_font(fonts_path[i], fonts_name[i], engine) == sfFalse)
            return 84;
    }
    return 0;
}