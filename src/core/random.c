/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** random
*/

#include <stdlib.h>
#include <stdio.h>

int set_random(FILE *file)
{
    unsigned int seed = 0;

    if (!file)
        return 84;
    if (fread(&seed, sizeof seed, 1, file) == 1) {
        fclose(file);
        srand(seed);
        return 0;
    }
    fclose(file);
    return 84;
}

int get_random(void)
{
    if (!set_random(fopen("/dev/urandom", "r")))
        return 0;
    if (!set_random(fopen("/dev/arandom", "r")))
        return 0;
    if (!set_random(fopen("/dev/random", "r")))
        return 0;
    return 84;
}
