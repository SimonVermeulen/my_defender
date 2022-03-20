/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** main.c
*/

#include "game.h"
#include "my.h"

static int help(void)
{
    my_putstr("USAGE\n\n");
    my_putstr("\tmake re then ./my_defender\n\n");
    my_putstr("DESCRIPTION\n\n");
    my_putstr("\tWelcome to our «my_defender» game.\n");
    my_putstr("\tLaunch the game to play.\n\n");
    my_putstr("COMMANDE\n\n");
    my_putstr("\t-Mouse left click on buttons\n");
    my_putstr("\t-Mouse right click to drag the map\n");
    my_putstr("\t-Escape key to pause the game faster\n\n");
    my_putstr("\tGood game.\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return (help());
    return load_game();
}
