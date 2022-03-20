/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** print_type.c
*/

#include "game_engine.h"

void print_type(print_node_t *node, sfRenderWindow *win)
{
    switch (node->type) {
        case 0:
            sfRenderWindow_drawSprite(win, node->data, NULL);
            break;
        case 1:
            sfRenderWindow_drawText(win, node->data, NULL);
            break;
    }
}
