/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_str_isalpha.c
*/

int check_isalpha(char c);

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_isalpha(str[i]) == 0)
            return 0;
    }
    return 1;
}
