/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** random
*/

#include <stdio.h>

int randomize_helper(FILE *in)
{
    unsigned int seed = 0;

    if (!in)
        return 84;
    if (fread(&seed, sizeof seed, 1, in) == 1) {
        fclose(in);
        srand(seed);
        return 0;
    }
    fclose(in);
    return 84;
}

int randomize(void)
{
    if (!randomize_helper(fopen("/dev/urandom", "r")))
        return 0;
    if (!randomize_helper(fopen("/dev/arandom", "r")))
        return 0;
    if (!randomize_helper(fopen("/dev/random", "r")))
        return 0;
    return 84;
}
