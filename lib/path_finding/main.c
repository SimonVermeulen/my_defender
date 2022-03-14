/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** main.c
*/

#include "path_finding.h"
#include "my.h"

int main(void)
{
    char map[10][10] = {
        {"xxxxxxxxxx"},
        {"xxxxxxxxxx"},
        {"xxxxxxxxxx"},
        {"xxxxOOxxxx"},
        {"xxxxOOxxxx"},
        {"xxxxOOxxxx"},
        {"xxxxOOxxxx"},
        {"xxxxxxxxxx"},
        {"xxxxxxxxxx"},
        {"xxxxxxxxxx"}};
    int start[2] = {0, 0};
    int end[2] = {8, 7}; 
    find_path(map, start, end);
    return (0);
};